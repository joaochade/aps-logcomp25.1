%{
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
%}

%union {
    int num;
    double fnum;
    char *str;
}

%token RECIPE ROUTINE REQUIRES STEPS SET
%token COINS WATER BEANS CUP
%token GRIND HEAT BREW DISPENSE WAIT SHOW DO
%token CHECK OTHERWISE WHILE REPEAT TIMES FOR FROM TO STEP
%token ABORT SKIP EXIT
%token SENSE MEMORY
%token COFFEE STEAM MILK

%token SENSOR_COIN SENSOR_WATER SENSOR_BEANS SENSOR_CUP 
%token SENSOR_TEMP SENSOR_EMERGENCY

%token CELSIUS FAHRENHEIT ML SECONDS MILLISECONDS

%token AND OR NOT
%token EQ NE LE GE LT GT
%token PLUS MINUS MULT DIV MOD

%token ASSIGN SEMICOLON COMMA
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET

%token <num> NUMBER
%token <fnum> FLOAT
%token <str> STRING IDENTIFIER

%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left MULT DIV MOD
%right NOT UMINUS

%type <str> expression primary sensor_name liquid

%%

program:
    declarations
    ;

declarations:
    /* vazio */
    | declarations declaration
    ;

declaration:
    recipe_def
    | routine_def
    | var_decl
    ;

var_decl:
    SET IDENTIFIER ASSIGN expression SEMICOLON {
        emit("    ; Declaração de variável");
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $4);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", $2);
        emit(buffer);
        emit("");
    }
    ;

recipe_def:
    RECIPE IDENTIFIER requirements STEPS LBRACE statements RBRACE {
        emit("    ; Fim da receita");
        emit("    HALT");
        emit("");
    }
    | RECIPE IDENTIFIER STEPS LBRACE statements RBRACE {
        emit("    ; Fim da receita");
        emit("    HALT");
        emit("");
    }
    ;

requirements:
    REQUIRES requirement_list
    ;

requirement_list:
    requirement
    | requirement_list COMMA requirement
    ;

requirement:
    COINS NUMBER {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    ; Requer %d moedas", $2);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SENSOR COIN_INSERTED R0");
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %d", $2);
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JGE coins_ok");
        emit("    JMP error_insufficient_coins");
        emit("coins_ok:");
    }
    | WATER {
        emit("    ; Requer água");
        emit("    SENSOR WATER_LEVEL R0");
        emit("    SET R1 10");
        emit("    CMP R0 R1");
        emit("    JGE water_ok");
        emit("    JMP error_no_water");
        emit("water_ok:");
    }
    | BEANS {
        emit("    ; Requer grãos");
        emit("    SENSOR BEANS_LEVEL R0");
        emit("    SET R1 10");
        emit("    CMP R0 R1");
        emit("    JGE beans_ok");
        emit("    JMP error_no_beans");
        emit("beans_ok:");
    }
    | CUP {
        emit("    ; Requer copo");
        emit("    SENSOR CUP_PRESENT R0");
        emit("    SET R1 1");
        emit("    CMP R0 R1");
        emit("    JGE cup_ok");
        emit("    JMP error_no_cup");
        emit("cup_ok:");
    }
    ;

routine_def:
    ROUTINE IDENTIFIER LBRACE statements RBRACE {
        emit("    ; Fim da rotina");
        emit("    RET");
        emit("");
    }
    ;

statements:
    /* vazio */
    | statements statement
    ;

statement:
    assignment SEMICOLON
    | action SEMICOLON
    | conditional
    | loop
    | control_flow SEMICOLON
    | block
    ;

assignment:
    SET IDENTIFIER ASSIGN expression {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $4);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", $2);
        emit(buffer);
    }
    | SET MEMORY LBRACKET expression RBRACKET ASSIGN expression {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $7);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $4);
        emit(buffer);
        emit("    STORE_MEM R0 R1");
    }
    ;

block:
    LBRACE statements RBRACE
    ;

action:
    GRIND {
        emit("    ; Moer grãos");
        emit("    ACTUATOR GRINDER 1");
        emit("    SET R0 5000");
        emit("    WAIT R0");
        emit("    ACTUATOR GRINDER 0");
    }
    | GRIND FOR expression time_unit {
        char buffer[256];
        emit("    ; Moer grãos");
        emit("    ACTUATOR GRINDER 1");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $3);
        emit(buffer);
        emit("    WAIT R0");
        emit("    ACTUATOR GRINDER 0");
    }
    | HEAT TO expression {
        char buffer[256];
        emit("    ; Aquecer");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $3);
        emit(buffer);
        emit("    ACTUATOR HEATER R0");
    }
    | HEAT TO expression temp_unit {
        char buffer[256];
        emit("    ; Aquecer");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $3);
        emit(buffer);
        emit("    ACTUATOR HEATER R0");
    }
    | BREW {
        emit("    ; Fazer café");
        emit("    ACTUATOR PUMP 1");
        emit("    SET R0 25000");
        emit("    WAIT R0");
        emit("    ACTUATOR PUMP 0");
    }
    | BREW FOR expression time_unit {
        char buffer[256];
        emit("    ; Fazer café");
        emit("    ACTUATOR PUMP 1");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $3);
        emit(buffer);
        emit("    WAIT R0");
        emit("    ACTUATOR PUMP 0");
    }
    | DISPENSE liquid expression {
        char buffer[256];
        emit("    ; Dispensar líquido");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $3);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    ACTUATOR VALVE_%s R0", $2);
        emit(buffer);
    }
    | DISPENSE liquid expression volume_unit {
        char buffer[256];
        emit("    ; Dispensar líquido");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $3);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    ACTUATOR VALVE_%s R0", $2);
        emit(buffer);
    }
    | WAIT expression time_unit {
        char buffer[256];
        emit("    ; Esperar");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $2);
        emit(buffer);
        emit("    WAIT R0");
    }
    | SHOW expression {
        char buffer[256];
        emit("    ; Mostrar mensagem");
        snprintf(buffer, sizeof(buffer), "    DISPLAY %s", $2);
        emit(buffer);
    }
    | DO IDENTIFIER {
        char buffer[256];
        emit("    ; Chamar rotina");
        snprintf(buffer, sizeof(buffer), "    CALL %s", $2);
        emit(buffer);
    }
    ;

conditional:
    CHECK expression LBRACE statements RBRACE {
        char *label_end = new_label();
        char buffer[256];
        
        emit("    ; Condicional check");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $2);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    JZ R0 %s", label_end);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "%s:", label_end);
        emit(buffer);
    }
    | CHECK expression LBRACE statements RBRACE OTHERWISE LBRACE statements RBRACE {
        char *label_else = new_label();
        char *label_end = new_label();
        char buffer[256];
        
        emit("    ; Condicional check-otherwise");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $2);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    JZ R0 %s", label_else);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    JMP %s", label_end);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "%s:", label_else);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "%s:", label_end);
        emit(buffer);
    }
    ;

loop:
    WHILE expression LBRACE statements RBRACE {
        emit("    ; TODO: While loop - código pode estar fora de ordem");
    }
    | REPEAT expression TIMES LBRACE statements RBRACE {
        char buffer[256];
        emit("    ; Loop repeat");
        snprintf(buffer, sizeof(buffer), "    SET R2 %s", $2);
        emit(buffer);
        emit("    SET R3 0");
        emit("repeat_start:");
        emit("    CMP R3 R2");
        emit("    JGE repeat_end");
        emit("    ADD R3 1");
        emit("    JMP repeat_start");
        emit("repeat_end:");
    }
    | FOR IDENTIFIER FROM expression TO expression LBRACE statements RBRACE {
        char buffer[256];
        
        emit("    ; Loop for");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $4);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", $2);
        emit(buffer);
        emit("for_start:");
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", $2);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $6);
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JG for_end");
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", $2);
        emit(buffer);
        emit("    ADD R0 1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", $2);
        emit(buffer);
        emit("    JMP for_start");
        emit("for_end:");
    }
    | FOR IDENTIFIER FROM expression TO expression STEP expression LBRACE statements RBRACE {
        char buffer[256];
        
        emit("    ; Loop for com step");
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $4);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", $2);
        emit(buffer);
        emit("for_start:");
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", $2);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $6);
        emit(buffer);
        emit("    CMP R0 R1");
        emit("    JG for_end");
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", $2);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R2 %s", $8);
        emit(buffer);
        emit("    ADD R0 R2");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", $2);
        emit(buffer);
        emit("    JMP for_start");
        emit("for_end:");
    }
    ;

control_flow:
    ABORT {
        emit("    ; Abortar");
        emit("    HALT");
    }
    | ABORT expression {
        char buffer[256];
        emit("    ; Abortar com mensagem");
        snprintf(buffer, sizeof(buffer), "    DISPLAY %s", $2);
        emit(buffer);
        emit("    HALT");
    }
    | EXIT {
        emit("    ; Exit (break)");
        emit("    JMP loop_end");
    }
    | SKIP {
        emit("    ; Skip (continue)");
        emit("    JMP loop_start");
    }
    ;

expression:
    expression OR expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
        emit(buffer);
        emit("    OR R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        $$ = result;
    }
    | expression AND expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
        emit(buffer);
        emit("    AND R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        $$ = result;
    }
    | expression EQ expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
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
        $$ = result;
    }
    | expression NE expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
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
        $$ = result;
    }
    | expression LT expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
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
        $$ = result;
    }
    | expression GT expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
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
        $$ = result;
    }
    | expression LE expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
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
        $$ = result;
    }
    | expression GE expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
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
        $$ = result;
    }
    | expression PLUS expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
        emit(buffer);
        emit("    ADD R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        $$ = result;
    }
    | expression MINUS expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
        emit(buffer);
        emit("    SUB R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        $$ = result;
    }
    | expression MULT expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
        emit(buffer);
        emit("    MUL R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        $$ = result;
    }
    | expression DIV expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
        emit(buffer);
        emit("    DIV R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        $$ = result;
    }
    | expression MOD expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
        emit(buffer);
        emit("    MOD R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        $$ = result;
    }
    | NOT expression {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $2);
        emit(buffer);
        emit("    NOT R0");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        $$ = result;
    }
    | MINUS expression %prec UMINUS {
        char *result = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R0 %s", $2);
        emit(buffer);
        emit("    NEG R0");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", result);
        emit(buffer);
        $$ = result;
    }
    | primary {
        $$ = $1;
    }
    ;

primary:
    NUMBER {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%d", $1);
        $$ = strdup(buffer);
    }
    | FLOAT {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%.2f", $1);
        $$ = strdup(buffer);
    }
    | STRING {
        $$ = $1;
    }
    | IDENTIFIER {
        char *temp = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    LOAD R0 %s", $1);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", temp);
        emit(buffer);
        $$ = temp;
    }
    | SENSE sensor_name {
        char *temp = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SENSOR %s R0", $2);
        emit(buffer);
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", temp);
        emit(buffer);
        $$ = temp;
    }
    | MEMORY LBRACKET expression RBRACKET {
        char *temp = new_temp();
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "    SET R1 %s", $3);
        emit(buffer);
        emit("    LOAD_MEM R0 R1");
        snprintf(buffer, sizeof(buffer), "    STORE R0 %s", temp);
        emit(buffer);
        $$ = temp;
    }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
    ;

sensor_name:
    SENSOR_COIN { $$ = strdup("COIN_INSERTED"); }
    | SENSOR_WATER { $$ = strdup("WATER_LEVEL"); }
    | SENSOR_BEANS { $$ = strdup("BEANS_LEVEL"); }
    | SENSOR_CUP { $$ = strdup("CUP_PRESENT"); }
    | SENSOR_TEMP { $$ = strdup("CURRENT_TEMP"); }
    | SENSOR_EMERGENCY { $$ = strdup("EMERGENCY"); }
    ;

liquid:
    WATER { $$ = strdup("WATER"); }
    | COFFEE { $$ = strdup("COFFEE"); }
    | STEAM { $$ = strdup("STEAM"); }
    | MILK { $$ = strdup("MILK"); }
    ;

temp_unit:
    CELSIUS
    | FAHRENHEIT
    ;

time_unit:
    SECONDS
    | MILLISECONDS
    ;

volume_unit:
    ML
    ;

%%

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