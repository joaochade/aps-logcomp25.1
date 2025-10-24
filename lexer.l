%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
%}

%option noyywrap
%option yylineno
%option nounput
%option noinput

%%

    /* Palavras reservadas */
"const"         { return CONST; }
"let"           { return LET; }
"proc"          { return PROC; }
"int"           { return INT; }
"bool"          { return BOOL; }
"string"        { return STRING; }
"display"       { return DISPLAY; }
"clear"         { return CLEAR; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"repeat"        { return REPEAT; }
"until"         { return UNTIL; }
"call"          { return CALL; }
"log"           { return LOG; }
"halt"          { return HALT; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"true"          { return TRUE; }
"false"         { return FALSE; }
"or"            { return OR; }
"and"           { return AND; }

    /* Sensores e Atuadores */
"_SENSOR"       { return SENSOR; }
"_ACT"          { return ACT; }
"_MEM"          { return MEM; }
"COIN"          { return COIN; }
"WATER_OK"      { return WATER_OK; }
"BEANS_OK"      { return BEANS_OK; }
"CUP_DETECTED"  { return CUP_DETECTED; }
"TEMP"          { return TEMP; }
"EMERGENCY"     { return EMERGENCY; }
"HEATER"        { return HEATER; }
"PUMP"          { return PUMP; }
"GRINDER"       { return GRINDER; }
"VALVE"         { return VALVE; }
"DISPLAY"       { return DISPLAY_ACT; }

    /* Operadores e pontuação */
"->"            { return ARROW; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LEQ; }
">="            { return GEQ; }
"<"             { return LT; }
">"             { return GT; }
"="             { return ASSIGN; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULT; }
"/"             { return DIV; }
"%"             { return MOD; }
"!"             { return NOT; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"."             { return DOT; }

    /* Identificadores */
[a-zA-Z][a-zA-Z0-9_]* { 
    yylval.str = strdup(yytext); 
    return IDENTIFIER; 
}

    /* Números */
[0-9]+          { 
    yylval.num = atoi(yytext); 
    return NUMBER; 
}

    /* Strings */
\"([^\\\"]|\\.)*\" { 
    yylval.str = strdup(yytext); 
    return STRING_LITERAL; 
}

    /* Comentários */
"//".*          { /* ignorar comentários de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* ignorar comentários de bloco */ }

    /* Whitespace */
[ \t\r]+        { /* ignorar espaços */ }
\n              { /* yylineno é incrementado automaticamente */ }

    /* Erro */
.               { 
    fprintf(stderr, "Erro léxico na linha %d: caractere inesperado '%s'\n", 
            yylineno, yytext); 
}

%%