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
    JL error_insufficient_coins
    ; Requer água
    SENSOR WATER_LEVEL R0
    JZ R0 error_no_water
    ; Requer grãos
    SENSOR BEANS_LEVEL R0
    JZ R0 error_no_beans
    ; Requer copo
    SENSOR CUP_PRESENT R0
    JZ R0 error_no_cup
    ; Mostrar mensagem
    DISPLAY "Preparing espresso..."
    SENSOR CUP_PRESENT R0
    ; Moer grãos
    ACTUATOR GRINDER 1
    SET R0 5
    WAIT R0
    ACTUATOR GRINDER 0
    ; Aquecer
    SET R0 93
    ACTUATOR HEATER R0
    SENSOR CURRENT_TEMP R0
    SET R0 R0
    SET R1 90
    CMP R0 R1
    JL temp_true
    SET R0 0
    JMP temp_end
temp_true:
    SET R0 1
temp_end:
    STORE R0 T5
    ; Esperar
    SET R0 500
    WAIT R0
    ; Loop while
L0:
    SET R0 T5
    JZ R0 L1
    JMP L0
L1:
