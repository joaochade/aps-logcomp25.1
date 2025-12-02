/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RECIPE = 258,
     ROUTINE = 259,
     REQUIRES = 260,
     STEPS = 261,
     SET = 262,
     COINS = 263,
     WATER = 264,
     BEANS = 265,
     CUP = 266,
     GRIND = 267,
     HEAT = 268,
     BREW = 269,
     DISPENSE = 270,
     WAIT = 271,
     SHOW = 272,
     DO = 273,
     CHECK = 274,
     OTHERWISE = 275,
     WHILE = 276,
     REPEAT = 277,
     TIMES = 278,
     FOR = 279,
     FROM = 280,
     TO = 281,
     STEP = 282,
     ABORT = 283,
     SKIP = 284,
     EXIT = 285,
     SENSE = 286,
     MEMORY = 287,
     COFFEE = 288,
     STEAM = 289,
     MILK = 290,
     SENSOR_COIN = 291,
     SENSOR_WATER = 292,
     SENSOR_BEANS = 293,
     SENSOR_CUP = 294,
     SENSOR_TEMP = 295,
     SENSOR_EMERGENCY = 296,
     CELSIUS = 297,
     FAHRENHEIT = 298,
     ML = 299,
     SECONDS = 300,
     MILLISECONDS = 301,
     AND = 302,
     OR = 303,
     NOT = 304,
     EQ = 305,
     NE = 306,
     LE = 307,
     GE = 308,
     LT = 309,
     GT = 310,
     PLUS = 311,
     MINUS = 312,
     MULT = 313,
     DIV = 314,
     MOD = 315,
     ASSIGN = 316,
     SEMICOLON = 317,
     COMMA = 318,
     LPAREN = 319,
     RPAREN = 320,
     LBRACE = 321,
     RBRACE = 322,
     LBRACKET = 323,
     RBRACKET = 324,
     NUMBER = 325,
     FLOAT = 326,
     STRING = 327,
     IDENTIFIER = 328,
     UMINUS = 329
   };
#endif
/* Tokens.  */
#define RECIPE 258
#define ROUTINE 259
#define REQUIRES 260
#define STEPS 261
#define SET 262
#define COINS 263
#define WATER 264
#define BEANS 265
#define CUP 266
#define GRIND 267
#define HEAT 268
#define BREW 269
#define DISPENSE 270
#define WAIT 271
#define SHOW 272
#define DO 273
#define CHECK 274
#define OTHERWISE 275
#define WHILE 276
#define REPEAT 277
#define TIMES 278
#define FOR 279
#define FROM 280
#define TO 281
#define STEP 282
#define ABORT 283
#define SKIP 284
#define EXIT 285
#define SENSE 286
#define MEMORY 287
#define COFFEE 288
#define STEAM 289
#define MILK 290
#define SENSOR_COIN 291
#define SENSOR_WATER 292
#define SENSOR_BEANS 293
#define SENSOR_CUP 294
#define SENSOR_TEMP 295
#define SENSOR_EMERGENCY 296
#define CELSIUS 297
#define FAHRENHEIT 298
#define ML 299
#define SECONDS 300
#define MILLISECONDS 301
#define AND 302
#define OR 303
#define NOT 304
#define EQ 305
#define NE 306
#define LE 307
#define GE 308
#define LT 309
#define GT 310
#define PLUS 311
#define MINUS 312
#define MULT 313
#define DIV 314
#define MOD 315
#define ASSIGN 316
#define SEMICOLON 317
#define COMMA 318
#define LPAREN 319
#define RPAREN 320
#define LBRACE 321
#define RBRACE 322
#define LBRACKET 323
#define RBRACKET 324
#define NUMBER 325
#define FLOAT 326
#define STRING 327
#define IDENTIFIER 328
#define UMINUS 329




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "coffee.y"
{
    int num;
    double fnum;
    char *str;
}
/* Line 1529 of yacc.c.  */
#line 203 "coffee.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

