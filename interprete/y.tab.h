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
    STRING = 259,
    INTNUM = 260,
    BOOL = 261,
    APPROXNUM = 262,
    AUTO_INCREMENT = 263,
    CREATE = 264,
    DATABASE = 265,
    INDEX = 266,
    INSERT = 267,
    INTO = 268,
    VALUES = 269,
    PRIMARY = 270,
    KEY = 271,
    NULLX = 272,
    SCHEMA = 273,
    TABLE = 274,
    VARCHAR = 275,
    INDEF = 276,
    ASC = 277,
    ORDER = 278,
    BY = 279,
    DESC = 280,
    SELECT = 281,
    FROM = 282,
    WHERE = 283,
    DELETE = 284,
    USERVAR = 285,
    OR = 286,
    XOR = 287,
    ANDOP = 288,
    NOT = 289,
    MOD = 290,
    nonassoc = 291,
    UMINUS = 292
  };
#endif
/* Tokens.  */
#define NAME 258
#define STRING 259
#define INTNUM 260
#define BOOL 261
#define APPROXNUM 262
#define AUTO_INCREMENT 263
#define CREATE 264
#define DATABASE 265
#define INDEX 266
#define INSERT 267
#define INTO 268
#define VALUES 269
#define PRIMARY 270
#define KEY 271
#define NULLX 272
#define SCHEMA 273
#define TABLE 274
#define VARCHAR 275
#define INDEF 276
#define ASC 277
#define ORDER 278
#define BY 279
#define DESC 280
#define SELECT 281
#define FROM 282
#define WHERE 283
#define DELETE 284
#define USERVAR 285
#define OR 286
#define XOR 287
#define ANDOP 288
#define NOT 289
#define MOD 290
#define nonassoc 291
#define UMINUS 292

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

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
