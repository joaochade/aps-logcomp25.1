# aps-logcomp25.1

## Descrição:
Linguagem de programação de alto nível criada para controlar a CoffeeVM, uma máquina virtual que simula o funcionamento de uma cafeteira automática.

## EBNF
```program         = { declaration | statement } EOF ;

(* -------------------- Declarações -------------------- *)
declaration     = const_decl | var_decl | proc_decl ;

const_decl      = "const" identifier "->" type "=" expr ";" ;
var_decl        = "let"   identifier [ "->" type ] [ "=" expr ] ";" ;

proc_decl       = "proc" identifier "(" [ param_list ] ")" block ;
param_list      = param { "," param } ;
param           = identifier "->" type ;

(* ----------------------- Tipos ----------------------- *)
type            = "int" | "bool" | "string" ;

(* ---------------------- Comandos --------------------- *)
statement       = assign_stmt ";"
                | io_stmt ";"
                | if_stmt
                | while_stmt
                | repeat_stmt
                | call_stmt ";"
                | log_stmt ";"
                | halt_stmt ";"
                | break_stmt ";"
                | continue_stmt ";"
                | block ;

assign_stmt     = lvalue "=" expr ;
lvalue          = identifier | mem_ref | actuator_ref ;

io_stmt         = "display" "(" display_arg ")"
                | "clear" "." "DISPLAY" ;
display_arg     = expr ;

if_stmt         = "if" "(" expr ")" block [ "else" block ] ;
while_stmt      = "while" "(" expr ")" block ;
repeat_stmt     = "repeat" block "until" "(" expr ")" ";" ;

call_stmt       = "call" identifier "(" [ arg_list ] ")" ;
arg_list        = expr { "," expr } ;

log_stmt        = "log" "(" expr ")" ;
halt_stmt       = "halt" ;
break_stmt      = "break" ;
continue_stmt   = "continue" ;

block           = "{" { declaration | statement } "}" ;

(* --------------------- Expressões -------------------- *)
expr            = logic_or ;

logic_or        = logic_and { "or"  logic_and } ;
logic_and       = equality  { "and" equality  } ;

equality        = relation { ( "==" | "!=" ) relation } ;
relation        = additive { ( "<" | "<=" | ">" | ">=" ) additive } ;

additive        = multiplicative { ( "+" | "-" ) multiplicative } ;
multiplicative  = unary          { ( "*" | "/" | "%" ) unary } ;

unary           = ( "!" | "-" ) unary | primary ;

primary         = number
                | string
                | boolean
                | identifier
                | sensor_ref
                | mem_ref
                | "(" expr ")" ;

(* --------------- Sensores / Atuadores / Mem ---------- *)
sensor_ref      = "_SENSOR" "." sensor_name ;    (* somente leitura *)
actuator_ref    = "_ACT"    "." actuator_name ;  (* escrita/leitura *)
mem_ref         = "_MEM"    "[" expr "]" ;       (* RAM indexada 0..N *)

sensor_name     = "COIN" | "WATER_OK" | "BEANS_OK" | "CUP_DETECTED"
                | "TEMP" | "EMERGENCY" ;

actuator_name   = "HEATER" | "PUMP" | "GRINDER" | "VALVE" | "DISPLAY" ;

(* ----------------- Léxico / Tokens base --------------- *)
number          = digit { digit } ;
string          = "\"" { character - "\"" } "\"" ;
boolean         = "true" | "false" ;

identifier      = letter { letter | digit | "_" } ;
letter          = "A"…"Z" | "a"…"z" ;
digit           = "0"…"9" ;
character       = ? qualquer caractere Unicode ? ;
