%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
    int num;
    char* str;
}

/* Tokens */
%token CONST LET PROC
%token INT BOOL STRING
%token DISPLAY CLEAR IF ELSE WHILE REPEAT UNTIL
%token CALL LOG HALT BREAK CONTINUE
%token TRUE FALSE OR AND
%token SENSOR ACT MEM
%token COIN WATER_OK BEANS_OK CUP_DETECTED TEMP EMERGENCY
%token HEATER PUMP GRINDER VALVE DISPLAY_ACT
%token ARROW EQ NEQ LEQ GEQ LT GT
%token ASSIGN PLUS MINUS MULT DIV MOD NOT
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA DOT

%token <num> NUMBER
%token <str> IDENTIFIER STRING_LITERAL

/* Precedência e associatividade (do menor para maior) */
%left OR
%left AND
%left EQ NEQ
%left LT LEQ GT GEQ
%left PLUS MINUS
%left MULT DIV MOD
%right NOT UMINUS

/* Não-terminais */
%type <str> type

%%

program:
    /* vazio */
    | program declaration
    | program statement
    ;

/* -------------------- Declarações -------------------- */
declaration:
    const_decl
    | var_decl
    | proc_decl
    ;

const_decl:
    CONST IDENTIFIER ARROW type ASSIGN expr SEMICOLON
    { printf("Declaração de constante: %s\n", $2); free($2); free($4); }
    ;

var_decl:
    LET IDENTIFIER SEMICOLON
    { printf("Declaração de variável: %s\n", $2); free($2); }
    | LET IDENTIFIER ARROW type SEMICOLON
    { printf("Declaração de variável tipada: %s : %s\n", $2, $4); free($2); free($4); }
    | LET IDENTIFIER ASSIGN expr SEMICOLON
    { printf("Declaração de variável com inicialização: %s\n", $2); free($2); }
    | LET IDENTIFIER ARROW type ASSIGN expr SEMICOLON
    { printf("Declaração de variável tipada com inicialização: %s : %s\n", $2, $4); free($2); free($4); }
    ;

proc_decl:
    PROC IDENTIFIER LPAREN RPAREN block
    { printf("Declaração de procedimento: %s\n", $2); free($2); }
    | PROC IDENTIFIER LPAREN param_list RPAREN block
    { printf("Declaração de procedimento com parâmetros: %s\n", $2); free($2); }
    ;

param_list:
    param
    | param_list COMMA param
    ;

param:
    IDENTIFIER ARROW type
    { printf("Parâmetro: %s : %s\n", $1, $3); free($1); free($3); }
    ;

/* ----------------------- Tipos ----------------------- */
type:
    INT     { $$ = strdup("int"); }
    | BOOL  { $$ = strdup("bool"); }
    | STRING { $$ = strdup("string"); }
    ;

/* ---------------------- Comandos --------------------- */
statement:
    assign_stmt SEMICOLON
    | io_stmt SEMICOLON
    | if_stmt
    | while_stmt
    | repeat_stmt
    | call_stmt SEMICOLON
    | log_stmt SEMICOLON
    | halt_stmt SEMICOLON
    | break_stmt SEMICOLON
    | continue_stmt SEMICOLON
    | block
    ;

assign_stmt:
    lvalue ASSIGN expr
    { printf("Atribuição\n"); }
    ;

lvalue:
    IDENTIFIER
    { printf("lvalue: %s\n", $1); free($1); }
    | mem_ref
    | actuator_ref
    ;

io_stmt:
    DISPLAY LPAREN display_arg RPAREN
    { printf("Comando display\n"); }
    | CLEAR DOT DISPLAY_ACT
    { printf("Comando clear display\n"); }
    ;

display_arg:
    expr
    ;

if_stmt:
    IF LPAREN expr RPAREN block
    { printf("Comando if\n"); }
    | IF LPAREN expr RPAREN block ELSE block
    { printf("Comando if-else\n"); }
    ;

while_stmt:
    WHILE LPAREN expr RPAREN block
    { printf("Comando while\n"); }
    ;

repeat_stmt:
    REPEAT block UNTIL LPAREN expr RPAREN SEMICOLON
    { printf("Comando repeat-until\n"); }
    ;

call_stmt:
    CALL IDENTIFIER LPAREN RPAREN
    { printf("Chamada de procedimento: %s\n", $2); free($2); }
    | CALL IDENTIFIER LPAREN arg_list RPAREN
    { printf("Chamada de procedimento com argumentos: %s\n", $2); free($2); }
    ;

arg_list:
    expr
    | arg_list COMMA expr
    ;

log_stmt:
    LOG LPAREN expr RPAREN
    { printf("Comando log\n"); }
    ;

halt_stmt:
    HALT
    { printf("Comando halt\n"); }
    ;

break_stmt:
    BREAK
    { printf("Comando break\n"); }
    ;

continue_stmt:
    CONTINUE
    { printf("Comando continue\n"); }
    ;

block:
    LBRACE RBRACE
    { printf("Bloco vazio\n"); }
    | LBRACE block_content RBRACE
    { printf("Bloco\n"); }
    ;

block_content:
    declaration
    | statement
    | block_content declaration
    | block_content statement
    ;

/* --------------------- Expressões -------------------- */
expr:
    logic_or
    ;

logic_or:
    logic_and
    | logic_or OR logic_and
    ;

logic_and:
    equality
    | logic_and AND equality
    ;

equality:
    relation
    | equality EQ relation
    | equality NEQ relation
    ;

relation:
    additive
    | relation LT additive
    | relation LEQ additive
    | relation GT additive
    | relation GEQ additive
    ;

additive:
    multiplicative
    | additive PLUS multiplicative
    | additive MINUS multiplicative
    ;

multiplicative:
    unary
    | multiplicative MULT unary
    | multiplicative DIV unary
    | multiplicative MOD unary
    ;

unary:
    primary
    | NOT unary
    | MINUS unary %prec UMINUS
    ;

primary:
    NUMBER
    { printf("Número: %d\n", $1); }
    | STRING_LITERAL
    { printf("String: %s\n", $1); free($1); }
    | boolean
    | IDENTIFIER
    { printf("Identificador: %s\n", $1); free($1); }
    | sensor_ref
    | mem_ref
    | LPAREN expr RPAREN
    ;

boolean:
    TRUE
    { printf("Boolean: true\n"); }
    | FALSE
    { printf("Boolean: false\n"); }
    ;

/* --------------- Sensores / Atuadores / Mem ---------- */
sensor_ref:
    SENSOR DOT sensor_name
    { printf("Referência a sensor\n"); }
    ;

actuator_ref:
    ACT DOT actuator_name
    { printf("Referência a atuador\n"); }
    ;

mem_ref:
    MEM LBRACKET expr RBRACKET
    { printf("Referência à memória\n"); }
    ;

sensor_name:
    COIN
    | WATER_OK
    | BEANS_OK
    | CUP_DETECTED
    | TEMP
    | EMERGENCY
    ;

actuator_name:
    HEATER
    | PUMP
    | GRINDER
    | VALVE
    | DISPLAY_ACT
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, s);
}

int main(int argc, char** argv) {
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            perror("Erro ao abrir arquivo");
            return 1;
        }
        yyin = file;
    }
    
    printf("=== Iniciando análise léxica e sintática ===\n\n");
    
    int result = yyparse();
    
    if (result == 0) {
        printf("\n=== Análise concluída com sucesso! ===\n");
    } else {
        printf("\n=== Análise concluída com erros ===\n");
    }
    
    if (argc > 1) {
        fclose(yyin);
    }
    
    return result;
}