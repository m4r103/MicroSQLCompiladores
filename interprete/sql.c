#include "sql.h"
#include  "y.tab.h"

Inst *progbase = prog;

static Symbol *symlist=0;    /* tabla de simbolos: lista ligada */
static struct {
    char *name;
    int kval;
} keywords[] = {
    "auto_increment",   AUTO_INCREMENT,
    "create",           CREATE,
    "database",         DATABASE,
    "index",            INDEX,
    "insert",           INSERT,
    "into",             INTO,
    "values",           VALUES,
    "primary",          PRIMARY,
    "key",              KEY,
    "null",             NULLX,
    "schema",            SCHEMA,
    "table",            TABLE,
    "varchar",          VARCHAR,
    "not",NOT,
    0,      0,
};

int init(){
    int i;
    Symbol *s;
    for(i = 0; keywords[i].name; i++)
        install(keywords[i].name, keywords[i].kval, NULL);
}

Symbol *lookup(char *s)    /* encontrar s en la tabla de símbolos */
{
Symbol  *sp;
	for (sp = symlist; sp != (Symbol *)0; sp = sp->next) 
		if (strcmp(sp->name, s)== 0) 
			return sp;
	return 0;      /* 0 ==> no se encontró */ 
}

Symbol *install(char *s,int t, char *d) /* instalar s en la tabla de símbolos */
{
	Symbol *sp;
	sp = (Symbol *)malloc(sizeof(Symbol));
	sp->name = (char *)malloc(strlen(s)+ 1) ; /* +1 para '\0' */
	strcpy(sp->name, s);
	sp->type = t;
	sp->u.str = d;
	sp->next  =  symlist;   /*  poner al frente de la lista   */
	symlist =  sp; 
        return sp; 
}

void initcode(){
    stackp = stack;
    progp = progbase;
    returning = 0;
    indef = 0;
}

void push(Datum dato){
    if(stackp >= &stack[NSTACK])
        execerror("Stack overflow", (char *)0);
    *stackp++ = dato;
}

Datum pop(){
    if(stackp <= stack)
        execerror("Stack underflow", (char *)0);
    return *--stackp;
}

int constpush(){
    Datum *d;
    d = (Datum *)*pc++;
    push(*d);
}
int varpush(){
    Datum d;
    d.sym = (Symbol *)(*pc++);
    push(d);
}

Inst *code(Inst f){
    Inst *oprogp = progp;
    if(progp >= &progp[NPROG])
        execerror("Program too big", (char *)0);
    *progp++ = f;
    return oprogp;
}
void execute(Inst *p){
    for(pc = p; *pc !=STOP; ){
        (*(*pc++))();
    }
}
