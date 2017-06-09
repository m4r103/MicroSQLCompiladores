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
    "schema",           SCHEMA,
    "table",            TABLE,
    "varchar",          VARCHAR,
    "int",              INTEGER,
    "asc",              ASC,
    "order",            ORDER,
    "by",               BY,
    "desc",             DESC,
    "select",           SELECT,
    "from",             FROM,
    "where",            WHERE,
    "delete",           DELETE,
    "update",           UPDATE,
    "set",              SET,
    "and",              ANDOP,
    "or",               OR,
    0,                  0,
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
int colpush(){
    Datum d;
    d.col = (Columnval *)(*pc++);
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
Columnval *createColumn(char *nombre, short type, int len, Datum *val){
    Columnval *columna;
    columna = (Columnval *)malloc(sizeof(Columnval));
    columna->nombre = nombre;
    columna->type   = type;
    columna->len    = len;
    columna->val    = val;
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
        printf("%s ", itera->val->nombre);
        switch(itera->val->type){
            case VARCHAR:
                printf("varchar (%d)\n", itera->val->len);
                break;
            case INTNUM:
                printf("int\n");
            break;
        }
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
        switch(v->val->type){
            case STRING:
                printf("%s = '%s'\n", c->val->nombre, v->val->val->str);
                break;
            case INTNUM:
                printf("%s = %d\n", c->val->nombre, v->val->val->intval);
                break;
        }
    }
}
int selectsql(){
    Datum d1;
    d1 = pop();
    printf("Consultando tabla %s\n", d1.str);
    printf("Campos:\n");
    Column *campos;
    Datum *where;
    campos = (Column *)*pc++;
    where = (Datum *)*pc++;
    Column *c;
    if(campos == 0){
        printf("* (Todos)\n");
    }else{
        for(c = campos; c!=0; c = c->next){
            printf("%s\n", c->val->nombre);
        }
    }
    if(where == 0){return 0;} // Sin where
    else{ // Incluye where
        Inst *codigoWhere = pc;
        //for cada registro{
            pc = codigoWhere;
            while(*pc != STOP){ //Ejecucion de comparaciones y and, or
                //d1 = pop();
                //printf("Atributo a comparar %s\n", d1.col->nombre);
                /*Si el atributo es string
                d1.col->val->str = "string del atributo";
                Si el atributo es entero
                d1.col->val->intval = 10;
                push(d1);
                */
                execute(pc);
                pc++;
            }
            //d1 = pop();
            /*if(d1.intval){
                registro cumple con where
            }else{
                registro no cumple con where
            }
            */
        //} end for
    }
}
int deletesql(){
    Datum d1;
    d1 = pop();
    printf("Eliminando de tabla %s\n", d1.str);
}
int updatesql(){
    Datum d1;
    d1 = pop();
    printf("Actualizando tabla %s\n", d1.str);
    printf("Campos:\n");
    Column *campos;
    campos = (Column *)*pc++;
    Column *c;
    for(c = campos; c!=0; c = c->next){
        switch(c->val->type){
            case STRING:
                printf("%s = '%s'\n", c->val->nombre, c->val->val->str);
                break;
            case INTNUM:
                printf("%s = %d\n", c->val->nombre, c->val->val->intval);
                break;
        }
    }
}
int eq(){ /* d1 = d2 */
    Datum d1, d2, d3;
    d2 = pop();
    d1 = pop();
    int tipo = d1.col->type + d2.col->type;
    char *temp = "prueba";
    printf("Comparando (a == b)\n");
    switch(tipo){
        case STRING: /* Comparando strings */
            d3.intval = strcmp(d1.col->val->str, d2.col->val->str);
            break;
        case INTNUM: /* Comparando enteros */
            d3.intval = d1.col->val->intval == d2.col->val->intval;
            break;
    }
    printf("Resultado == : %d\n", d3.intval);
    //push(d3); //guardar resultado en la pila
}
int gt(){
}
int ge(){
}
int lt(){
}
int le(){
}
int ne(){
}
int and(){
}
int or(){
}
