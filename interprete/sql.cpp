#include "sql.h"
#include "sql.tab.hpp"
#include <stack>

std::stack<std::vector<str_registro>> std_stack;

Inst prog[NPROG];   /* La maquina */
Inst *progp;        /* Siguiente celda libre en generacion de codigo */
Inst *pc;           /* Contador de programa durante */
Inst *progbase = prog;
int wheresql(Inst *);

static Symbol *symlist=0;    /* tabla de simbolos: lista ligada */
static struct {
    char *name;
    int kval;
} keywords[] = {
    {"auto_increment",   AUTO_INCREMENT},
    {"create",           CREATE},
    {"database",         DATABASE},
    {"index",            INDEX},
    {"insert",           INSERT},
    {"into",             INTO},
    {"values",           VALUES},
    {"primary",          PRIMARY},
    {"key",              KEY},
    {"null",             NULLX},
    {"schema",           SCHEMA},
    {"table",            TABLE},
    {"varchar",          VARCHAR},
    {"int",              INTEGER},
    {"asc",              ASC},
    {"order",            ORDER},
    {"by",               BY},
    {"desc",             DESC},
    {"select",           SELECT},
    {"from",             FROM},
    {"where",            WHERE},
    {"delete",           DELETE},
    {"update",           UPDATE},
    {"set",              SET},
    {"and",              ANDOP},
    {"or",               OR},
    {0,                  0}
};

int init(){
    int i;
    for(i = 0; keywords[i].name; i++)
        install(keywords[i].name, keywords[i].kval, NULL);
    return 0;
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
    return 0;
}
int colpush(){
    Datum d;
    d.col = (Columnval *)(*pc++);
    push(d);
    return 0;
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
    return 0;
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
    // printf("Creando tabla %s\n", d1.str);
    Tabla miTabla(d1.str);
    // printf("Parametros:\n");
    Column *list;
    list = (Column *)*pc++;
    Column *itera;
    for(itera = list; itera!=0; itera = itera->next){
        // printf("%s ", itera->val->nombre);
        switch(itera->val->type){
            case VARCHAR:
                // printf("varchar (%d)\n", itera->val->len);
                miTabla.addColumna(itera->val->nombre,itera->val->len);
                break;
            case INTNUM:
                printf("int\n");
            break;
        }
    }
    return 0;
}
int insert(){
    Datum d1;
    d1 = pop();
    // printf("Insertando en tabla %s\n", d1.str);
    // printf("Valores:\n");
    Tabla miTabla;
    if(!miTabla.leerTabla(d1.str))
    {
        std::cout << "No existe la tabla " << d1.str << std::endl;
        return 0;
    }
    str_registro r1;
    Column *campos, *valores;
    campos = (Column *)*pc++;
    valores = (Column *)*pc++;
    Column *c, *v;
    for(c = campos, v = valores ; c!=0 && v!=0; c = c->next, v = v->next){
        switch(v->val->type){
            case STRING:
                // printf("%s = '%s'\n", c->val->nombre, v->val->val->str);
                r1.atributo_valor.insert(std::pair<std::string,std::string>(c->val->nombre,v->val->val->str));
                break;
            case INTNUM:
                printf("%s = %d\n", c->val->nombre, v->val->val->intval);
                break;
        }
    }
    miTabla.insertarRegistro(r1);
    return 0;
}
int selectsql(){
    Datum d1;
    d1 = pop();
    // printf("Consultando tabla %s\n", d1.str);
    // printf("Campos:\n");
    std::vector<std::string> attrib;
    Tabla miTabla;
    if(!miTabla.leerTabla(d1.str))
    {
        std::cout << "No existe la tabla : " << d1.str << std::endl;
        return 0;
    }
    std_stack.push(miTabla.leerRegistros());
    Column *campos;
    Datum *where;
    campos = (Column *)*pc++;
    where = (Datum *)*pc++;
    Column *c;
    
    if(where != 0){
         // Incluye where
        printf("Where\n");
        Inst *codigoWhere = pc;
        //for cada registro{
            pc = codigoWhere;
            if(wheresql(codigoWhere)){
                printf("Registro cumple con where\n");
            }else{
                printf("Registro NO cumple con where\n");
            }
        //} end for
        pc++;
    }
    
    if(campos == 0){
        // printf("* (Todos)\n");
        for(auto &x : miTabla.getColumnas())    //Imprime los atributos
            std::cout << x << " | ";

        std::cout << std::endl;
        std::vector<str_registro> registros = std_stack.top();
        std_stack.pop();

        for(auto&x : registros)
        {
            for(auto &y : miTabla.getColumnas())
               std::cout << x.atributo_valor.at(y) << " | ";    //Imprime los valores de cada registro
            std::cout << std::endl;
        }

    }else{
        for(c = campos; c!=0; c = c->next){
            // printf("%s\n", c->val->nombre);
            attrib.push_back(c->val->nombre);   
        }
    }
    
    return 0;
}
int deletesql(){
    Datum d1;
    d1 = pop();
    printf("Eliminando de tabla %s\n", d1.str);
    Datum *where;
    where = (Datum *)*pc++;
    if(where == 0){return 0;} // Sin where, eliminar todo
    else{ // Incluye where
        printf("Where\n");
        Inst *codigoWhere = pc;
        //for cada registro{
            pc = codigoWhere;
            if(wheresql(codigoWhere)){
                printf("Registro cumple con where\n");
            }else{
                printf("Registro NO cumple con where\n");
            }
        //} end for
        pc++;
    }
    return 0;
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
    Datum *where;
    where = (Datum *)*pc++;
    if(where == 0){return 0;} // Sin where, actualizar todo
    else{ // Incluye where
        printf("Where\n");
        Inst *codigoWhere = pc;
        //for cada registro{
            pc = codigoWhere;
            if(wheresql(codigoWhere)){
                printf("Registro cumple con where\n");
            }else{
                printf("Registro NO cumple con where\n");
            }
        //} end for
        pc++;
    }
    return 0;
}
int wheresql(Inst *codigoWhere){
    Datum d1;
    pc = codigoWhere;
    while(*pc != STOP){ // Ejecucion de codigo de where
        if(*pc == log_and || *pc == log_or){    //Ejecucion de and u or
            execute(pc); 
            pc++;
            continue;
        }
        execute(pc); //Insertar operandos en la pila
        pc++;
        d1 = pop();
        printf("Atributo a comparar %s\n", d1.col->nombre);
        // printf("Valor atributo %s\n", d1.col->val->str);
        /* Actualizar atributo con valor del registro actual */
        /*Si el atributo es string*/
        //d1.col->val->str = "jorge"; //Valor de prueba
        /*Si el atributo es entero*/
        // d1.col->val->intval = 10;
        push(d1);
        execute(pc);    //Ejecutar comparacion
        pc++;
    }
    d1 = pop();
    return d1.intval;
}
int eq(){ /* d1 = d2 */
    Datum d1, d2, d3;
    d2 = pop();
    d1 = pop();
    std::vector<str_registro> r1 = std_stack.top();
    std::vector<str_registro> r2;
    std_stack.pop();
    int tipo = d1.col->type + d2.col->type;
    switch(tipo){
        case STRING: /* Comparando strings */
            //d3.intval = strcmp(d1.col->val->str, d2.col->val->str) == 0 ? 1 : 0;
            for(auto &x : r1)
            {
                if(x.atributo_valor.at(d2.col->val->str) == d1.col->val->str)
                {
                    std::cout << "Nombre columna: " << d2.col->val->str << std::endl
                              << "Valor real: " <<x.atributo_valor.at(d2.col->val->str) << std:: endl
                              << "valor deseado: "<< d1.col->val->str << std::endl;
                    r2.push_back(x);
                }
            }
            std_stack.push(r2);
            break;
        case INTNUM: /* Comparando enteros */
            d3.intval = d1.col->val->intval == d2.col->val->intval;
            break;
    }
    push(d3); //guardar resultado en la pila
    return 0;
}
int gt(){
    Datum d1, d2, d3;
    d2 = pop();
    d1 = pop();
    printf("%d > %d\n", d1.col->val->intval, d2.col->val->intval);
    d3.intval = d1.col->val->intval > d2.col->val->intval;
    push(d3);
    return 0;
}
int ge(){
    Datum d1, d2, d3;
    d2 = pop();
    d1 = pop();
    printf("%d >= %d\n", d1.col->val->intval, d2.col->val->intval);
    d3.intval = d1.col->val->intval >= d2.col->val->intval;
    push(d3);
    return 0;
}
int lt(){
    Datum d1, d2, d3;
    d2 = pop();
    d1 = pop();
    printf("%d < %d\n", d1.col->val->intval, d2.col->val->intval);
    d3.intval = d1.col->val->intval < d2.col->val->intval;
    push(d3);
    return 0;
}
int le(){
    Datum d1, d2, d3;
    d2 = pop();
    d1 = pop();
    printf("%d <= %d\n", d1.col->val->intval, d2.col->val->intval);
    d3.intval = d1.col->val->intval <= d2.col->val->intval;
    push(d3);
    return 0;
}
int ne(){
    Datum d1, d2, d3;
    d2 = pop();
    d1 = pop();
    printf("%d != %d\n", d1.col->val->intval, d2.col->val->intval);
    d3.intval = d1.col->val->intval != d2.col->val->intval;
    push(d3);
    return 0;
}
int log_and(){
    Datum d1, d2, d3;
    d2 = pop();
    d1 = pop();
    d3.intval = d1.intval && d2.intval;
    push(d3);
    return 0;
}
int log_or(){
    Datum d1, d2, d3;
    d2 = pop();
    d1 = pop();
    d3.intval = d1.intval || d2.intval;
    push(d3);
    return 0;
}
