# aps-logcomp25.1

## Descrição:
Linguagem de programação de alto nível criada para controlar a CoffeeVM, uma máquina virtual que simula o funcionamento de uma cafeteira automática.

## EBNF
(* ============================================================
   CoffeeLang - Linguagem de Programação para Máquina de Café
   Com variáveis, condicionais e loops
   ============================================================ *)

program = { declaration } ;

(* -------------------- Declarações -------------------- *)
declaration = recipe_def
            | routine_def
            | var_decl ;

var_decl = "set" identifier "=" expression ";" ;

(* -------------------- Definição de Receitas -------------------- *)
recipe_def = "recipe" identifier 
             [ "requires" requirements ]
             "steps" "{" { statement } "}" ;

requirements = requirement { "," requirement } ;
requirement  = "coins" number
             | "water" 
             | "beans"
             | "cup" ;

(* ---------------------- Rotinas Reutilizáveis ------------------ *)
routine_def = "routine" identifier 
              "{" { statement } "}" ;

(* ----------------------- Comandos (Statements) ----------------- *)
statement = assignment ";"
          | action ";"
          | conditional
          | loop
          | control_flow ";"
          | block ;

assignment = "set" identifier "=" expression ;

block = "{" { statement } "}" ;

(* ----------------------- Ações da Máquina ---------------------- *)
action = grind_action
       | heat_action
       | brew_action
       | dispense_action
       | wait_action
       | message_action
       | call_routine ;

grind_action    = "grind" [ "for" expression time_unit ] ;
heat_action     = "heat" "to" expression [ temp_unit ] ;
brew_action     = "brew" [ "for" expression time_unit ] ;
dispense_action = "dispense" liquid expression [ volume_unit ] ;
wait_action     = "wait" expression time_unit ;
message_action  = "show" expression ;
call_routine    = "do" identifier ;

(* ----------------------- Estruturas de Controle ---------------- *)
conditional = "check" expression 
              "{" { statement } "}" 
              [ "otherwise" "{" { statement } "}" ] ;

loop = while_loop | repeat_loop | for_loop ;

while_loop  = "while" expression 
              "{" { statement } "}" ;

repeat_loop = "repeat" expression "times"
              "{" { statement } "}" ;

for_loop    = "for" identifier "from" expression "to" expression 
              [ "step" expression ]
              "{" { statement } "}" ;

control_flow = "abort" [ expression ]
             | "skip"        (* continue *)
             | "exit" ;      (* break *)

(* ----------------------- Expressões ---------------------------- *)
expression = logic_or ;

logic_or   = logic_and { "or" logic_and } ;
logic_and  = equality { "and" equality } ;
equality   = comparison { ( "==" | "!=" ) comparison } ;
comparison = additive { ( ">" | "<" | ">=" | "<=" ) additive } ;
additive   = multiplicative { ( "+" | "-" ) multiplicative } ;
multiplicative = unary { ( "*" | "/" | "%" ) unary } ;
unary      = [ "not" | "-" ] primary ;

primary = number
        | string
        | identifier
        | sensor_access
        | memory_access
        | "(" expression ")" ;

(* ----------------------- Acesso a Hardware --------------------- *)
sensor_access = "sense" sensor_name ;

memory_access = "memory" "[" expression "]" ;

sensor_name = "coin_inserted"
            | "water_level"
            | "beans_level"
            | "cup_present"
            | "current_temp"
            | "emergency" ;

(* ----------------------- Unidades ------------------------------ *)
temp_unit   = "°C" | "°F" ;
time_unit   = "s" | "ms" ;
volume_unit = "ml" ;
liquid      = "water" | "coffee" | "steam" | "milk" ;

(* ---------------------- Tokens Básicos ------------------------- *)
identifier = letter { letter | digit | "_" } ;
number     = digit { digit } [ "." digit { digit } ] ;
string     = "\"" { character - "\"" } "\"" ;

letter     = "a"…"z" | "A"…"Z" ;
digit      = "0"…"9" ;
character  = ? qualquer caractere imprimível ? ;