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
}

%token <strval> NAME
%token <intval> INTNUM
%token <intval> BOOL
%token <floatval> APPROXNUM
%token <sym> AUTO_INCREMENT CREATE DATABASE INDEX INSERT INTO VALUES PRIMARY KEY NULLX SCHEMA TABLE VARCHAR INDEF

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
stmt_list:    stmt ';'
            | stmt_list stmt ';'
            ;

expr:         NAME 
            | NAME '.' NAME
            | USERVAR
            | '"' NAME '"'  {printf("%s\n", $2);}/*String*/
            | INTNUM
            | APPROXNUM
            | BOOL
            ;

expr:       | expr '+' expr
            | expr '-' expr
            | expr '*' expr
            | expr '/' expr
            | expr '%' expr
            | expr MOD expr
            | '-' expr %prec UMINUS
            | expr ANDOP expr
            | expr OR expr
            | expr XOR expr
            | expr '|' expr
            | expr '&' expr
            | expr '^' expr
            | NOT expr
            | '!' expr
            ;
/* Create database */
stmt:         create_database_stmt {;}
            ;

create_database_stmt: CREATE DATABASE NAME {printf("Creando bd: %s\n", $3);}
            |         CREATE SCHEMA NAME {;}
            ;

/* Create table */
stmt:         create_table_stmt {;}
            ;

create_table_stmt:  CREATE TABLE NAME {printf("Creando tabla %s\n", $3);} '(' create_col_list ')'
                 ;
            
create_table_stmt:  CREATE TABLE NAME '.' NAME '(' create_col_list ')' {;}
            ;
/* Lista de columnas */
create_col_list:    create_definition {;}
            |       create_col_list ',' create_definition {;}
            ;

create_definition:  PRIMARY KEY '(' column_list ')' {;}
            |       KEY '(' column_list ')' {;}
            |       INDEX '(' column_list ')' {;}
            ;

column_list: NAME {;}
            | column_list ',' NAME {;}
            ;

create_definition:  NAME {printf("Creando columna %s, ", $1);} data_type column_atts {;}
            ;
column_atts:    /* Vacion */ {}
            | column_atts NOT NULLX {;}
            | column_atts NULLX     {;}
            | column_atts AUTO_INCREMENT {;}
            | column_atts PRIMARY KEY
            ;
data_type:  VARCHAR '(' INTNUM ')' {printf("Tam %d\n", $3);}

/* Insertar */
stmt:         insert_stmt {;}
            ;

insert_stmt:  INSERT INTO NAME {printf("Insertando en %s\n", $3);}opt_col_names VALUES insert_vals_list
            ;

opt_col_names: /* Vacio */
            | '(' column_list ')' {;}
            ;
insert_vals_list: '(' insert_vals ')' {;}
            | insert_vals_list ',' '(' insert_vals ')' {;}
insert_vals: expr {;}
            | insert_vals ',' expr {;}
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
    initcode();
    yyparse();
  	//for(initcode(); yyparse (); initcode())
    //    execute(progbase);
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
      		scanf ("%d", &(yylval.intval));
	      return INTNUM;
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
            char *temp = (char *)malloc(strlen(sbuf));
            memcpy(temp, sbuf, strlen(sbuf));
		    yylval.strval = temp; 
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
