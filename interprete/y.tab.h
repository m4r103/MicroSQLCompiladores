/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NAME = 258,
    INTNUM = 259,
    BOOL = 260,
    APPROXNUM = 261,
    AUTO_INCREMENT = 262,
    CREATE = 263,
    DATABASE = 264,
    INDEX = 265,
    INSERT = 266,
    INTO = 267,
    VALUES = 268,
    PRIMARY = 269,
    KEY = 270,
    NULLX = 271,
    SCHEMA = 272,
    TABLE = 273,
    VARCHAR = 274,
    INDEF = 275,
    USERVAR = 276,
    OR = 277,
    XOR = 278,
    ANDOP = 279,
    NOT = 280,
    MOD = 281,
    nonassoc = 282,
    UMINUS = 283
  };
#endif
/* Tokens.  */
#define NAME 258
#define INTNUM 259
#define BOOL 260
#define APPROXNUM 261
#define AUTO_INCREMENT 262
#define CREATE 263
#define DATABASE 264
#define INDEX 265
#define INSERT 266
#define INTO 267
#define VALUES 268
#define PRIMARY 269
#define KEY 270
#define NULLX 271
#define SCHEMA 272
#define TABLE 273
#define VARCHAR 274
#define INDEF 275
#define USERVAR 276
#define OR 277
#define XOR 278
#define ANDOP 279
#define NOT 280
#define MOD 281
#define nonassoc 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 6 "sql.y" /* yacc.c:1909  */

    int intval;
    double floatval;
    char *strval;
    int subtok;
    Symbol *sym;
    Inst *inst;
    Datum *const_val;
    Column *columnlist;
    Columnval *columnval;

#line 122 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
