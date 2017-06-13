#ifndef __SQL_H__
#define __SQL_H__

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "Tabla.h"

typedef int (*Inst)(void);
typedef struct  Symbol      Symbol;
typedef union   Datum       Datum;
typedef union   Symval      Symval;
typedef struct  Column      Column;
typedef struct  Columnval   Columnval;

union Symval{               /* Valor de un simbolo */
    int intval;		/* Entero */
    double doubleval;         /* Flotante */
    char *str;              /* String */
};

struct Symbol { /* entrada de la tabla de símbolos */
	char   *name;
	short   type;   /* VAR, BLTIN, UNDEF */
    	Symval u;
	struct Symbol *next;  /* para ligarse a otro simbolo */ 
};

union Datum{
    int intval;
    char *str;
    Symbol *sym;
    Columnval *col;
};
struct Column{      /* Columnas de una tabla */
    Columnval *val;
    Column *next;
};
struct Columnval{   /* Columna de una tabla */
    char *nombre;
    short type;     /* VARCHAR */
    int len;        /* Longitud del tipo */
    Datum *val;
};

/*********** Yacc *****************/
void yyerror (char *s);
int yylex ();
void warning(char *s, char *t);
void execerror(char *s, char *t);
void fpecatch(int);
void defnonly(char *);
int follow(int, int, int);

/*********** Tabla de simbolos ****/
int init();
Symbol *install(char *,int, char *); 
Symbol *lookup(char *s);

/********** Maquina de pila virtual **/
#define code2(c1, c2)       code(c1); code(c2);
#define code3(c1, c2, c3)   code(c1); code(c2); code(c3);
#define STOP                (Inst) 0
#define NSTACK              256
#define NPROG               2000
#define NFRAME              100

static Datum stack[NSTACK];
static Datum *stackp;
extern Inst prog[NPROG];   /* La maquina */
extern Inst *progp;        /* Siguiente celda libre en generacion de codigo */
extern Inst *pc;           /* Contador de programa durante ejecucion */
extern Inst *progbase;  /* Inicio del subprograma actual */

void  initcode();
void  push(Datum);
Datum pop();
int   constpush();
int   colpush();
Inst  *code(Inst);
void  execute(Inst *);

int createDatabase();
Column *columnlist(Columnval *, Column *);
Columnval *createColumn(char *, short, int, Datum *);
int createTable();
int insert();
int selectsql();
int deletesql();
int updatesql();
int eq();
int gt();
int ge();
int lt();
int le();
int ne();
int log_or();
int log_and();

#endif
