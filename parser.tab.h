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
     CONST = 258,
     LET = 259,
     PROC = 260,
     INT = 261,
     BOOL = 262,
     STRING = 263,
     DISPLAY = 264,
     CLEAR = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     REPEAT = 269,
     UNTIL = 270,
     CALL = 271,
     LOG = 272,
     HALT = 273,
     BREAK = 274,
     CONTINUE = 275,
     TRUE = 276,
     FALSE = 277,
     OR = 278,
     AND = 279,
     SENSOR = 280,
     ACT = 281,
     MEM = 282,
     COIN = 283,
     WATER_OK = 284,
     BEANS_OK = 285,
     CUP_DETECTED = 286,
     TEMP = 287,
     EMERGENCY = 288,
     HEATER = 289,
     PUMP = 290,
     GRINDER = 291,
     VALVE = 292,
     DISPLAY_ACT = 293,
     ARROW = 294,
     EQ = 295,
     NEQ = 296,
     LEQ = 297,
     GEQ = 298,
     LT = 299,
     GT = 300,
     ASSIGN = 301,
     PLUS = 302,
     MINUS = 303,
     MULT = 304,
     DIV = 305,
     MOD = 306,
     NOT = 307,
     LPAREN = 308,
     RPAREN = 309,
     LBRACE = 310,
     RBRACE = 311,
     LBRACKET = 312,
     RBRACKET = 313,
     SEMICOLON = 314,
     COMMA = 315,
     DOT = 316,
     NUMBER = 317,
     IDENTIFIER = 318,
     STRING_LITERAL = 319,
     UMINUS = 320
   };
#endif
/* Tokens.  */
#define CONST 258
#define LET 259
#define PROC 260
#define INT 261
#define BOOL 262
#define STRING 263
#define DISPLAY 264
#define CLEAR 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define REPEAT 269
#define UNTIL 270
#define CALL 271
#define LOG 272
#define HALT 273
#define BREAK 274
#define CONTINUE 275
#define TRUE 276
#define FALSE 277
#define OR 278
#define AND 279
#define SENSOR 280
#define ACT 281
#define MEM 282
#define COIN 283
#define WATER_OK 284
#define BEANS_OK 285
#define CUP_DETECTED 286
#define TEMP 287
#define EMERGENCY 288
#define HEATER 289
#define PUMP 290
#define GRINDER 291
#define VALVE 292
#define DISPLAY_ACT 293
#define ARROW 294
#define EQ 295
#define NEQ 296
#define LEQ 297
#define GEQ 298
#define LT 299
#define GT 300
#define ASSIGN 301
#define PLUS 302
#define MINUS 303
#define MULT 304
#define DIV 305
#define MOD 306
#define NOT 307
#define LPAREN 308
#define RPAREN 309
#define LBRACE 310
#define RBRACE 311
#define LBRACKET 312
#define RBRACKET 313
#define SEMICOLON 314
#define COMMA 315
#define DOT 316
#define NUMBER 317
#define IDENTIFIER 318
#define STRING_LITERAL 319
#define UMINUS 320




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "parser.y"
{
    int num;
    char* str;
}
/* Line 1529 of yacc.c.  */
#line 184 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

