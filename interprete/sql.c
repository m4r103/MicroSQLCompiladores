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
int createDatabase(){
    Datum d1;
    d1 = pop();
    printf("Creando base de datos %s\n", d1.str);
}
Column *columnlist(Columnval *columna, Column *list){
    Column *col;
    col = (Column *)malloc(sizeof(Column));
    col->val = columna;
    col->next = list;
    return col;
}
Columnval *createColumn(char *nombre, short type, int len){
    Columnval *columna;
    columna = (Columnval *)malloc(sizeof(Columnval));
    columna->nombre = nombre;
    columna->type   = type;
    columna->len    = len;
    return columna;
}
int createTable(){
    Datum d1;
    d1 = pop();
    printf("Creando tabla %s\n", d1.str);
    
    printf("Parametros:\n");
    Column *list;
    list = (Column *)*pc++;
    Column *itera;
    for(itera = list; itera!=0; itera = itera->next){
        printf("%s --- %d\n", itera->val->nombre, itera->val->len);
    }
    
}
int insert(){
    Datum d1;
    d1 = pop();
    printf("Insertando en tabla %s\n", d1.str);
    printf("Valores:\n");
    Column *campos, *valores;
    campos = (Column *)*pc++;
    valores = (Column *)*pc++;
    Column *c, *v;
    for(c = campos, v = valores ; c!=0 && v!=0; c = c->next, v = v->next){
        printf("%s --- %s\n", c->val->nombre, v->val->nombre);
    }
}
