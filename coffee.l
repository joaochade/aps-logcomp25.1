%{
#include <stdio.h>
#include <string.h>
#include "coffee.tab.h"

int line_num = 1;
%}

%option noyywrap

%%

 /* Palavras-chave - Declarações */
"recipe"            { return RECIPE; }
"routine"           { return ROUTINE; }
"requires"          { return REQUIRES; }
"steps"             { return STEPS; }
"set"               { return SET; }

 /* Palavras-chave - Requisitos */
"coins"             { return COINS; }
"water"             { return WATER; }
"beans"             { return BEANS; }
"cup"               { return CUP; }

 /* Palavras-chave - Ações */
"grind"             { return GRIND; }
"heat"              { return HEAT; }
"brew"              { return BREW; }
"dispense"          { return DISPENSE; }
"wait"              { return WAIT; }
"show"              { return SHOW; }
"do"                { return DO; }

 /* Palavras-chave - Controle de Fluxo */
"check"             { return CHECK; }
"otherwise"         { return OTHERWISE; }
"while"             { return WHILE; }
"repeat"            { return REPEAT; }
"times"             { return TIMES; }
"for"               { return FOR; }
"from"              { return FROM; }
"to"                { return TO; }
"step"              { return STEP; }
"abort"             { return ABORT; }
"skip"              { return SKIP; }
"exit"              { return EXIT; }

 /* Palavras-chave - Sensores */
"sense"             { return SENSE; }
"memory"            { return MEMORY; }
"coin_inserted"     { return SENSOR_COIN; }
"water_level"       { return SENSOR_WATER; }
"beans_level"       { return SENSOR_BEANS; }
"cup_present"       { return SENSOR_CUP; }
"current_temp"      { return SENSOR_TEMP; }
"emergency"         { return SENSOR_EMERGENCY; }

 /* Líquidos */
"coffee"            { return COFFEE; }
"steam"             { return STEAM; }
"milk"              { return MILK; }

 /* Unidades */
"°C"                { return CELSIUS; }
"°F"                { return FAHRENHEIT; }
"ml"                { return ML; }
"s"                 { return SECONDS; }
"ms"                { return MILLISECONDS; }

 /* Operadores Lógicos */
"and"               { return AND; }
"or"                { return OR; }
"not"               { return NOT; }

 /* Operadores Relacionais */
"=="                { return EQ; }
"!="                { return NE; }
"<="                { return LE; }
">="                { return GE; }
"<"                 { return LT; }
">"                 { return GT; }

 /* Operadores Aritméticos */
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULT; }
"/"                 { return DIV; }
"%"                 { return MOD; }

 /* Delimitadores */
"="                 { return ASSIGN; }
";"                 { return SEMICOLON; }
","                 { return COMMA; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }

 /* Números */
[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }
[0-9]+"."[0-9]+     { yylval.fnum = atof(yytext); return FLOAT; }

 /* Strings */
\"([^\\\"]|\\.)*\"  { 
    yylval.str = strdup(yytext); 
    return STRING; 
}

 /* Identificadores */
[a-zA-Z_][a-zA-Z0-9_]* { 
    yylval.str = strdup(yytext); 
    return IDENTIFIER; 
}

 /* Comentários */
"//".*              { /* ignora comentários de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* ignora comentários de bloco */ }

 /* Whitespace */
[ \t]+              { /* ignora espaços e tabs */ }
"\n"                { line_num++; }
"\r\n"              { line_num++; }

 /* Caracteres inválidos */
.                   { 
    fprintf(stderr, "Erro léxico na linha %d: caractere inválido '%s'\n", 
            line_num, yytext); 
}

%%