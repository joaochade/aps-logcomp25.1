; CoffeeLang Assembly Output
; Gerado automaticamente

    ; Declaração de variável
    SET R0 95
    STORE R0 max_temp

    ; Declaração de variável
    SET R0 0
    STORE R0 coffee_count

    ; Requer 2 moedas
    SENSOR COIN_INSERTED R0
    SET R1 2
    CMP R0 R1
    JGE coins_ok
    JMP error_insufficient_coins
coins_ok:
    ; Requer água
    SENSOR WATER_LEVEL R0
    SET R1 10
    CMP R0 R1
    JGE water_ok
    JMP error_no_water
water_ok:
    ; Requer grãos
    SENSOR BEANS_LEVEL R0
    SET R1 10
    CMP R0 R1
    JGE beans_ok
    JMP error_no_beans
beans_ok:
    ; Requer copo
    SENSOR CUP_PRESENT R0
    SET R1 1
    CMP R0 R1
    JGE cup_ok
    JMP error_no_cup
cup_ok:
    ; Mostrar mensagem
    DISPLAY "Preparing espresso..."
    ; Moer grãos
    ACTUATOR GRINDER 1
    SET R0 5000
    WAIT R0
    ACTUATOR GRINDER 0
    ; Aquecer
    SET R0 93
    ACTUATOR HEATER R0
    ; Fazer café
    ACTUATOR PUMP 1
    SET R0 25000
    WAIT R0
    ACTUATOR PUMP 0
    ; Dispensar líquido
    SET R0 30
    ACTUATOR VALVE_COFFEE R0
    LOAD R0 coffee_count
    STORE R0 T0
    SET R0 T0
    SET R1 1
    ADD R0 R1
    STORE R0 T1
    SET R0 T1
    STORE R0 coffee_count
    ; Mostrar mensagem
    DISPLAY "Espresso ready!"
    ; Fim da receita
    HALT

    ; Mostrar mensagem
    DISPLAY "Starting cleaning..."
    ; Dispensar líquido
    SET R0 50
    ACTUATOR VALVE_WATER R0
    ; Esperar
    SET R0 2000
    WAIT R0
    ; Loop for
    SET R0 1
    STORE R0 cycle
for_start:
    LOAD R0 cycle
    SET R1 3
    CMP R0 R1
    JG for_end
    LOAD R0 cycle
    ADD R0 1
    STORE R0 cycle
    JMP for_start
for_end:

; Labels de erro
error_insufficient_coins:
    DISPLAY "Erro: Moedas insuficientes"
    HALT

error_no_water:
    DISPLAY "Erro: Sem água"
    HALT

error_no_beans:
    DISPLAY "Erro: Sem grãos"
    HALT

error_no_cup:
    DISPLAY "Erro: Sem copo"
    HALT
