/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "coffee.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int line_num;
extern FILE *yyin;
void yyerror(const char *s);

FILE *output_file;
int label_count = 0;
int temp_count = 0;

char* new_label();
char* new_temp();
void emit(const char* code);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "coffee.y"
{
    int num;
    double fnum;
    char *str;
}
/* Line 193 of yacc.c.  */
#line 269 "coffee.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 282 "coffee.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   643

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    21,
      29,    36,    39,    41,    45,    48,    50,    52,    54,    60,
      61,    64,    67,    70,    72,    74,    77,    79,    84,    92,
      96,    98,   103,   107,   112,   114,   119,   123,   128,   132,
     135,   138,   144,   154,   160,   167,   177,   189,   191,   194,
     196,   198,   202,   206,   210,   214,   218,   222,   226,   230,
     234,   238,   242,   246,   250,   253,   256,   258,   260,   262,
     264,   266,   269,   274,   278,   280,   282,   284,   286,   288,
     290,   292,   294,   296,   298,   300,   302,   304,   306
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,    77,    -1,    -1,    77,    78,    -1,    80,
      -1,    84,    -1,    79,    -1,     7,    73,    61,    93,    62,
      -1,     3,    73,    81,     6,    66,    85,    67,    -1,     3,
      73,     6,    66,    85,    67,    -1,     5,    82,    -1,    83,
      -1,    82,    63,    83,    -1,     8,    70,    -1,     9,    -1,
      10,    -1,    11,    -1,     4,    73,    66,    85,    67,    -1,
      -1,    85,    86,    -1,    87,    62,    -1,    89,    62,    -1,
      90,    -1,    91,    -1,    92,    62,    -1,    88,    -1,     7,
      73,    61,    93,    -1,     7,    32,    68,    93,    69,    61,
      93,    -1,    66,    85,    67,    -1,    12,    -1,    12,    24,
      93,    98,    -1,    13,    26,    93,    -1,    13,    26,    93,
      97,    -1,    14,    -1,    14,    24,    93,    98,    -1,    15,
      96,    93,    -1,    15,    96,    93,    99,    -1,    16,    93,
      98,    -1,    17,    93,    -1,    18,    73,    -1,    19,    93,
      66,    85,    67,    -1,    19,    93,    66,    85,    67,    20,
      66,    85,    67,    -1,    21,    93,    66,    85,    67,    -1,
      22,    93,    23,    66,    85,    67,    -1,    24,    73,    25,
      93,    26,    93,    66,    85,    67,    -1,    24,    73,    25,
      93,    26,    93,    27,    93,    66,    85,    67,    -1,    28,
      -1,    28,    93,    -1,    30,    -1,    29,    -1,    93,    48,
      93,    -1,    93,    47,    93,    -1,    93,    50,    93,    -1,
      93,    51,    93,    -1,    93,    54,    93,    -1,    93,    55,
      93,    -1,    93,    52,    93,    -1,    93,    53,    93,    -1,
      93,    56,    93,    -1,    93,    57,    93,    -1,    93,    58,
      93,    -1,    93,    59,    93,    -1,    93,    60,    93,    -1,
      49,    93,    -1,    57,    93,    -1,    94,    -1,    70,    -1,
      71,    -1,    72,    -1,    73,    -1,    31,    95,    -1,    32,
      68,    93,    69,    -1,    64,    93,    65,    -1,    36,    -1,
      37,    -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,
       9,    -1,    33,    -1,    34,    -1,    35,    -1,    42,    -1,
      43,    -1,    45,    -1,    46,    -1,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    66,    68,    72,    73,    74,    78,    90,
      95,   103,   107,   108,   112,   125,   134,   143,   155,   162,
     164,   168,   169,   170,   171,   172,   173,   177,   184,   195,
     199,   206,   215,   222,   229,   236,   245,   253,   261,   268,
     274,   283,   295,   315,   318,   331,   354,   382,   386,   393,
     397,   404,   416,   428,   446,   464,   482,   500,   518,   536,
     548,   560,   572,   584,   596,   606,   616,   622,   627,   632,
     635,   644,   653,   663,   669,   670,   671,   672,   673,   674,
     678,   679,   680,   681,   685,   686,   690,   691,   695
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RECIPE", "ROUTINE", "REQUIRES", "STEPS",
  "SET", "COINS", "WATER", "BEANS", "CUP", "GRIND", "HEAT", "BREW",
  "DISPENSE", "WAIT", "SHOW", "DO", "CHECK", "OTHERWISE", "WHILE",
  "REPEAT", "TIMES", "FOR", "FROM", "TO", "STEP", "ABORT", "SKIP", "EXIT",
  "SENSE", "MEMORY", "COFFEE", "STEAM", "MILK", "SENSOR_COIN",
  "SENSOR_WATER", "SENSOR_BEANS", "SENSOR_CUP", "SENSOR_TEMP",
  "SENSOR_EMERGENCY", "CELSIUS", "FAHRENHEIT", "ML", "SECONDS",
  "MILLISECONDS", "AND", "OR", "NOT", "EQ", "NE", "LE", "GE", "LT", "GT",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "ASSIGN", "SEMICOLON", "COMMA",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "NUMBER",
  "FLOAT", "STRING", "IDENTIFIER", "UMINUS", "$accept", "program",
  "declarations", "declaration", "var_decl", "recipe_def", "requirements",
  "requirement_list", "requirement", "routine_def", "statements",
  "statement", "assignment", "block", "action", "conditional", "loop",
  "control_flow", "expression", "primary", "sensor_name", "liquid",
  "temp_unit", "time_unit", "volume_unit", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    78,    78,    79,    80,
      80,    81,    82,    82,    83,    83,    83,    83,    84,    85,
      85,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    91,    91,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    97,    97,    98,    98,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     5,     7,
       6,     2,     1,     3,     2,     1,     1,     1,     5,     0,
       2,     2,     2,     1,     1,     2,     1,     4,     7,     3,
       1,     4,     3,     4,     1,     4,     3,     4,     3,     2,
       2,     5,     9,     5,     6,     9,    11,     1,     2,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     2,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     4,     7,     5,
       6,     0,     0,     0,     0,     0,     0,    19,     0,     0,
      15,    16,    17,    11,    12,    19,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,    70,     0,    66,    14,
       0,     0,    19,     0,    30,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    50,    49,    19,    18,
      20,     0,    26,     0,    23,    24,     0,    74,    75,    76,
      77,    78,    79,    71,     0,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,    13,    10,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,     0,     0,    39,    40,     0,     0,
       0,     0,    48,     0,    21,    22,    25,     0,    73,    52,
      51,    53,    54,    57,    58,    55,    56,    59,    60,    61,
      62,    63,     9,     0,     0,     0,    32,     0,    36,    86,
      87,    38,    19,    19,     0,     0,    29,    72,     0,    27,
      31,    84,    85,    33,    35,    88,    37,     0,     0,    19,
       0,     0,    41,    43,     0,     0,     0,     0,    44,     0,
      28,    19,     0,    19,     0,     0,     0,    42,    19,    45,
       0,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    16,    23,    24,    10,
      27,    60,    61,    62,    63,    64,    65,    66,    37,    38,
      73,   104,   153,   141,   156
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const yytype_int16 yypact[] =
{
    -111,     6,    93,  -111,   -55,   -52,   -26,  -111,  -111,  -111,
    -111,    84,   -18,    11,   130,    18,    81,  -111,    42,    25,
    -111,  -111,  -111,    35,  -111,  -111,    66,    64,    26,    65,
      42,    42,    42,  -111,  -111,  -111,  -111,   567,  -111,  -111,
     130,   142,  -111,   -27,   111,   116,   120,    -5,    42,    42,
      72,    42,    42,    42,    74,    42,  -111,  -111,  -111,  -111,
    -111,    88,  -111,    89,  -111,  -111,    90,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,    42,  -111,  -111,   518,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,  -111,  -111,  -111,   161,    94,   104,    42,    42,    42,
    -111,  -111,  -111,  -111,    42,   553,   583,  -111,   295,   370,
     -16,   144,   583,   217,  -111,  -111,  -111,   145,  -111,    69,
     313,   -44,   -44,    51,    51,    51,    51,    43,    43,  -111,
    -111,  -111,  -111,    42,    42,   553,   504,   553,   537,  -111,
    -111,  -111,  -111,  -111,   101,    42,  -111,  -111,   220,   583,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,   236,   292,  -111,
     470,   123,   166,  -111,   311,    42,    42,   115,  -111,   435,
     583,  -111,    42,  -111,   367,   484,   386,  -111,  -111,  -111,
     442,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   147,  -111,
     -25,  -111,  -111,  -111,  -111,  -111,  -111,  -111,   -29,  -111,
    -111,  -111,  -111,  -110,  -111
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      41,    75,    76,    77,   100,    95,     3,   144,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    94,    11,   105,
     106,    12,   108,   109,   110,   150,   112,   154,   101,   102,
     103,    78,    79,   113,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   117,    96,    13,    17,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    67,    68,    69,    70,    71,    72,   135,   136,
     137,    43,    18,    28,    29,   138,    44,    45,    46,    47,
      48,    49,    50,    51,    25,    52,    53,    26,    54,    14,
      15,    30,    55,    56,    57,    39,     4,     5,    40,    31,
       6,    88,    89,    90,   148,   149,    32,    86,    87,    88,
      89,    90,    33,    34,    35,    36,   160,   157,   158,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      58,    59,    42,    74,   164,    97,   169,   170,    19,    20,
      21,    22,    98,   175,    99,   107,   174,   111,   176,    43,
     114,   115,   116,   180,    44,    45,    46,    47,    48,    49,
      50,    51,   133,    52,    53,   134,    54,   159,    43,   145,
      55,    56,    57,    44,    45,    46,    47,    48,    49,    50,
      51,   171,    52,    53,   166,    54,   167,    92,     0,    55,
      56,    57,    78,    79,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,    58,    93,
       0,     0,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,     0,    58,   132,    44,
      45,    46,    47,    48,    49,    50,    51,     0,    52,    53,
       0,    54,     0,    43,     0,    55,    56,    57,    44,    45,
      46,    47,    48,    49,    50,    51,     0,    52,    53,     0,
      54,     0,     0,     0,    55,    56,    57,    78,    79,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,    58,   146,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    58,   162,    44,    45,    46,    47,    48,    49,
      50,    51,     0,    52,    53,     0,    54,     0,    43,     0,
      55,    56,    57,    44,    45,    46,    47,    48,    49,    50,
      51,     0,    52,    53,     0,    54,     0,     0,     0,    55,
      56,    57,    78,    79,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,    58,   163,
      78,   142,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    43,     0,     0,    58,   168,    44,
      45,    46,    47,    48,    49,    50,    51,     0,    52,    53,
       0,    54,     0,    43,     0,    55,    56,    57,    44,    45,
      46,    47,    48,    49,    50,    51,     0,    52,    53,     0,
      54,     0,     0,     0,    55,    56,    57,    78,    79,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,    58,   177,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    58,   179,    44,    45,    46,    47,    48,    49,
      50,    51,   172,    52,    53,     0,    54,     0,     0,     0,
      55,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   165,     0,     0,     0,
       0,   173,     0,     0,     0,     0,     0,     0,    58,   181,
       0,     0,     0,     0,     0,     0,     0,    78,    79,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,   151,   152,     0,     0,
     178,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    78,    79,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,   155,     0,   118,    78,    79,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   139,   140,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    78,    79,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90
};

static const yytype_int16 yycheck[] =
{
      25,    30,    31,    32,     9,    32,     0,    23,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    42,    73,    48,
      49,    73,    51,    52,    53,   135,    55,   137,    33,    34,
      35,    47,    48,    58,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    74,    73,    73,    66,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    36,    37,    38,    39,    40,    41,    97,    98,
      99,     7,    61,    31,    32,   104,    12,    13,    14,    15,
      16,    17,    18,    19,    66,    21,    22,     6,    24,     5,
       6,    49,    28,    29,    30,    70,     3,     4,    63,    57,
       7,    58,    59,    60,   133,   134,    64,    56,    57,    58,
      59,    60,    70,    71,    72,    73,   145,   142,   143,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      66,    67,    66,    68,   159,    24,   165,   166,     8,     9,
      10,    11,    26,   172,    24,    73,   171,    73,   173,     7,
      62,    62,    62,   178,    12,    13,    14,    15,    16,    17,
      18,    19,    68,    21,    22,    61,    24,    66,     7,    25,
      28,    29,    30,    12,    13,    14,    15,    16,    17,    18,
      19,    66,    21,    22,    61,    24,    20,    40,    -1,    28,
      29,    30,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    66,    67,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      -1,    24,    -1,     7,    -1,    28,    29,    30,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    -1,    -1,    28,    29,    30,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    66,    67,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    -1,    24,    -1,     7,    -1,
      28,    29,    30,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,    28,
      29,    30,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    66,    67,
      47,    66,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     7,    -1,    -1,    66,    67,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      -1,    24,    -1,     7,    -1,    28,    29,    30,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    -1,    -1,    28,    29,    30,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    66,    67,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    66,    67,    12,    13,    14,    15,    16,    17,
      18,    19,    27,    21,    22,    -1,    24,    -1,    -1,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    26,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    42,    43,    -1,    -1,
      66,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    44,    -1,    65,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    76,    77,     0,     3,     4,     7,    78,    79,    80,
      84,    73,    73,    73,     5,     6,    81,    66,    61,     8,
       9,    10,    11,    82,    83,    66,     6,    85,    31,    32,
      49,    57,    64,    70,    71,    72,    73,    93,    94,    70,
      63,    85,    66,     7,    12,    13,    14,    15,    16,    17,
      18,    19,    21,    22,    24,    28,    29,    30,    66,    67,
      86,    87,    88,    89,    90,    91,    92,    36,    37,    38,
      39,    40,    41,    95,    68,    93,    93,    93,    47,    48,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    62,    83,    67,    85,    32,    73,    24,    26,    24,
       9,    33,    34,    35,    96,    93,    93,    73,    93,    93,
      93,    73,    93,    85,    62,    62,    62,    93,    65,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    67,    68,    61,    93,    93,    93,    93,    45,
      46,    98,    66,    66,    23,    25,    67,    69,    93,    93,
      98,    42,    43,    97,    98,    44,    99,    85,    85,    66,
      93,    69,    67,    67,    85,    26,    61,    20,    67,    93,
      93,    66,    27,    66,    85,    93,    85,    67,    66,    67,
      85,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 78 "coffee.y"
    {
        emit("    ; Declaração de variável");
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(4) - (5)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", (yyvsp[(2) - (5)].str));
        emit(buffer);
        emit("");
    ;}
    break;

  case 9:
#line 90 "coffee.y"
    {
        emit("    ; Fim da receita");
        emit("    HALT");
        emit("");
    ;}
    break;

  case 10:
#line 95 "coffee.y"
    {
        emit("    ; Fim da receita");
        emit("    HALT");
        emit("");
    ;}
    break;

  case 14:
#line 112 "coffee.y"
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    ; Requer %d moedas", (yyvsp[(2) - (2)].num));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SENSOR COIN_INSERTED R0");
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %d", (yyvsp[(2) - (2)].num));
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JGE coins_ok");
        emit("    JMP error_insufficient_coins");
        emit("coins_ok:");
    ;}
    break;

  case 15:
#line 125 "coffee.y"
    {
        emit("    ; Requer água");
        emit("    SENSOR WATER_LEVEL R0");
        emit("    SET R1 10");
        emit("    CMP R0 R1");
        emit("    JGE water_ok");
        emit("    JMP error_no_water");
        emit("water_ok:");
    ;}
    break;

  case 16:
#line 134 "coffee.y"
    {
        emit("    ; Requer grãos");
        emit("    SENSOR BEANS_LEVEL R0");
        emit("    SET R1 10");
        emit("    CMP R0 R1");
        emit("    JGE beans_ok");
        emit("    JMP error_no_beans");
        emit("beans_ok:");
    ;}
    break;

  case 17:
#line 143 "coffee.y"
    {
        emit("    ; Requer copo");
        emit("    SENSOR CUP_PRESENT R0");
        emit("    SET R1 1");
        emit("    CMP R0 R1");
        emit("    JGE cup_ok");
        emit("    JMP error_no_cup");
        emit("cup_ok:");
    ;}
    break;

  case 18:
#line 155 "coffee.y"
    {
        emit("    ; Fim da rotina");
        emit("    RET");
        emit("");
    ;}
    break;

  case 27:
#line 177 "coffee.y"
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(4) - (4)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", (yyvsp[(2) - (4)].str));
        emit(buffer);
    ;}
    break;

  case 28:
#line 184 "coffee.y"
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(7) - (7)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(4) - (7)].str));
        emit(buffer);
        emit("    STORE_MEM R0 R1");
    ;}
    break;

  case 30:
#line 199 "coffee.y"
    {
        emit("    ; Moer grãos");
        emit("    ACTUATOR GRINDER 1");
        emit("    SET R0 5000");
        emit("    WAIT R0");
        emit("    ACTUATOR GRINDER 0");
    ;}
    break;

  case 31:
#line 206 "coffee.y"
    {
        char buffer[256];
        emit("    ; Moer grãos");
        emit("    ACTUATOR GRINDER 1");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(3) - (4)].str));
        emit(buffer);
        emit("    WAIT R0");
        emit("    ACTUATOR GRINDER 0");
    ;}
    break;

  case 32:
#line 215 "coffee.y"
    {
        char buffer[256];
        emit("    ; Aquecer");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    ACTUATOR HEATER R0");
    ;}
    break;

  case 33:
#line 222 "coffee.y"
    {
        char buffer[256];
        emit("    ; Aquecer");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(3) - (4)].str));
        emit(buffer);
        emit("    ACTUATOR HEATER R0");
    ;}
    break;

  case 34:
#line 229 "coffee.y"
    {
        emit("    ; Fazer café");
        emit("    ACTUATOR PUMP 1");
        emit("    SET R0 25000");
        emit("    WAIT R0");
        emit("    ACTUATOR PUMP 0");
    ;}
    break;

  case 35:
#line 236 "coffee.y"
    {
        char buffer[256];
        emit("    ; Fazer café");
        emit("    ACTUATOR PUMP 1");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(3) - (4)].str));
        emit(buffer);
        emit("    WAIT R0");
        emit("    ACTUATOR PUMP 0");
    ;}
    break;

  case 36:
#line 245 "coffee.y"
    {
        char buffer[256];
        emit("    ; Dispensar líquido");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    ACTUATOR VALVE_%s R0", (yyvsp[(2) - (3)].str));
        emit(buffer);
    ;}
    break;

  case 37:
#line 253 "coffee.y"
    {
        char buffer[256];
        emit("    ; Dispensar líquido");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(3) - (4)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    ACTUATOR VALVE_%s R0", (yyvsp[(2) - (4)].str));
        emit(buffer);
    ;}
    break;

  case 38:
#line 261 "coffee.y"
    {
        char buffer[256];
        emit("    ; Esperar");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(2) - (3)].str));
        emit(buffer);
        emit("    WAIT R0");
    ;}
    break;

  case 39:
#line 268 "coffee.y"
    {
        char buffer[256];
        emit("    ; Mostrar mensagem");
        snprintf(buffer, sizeof(buffer), "    DISPLAY %s", (yyvsp[(2) - (2)].str));
        emit(buffer);
    ;}
    break;

  case 40:
#line 274 "coffee.y"
    {
        char buffer[256];
        emit("    ; Chamar rotina");
        snprintf(buffer, sizeof(buffer), "    CALL %s", (yyvsp[(2) - (2)].str));
        emit(buffer);
    ;}
    break;

  case 41:
#line 283 "coffee.y"
    {
        char *label_end = new_label();
        char buffer[256];
        
        emit("    ; Condicional check");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(2) - (5)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    JZ R0 %s", label_end);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "%s:", label_end);
        emit(buffer);
    ;}
    break;

  case 42:
#line 295 "coffee.y"
    {
        char *label_else = new_label();
        char *label_end = new_label();
        char buffer[256];
        
        emit("    ; Condicional check-otherwise");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(2) - (9)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    JZ R0 %s", label_else);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    JMP %s", label_end);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "%s:", label_else);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "%s:", label_end);
        emit(buffer);
    ;}
    break;

  case 43:
#line 315 "coffee.y"
    {
        emit("    ; TODO: While loop - código pode estar fora de ordem");
    ;}
    break;

  case 44:
#line 318 "coffee.y"
    {
        char buffer[256];
        emit("    ; Loop repeat");
        snprintf(buffer, sizeof(buffer), "    SET R2 %s", (yyvsp[(2) - (6)].str));
        emit(buffer);
        emit("    SET R3 0");
        emit("repeat_start:");
        emit("    CMP R3 R2");
        emit("    JGE repeat_end");
        emit("    ADD R3 1");
        emit("    JMP repeat_start");
        emit("repeat_end:");
    ;}
    break;

  case 45:
#line 331 "coffee.y"
    {
        char buffer[256];
        
        emit("    ; Loop for");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(4) - (9)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", (yyvsp[(2) - (9)].str));
        emit(buffer);
        emit("for_start:");
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", (yyvsp[(2) - (9)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(6) - (9)].str));
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JG for_end");
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", (yyvsp[(2) - (9)].str));
        emit(buffer);
        emit("    ADD R0 1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", (yyvsp[(2) - (9)].str));
        emit(buffer);
        emit("    JMP for_start");
        emit("for_end:");
    ;}
    break;

  case 46:
#line 354 "coffee.y"
    {
        char buffer[256];
        
        emit("    ; Loop for com step");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(4) - (11)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", (yyvsp[(2) - (11)].str));
        emit(buffer);
        emit("for_start:");
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", (yyvsp[(2) - (11)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(6) - (11)].str));
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JG for_end");
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", (yyvsp[(2) - (11)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R2 %s", (yyvsp[(8) - (11)].str));
        emit(buffer);
        emit("    ADD R0 R2");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", (yyvsp[(2) - (11)].str));
        emit(buffer);
        emit("    JMP for_start");
        emit("for_end:");
    ;}
    break;

  case 47:
#line 382 "coffee.y"
    {
        emit("    ; Abortar");
        emit("    HALT");
    ;}
    break;

  case 48:
#line 386 "coffee.y"
    {
        char buffer[256];
        emit("    ; Abortar com mensagem");
        snprintf(buffer, sizeof(buffer), "    DISPLAY %s", (yyvsp[(2) - (2)].str));
        emit(buffer);
        emit("    HALT");
    ;}
    break;

  case 49:
#line 393 "coffee.y"
    {
        emit("    ; Exit (break)");
        emit("    JMP loop_end");
    ;}
    break;

  case 50:
#line 397 "coffee.y"
    {
        emit("    ; Skip (continue)");
        emit("    JMP loop_start");
    ;}
    break;

  case 51:
#line 404 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    OR R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 52:
#line 416 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    AND R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 53:
#line 428 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JE temp_true");
        emit("    SET R0 0");
        emit("    JMP temp_end");
        emit("temp_true:");
        emit("    SET R0 1");
        emit("temp_end:");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 54:
#line 446 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JNE temp_true");
        emit("    SET R0 0");
        emit("    JMP temp_end");
        emit("temp_true:");
        emit("    SET R0 1");
        emit("temp_end:");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 55:
#line 464 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JL temp_true");
        emit("    SET R0 0");
        emit("    JMP temp_end");
        emit("temp_true:");
        emit("    SET R0 1");
        emit("temp_end:");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 56:
#line 482 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JG temp_true");
        emit("    SET R0 0");
        emit("    JMP temp_end");
        emit("temp_true:");
        emit("    SET R0 1");
        emit("temp_end:");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 57:
#line 500 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JLE temp_true");
        emit("    SET R0 0");
        emit("    JMP temp_end");
        emit("temp_true:");
        emit("    SET R0 1");
        emit("temp_end:");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 58:
#line 518 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JGE temp_true");
        emit("    SET R0 0");
        emit("    JMP temp_end");
        emit("temp_true:");
        emit("    SET R0 1");
        emit("temp_end:");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 59:
#line 536 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    ADD R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 60:
#line 548 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    SUB R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 61:
#line 560 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    MUL R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 62:
#line 572 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    DIV R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 63:
#line 584 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(1) - (3)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (3)].str));
        emit(buffer);
        emit("    MOD R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 64:
#line 596 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(2) - (2)].str));
        emit(buffer);
        emit("    NOT R0");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 65:
#line 606 "coffee.y"
    {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", (yyvsp[(2) - (2)].str));
        emit(buffer);
        emit("    NEG R0");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        (yyval.str) = result;
    ;}
    break;

  case 66:
#line 616 "coffee.y"
    {
        (yyval.str) = (yyvsp[(1) - (1)].str);
    ;}
    break;

  case 67:
#line 622 "coffee.y"
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", (yyvsp[(1) - (1)].num));
        (yyval.str) = strdup(buffer);
    ;}
    break;

  case 68:
#line 627 "coffee.y"
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.2f", (yyvsp[(1) - (1)].fnum));
        (yyval.str) = strdup(buffer);
    ;}
    break;

  case 69:
#line 632 "coffee.y"
    {
        (yyval.str) = (yyvsp[(1) - (1)].str);
    ;}
    break;

  case 70:
#line 635 "coffee.y"
    {
        char *temp = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", (yyvsp[(1) - (1)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", temp);
        emit(buffer);
        (yyval.str) = temp;
    ;}
    break;

  case 71:
#line 644 "coffee.y"
    {
        char *temp = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SENSOR %s R0", (yyvsp[(2) - (2)].str));
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", temp);
        emit(buffer);
        (yyval.str) = temp;
    ;}
    break;

  case 72:
#line 653 "coffee.y"
    {
        char *temp = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", (yyvsp[(3) - (4)].str));
        emit(buffer);
        emit("    LOAD_MEM R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", temp);
        emit(buffer);
        (yyval.str) = temp;
    ;}
    break;

  case 73:
#line 663 "coffee.y"
    {
        (yyval.str) = (yyvsp[(2) - (3)].str);
    ;}
    break;

  case 74:
#line 669 "coffee.y"
    { (yyval.str) = strdup("COIN_INSERTED"); ;}
    break;

  case 75:
#line 670 "coffee.y"
    { (yyval.str) = strdup("WATER_LEVEL"); ;}
    break;

  case 76:
#line 671 "coffee.y"
    { (yyval.str) = strdup("BEANS_LEVEL"); ;}
    break;

  case 77:
#line 672 "coffee.y"
    { (yyval.str) = strdup("CUP_PRESENT"); ;}
    break;

  case 78:
#line 673 "coffee.y"
    { (yyval.str) = strdup("CURRENT_TEMP"); ;}
    break;

  case 79:
#line 674 "coffee.y"
    { (yyval.str) = strdup("EMERGENCY"); ;}
    break;

  case 80:
#line 678 "coffee.y"
    { (yyval.str) = strdup("WATER"); ;}
    break;

  case 81:
#line 679 "coffee.y"
    { (yyval.str) = strdup("COFFEE"); ;}
    break;

  case 82:
#line 680 "coffee.y"
    { (yyval.str) = strdup("STEAM"); ;}
    break;

  case 83:
#line 681 "coffee.y"
    { (yyval.str) = strdup("MILK"); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2534 "coffee.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 698 "coffee.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", line_num, s);
}

char* new_label() {
    static char label[32];
    snprintf(label, sizeof(label), "L%d", label_count++);
    return strdup(label);
}

char* new_temp() {
    static char temp[32];
    snprintf(temp, sizeof(temp), "T%d", temp_count++);
    return strdup(temp);
}

void emit(const char* code) {
    fprintf(output_file, "%s\n", code);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo_entrada.coffee> <arquivo_saida.asm>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Erro ao abrir arquivo de entrada: %s\n", argv[1]);
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (!output_file) {
        fprintf(stderr, "Erro ao abrir arquivo de saída: %s\n", argv[2]);
        fclose(yyin);
        return 1;
    }

    fprintf(output_file, "; CoffeeLang Assembly Output\n");
    fprintf(output_file, "; Gerado automaticamente\n\n");

    yyparse();

    fprintf(output_file, "\n; Labels de erro\n");
    fprintf(output_file, "error_insufficient_coins:\n");
    fprintf(output_file, "    DISPLAY \"Erro: Moedas insuficientes\"\n");
    fprintf(output_file, "    HALT\n\n");
    
    fprintf(output_file, "error_no_water:\n");
    fprintf(output_file, "    DISPLAY \"Erro: Sem água\"\n");
    fprintf(output_file, "    HALT\n\n");
    
    fprintf(output_file, "error_no_beans:\n");
    fprintf(output_file, "    DISPLAY \"Erro: Sem grãos\"\n");
    fprintf(output_file, "    HALT\n\n");
    
    fprintf(output_file, "error_no_cup:\n");
    fprintf(output_file, "    DISPLAY \"Erro: Sem copo\"\n");
    fprintf(output_file, "    HALT\n");

    fclose(yyin);
    fclose(output_file);

    printf("Compilação concluída com sucesso!\n");
    printf("Arquivo gerado: %s\n", argv[2]);

    return 0;
}
