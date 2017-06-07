%{
#include <stdio.h>
#include "sql.h"
%}

%union{
    int intval;
    double floatval;
    char *strval;
    int subtok;
    Symbol *sym;
    Inst *inst;
    Datum *const_val;
    Column *columnlist;
    Columnval *columnval;
}

%token <const_val> NAME
%token <const_val> STRING
%token <const_val> INTNUM
%token <const_val> BOOL
%token <floatval> APPROXNUM
%token <sym> AUTO_INCREMENT CREATE DATABASE INDEX INSERT INTO VALUES PRIMARY KEY NULLX SCHEMA TABLE VARCHAR INDEF ASC ORDER BY DESC SELECT FROM WHERE

%type <columnlist> create_col_list 
%type <columnlist> column_list
%type <columnlist> opt_col_names
%type <columnlist> insert_vals
%type <columnlist> insert_vals_list
%type <columnlist> select_expr_list
%type <columnval> create_definition
%type <columnval> data_type
%type <columnval> select_expr
%type <columnval> expr

%token <strval> USERVAR
%left OR
%left XOR
%left ANDOP
%left NOT '!'
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%' MOD
%left '^'
%left nonassoc UMINUS
%start stmt_list
%% 
stmt_list:    
            | stmt ';' {code(STOP); return 1;}
            | stmt_list stmt ';' {code(STOP); return 1;}
            ;

expr:         NAME {$$ = createColumn($1->str, 0, 0);}
            | NAME '.' NAME {;}
            | USERVAR {;}
            | STRING {$$ = createColumn($1->str, 0, 0);} /*String*/
            | INTNUM {;}
            | APPROXNUM {;}
            | BOOL {;}
            ;

expr:         expr '+' expr {;}
            | expr '-' expr {;}
            | expr '*' expr {;}
            | expr '/' expr {;}
            | expr '%' expr {;}
            | expr MOD expr {;}
            | '-' expr %prec UMINUS {;}
            | expr ANDOP expr {;}
            | expr OR expr {;}
            | expr XOR expr {;}
            | expr '|' expr {;}
            | expr '&' expr {;}
            | expr '^' expr {;}
            | NOT expr {;}
            | '!' expr {;}
            ;
/* Create database */
stmt:         create_database_stmt {;}
            ;

create_database_stmt: CREATE DATABASE NAME {code3(constpush, (Inst)$3, createDatabase);}
            |         CREATE SCHEMA NAME {code3(constpush, (Inst)$3, createDatabase);}
            ;

/* Create table */
stmt:         create_table_stmt {;}
            ;

create_table_stmt:  CREATE TABLE NAME '(' create_col_list ')' {code3(constpush, (Inst)$3, createTable); code((Inst)$5);}
            ;
            
create_table_stmt:  CREATE TABLE NAME '.' NAME '(' create_col_list ')' {;}
            ;
/* Lista de columnas */
create_col_list:    create_definition {$$ = columnlist($1, 0);}
            |       create_col_list ',' create_definition {$$ = columnlist($3, $1);}
            ;

create_definition:  PRIMARY KEY '(' column_list ')' {;}
            |       KEY '(' column_list ')' {;}
            |       INDEX '(' column_list ')' {;}
            ;

column_list: NAME {$$ = columnlist(createColumn($1->str, 0, 0), 0);}
            | column_list ',' NAME {$$ = columnlist(createColumn($3->str, 0, 0), $1);}
            ;

create_definition:  NAME data_type column_atts {$2->nombre = $1->str; $$ = $2;}
            ;
column_atts:    /* Vacio */ {}
            | column_atts NOT NULLX {;}
            | column_atts NULLX     {;}
            | column_atts AUTO_INCREMENT {;}
            | column_atts PRIMARY KEY
            ;
data_type:  VARCHAR '(' INTNUM ')' {$$ = createColumn(0, $1->type, $3->intval);}

/* Insertar */
stmt:         insert_stmt {;}
            ;

insert_stmt:  INSERT INTO NAME opt_col_names VALUES insert_vals_list {code3(constpush, (Inst)$3, insert); code2((Inst)$4, (Inst)$6);}
            ;

opt_col_names: /* Vacio */ {;}
            | '(' column_list ')' {$$ = $2;}
            ;
insert_vals_list: '(' insert_vals ')' {$$ = $2;}
            | insert_vals_list ',' '(' insert_vals ')' {;}
            ;
insert_vals:  expr {$$ = columnlist($1, 0);}
            | insert_vals ',' expr {$$ = columnlist($3, $1);}
            ;

/* Select */
stmt: select_stmt {;}
            ;

select_stmt:  SELECT select_expr_list FROM table_references opt_where opt_orderby {code2(selectsql, (Inst)$2);}
            ;

opt_where: /* Vacio */
            | WHERE expr {;}
            ;
opt_orderby: /* Vacio */
            | ORDER BY groupby_list {;}
            ;
groupby_list:   expr opt_asc_desc {;}
            | groupby_list ',' expr opt_asc_desc
            ;
opt_asc_desc: /* Vacio */
            | ASC {;}
            | DESC{;}
            ;
select_expr_list:  select_expr {$$ = columnlist($1, 0);}
            | select_expr_list ',' select_expr {$$ = columnlist($3, $1);}
            | '*' {$$ = 0;}   /* Select * from...  */
            ;
select_expr: expr {$$ = $1;}
            ;
table_references: NAME {code2(constpush, (Inst)$1);}
                | NAME '.' NAME {;}
                ;
%%

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include<setjmp.h>

char *progname;
int lineno = 1;
jmp_buf begin;
int indef;

void main (int argc, char *argv[]){
	progname=argv[0];
    init();
    setjmp(begin);
    signal(SIGFPE, fpecatch);
    //initcode();
    //yyparse();
  	for(initcode(); yyparse (); initcode())
        execute(progbase);
}

void execerror(char *s, char *t){
    warning(s, t);
    longjmp(begin, 0);
}

void fpecatch(){
    execerror("Excepcion de punto flotante", (char *)0);
}

int yylex (){
  	int c;

  	while ((c = getchar ()) == ' ' || c == '\t' || c == '\n')
  		;
 	if (c == EOF)                            
    		return 0;
  	if (isdigit (c)) {
        ungetc (c, stdin);
        yylval.const_val = (Datum *)malloc(sizeof(Datum)); 
        scanf ("%d", &(yylval.const_val->intval));
	    return INTNUM;
    }
    if(c == '\"'){
		char sbuf[200], *p=sbuf;
		while ((c=getchar())!=EOF && c != '\"'){
			*p++=c;
        }
        if(c == EOF) return 0;
        *p = 0;
        yylval.const_val = (Datum *)malloc(sizeof(Datum));
        char *temp = (char *)malloc(strlen(sbuf));
        memcpy(temp, sbuf, strlen(sbuf));
        yylval.const_val->str = temp; 
        return STRING;
    }
	if(isalpha(c)){
		Symbol *s;
		char sbuf[200], *p=sbuf;
		do {
			*p++=c;
		} while ((c=getchar())!=EOF && isalnum(c));
		ungetc(c, stdin);
		*p='\0';
		if((s=lookup(sbuf))==(Symbol *)NULL){
            yylval.const_val = (Datum *)malloc(sizeof(Datum));
            char *temp = (char *)malloc(strlen(sbuf));
            memcpy(temp, sbuf, strlen(sbuf));
		    yylval.const_val->str = temp; 
			return NAME;
        }
		yylval.sym=s;   
 		//printf("func=(%s) tipo=(%d) \n", s->name, s->type);
        return s->type;
	}
    return c;
}
void yyerror (char *s) {
	warning(s, (char *) 0);
}
void warning(char *s, char *t){
	fprintf (stderr, "%s: %s", progname, s);
	if(t)
		fprintf (stderr, " %s", t);
	fprintf (stderr, " cerca de la linea %d\n", lineno);
}
void defnonly(char *s){     /* If illegal definition */
    if(!indef){
        execerror(s, "used outside definition");
    }
}
