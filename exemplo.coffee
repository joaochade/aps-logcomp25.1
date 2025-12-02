// Exemplo de programa CoffeeLang
// Este programa faz um espresso simples

set max_temp = 95;
set coffee_count = 0;

recipe Espresso requires coins 2, water, beans, cup steps {
    show "Preparing espresso...";
    
    // Verifica se há copo
    check sense cup_present {
        // Moer grãos
        grind for 5 s;
        
        // Aquecer água
        heat to 93 °C;
        
        // Aguarda temperatura ideal
        while sense current_temp < 90 {
            wait 500 ms;
        };
        
        // Fazer café
        brew for 25 s;
        dispense coffee 30 ml;
        
        // Incrementa contador
        set coffee_count = coffee_count + 1;
        show "Espresso ready!";
    } otherwise {
        show "Please insert cup";
        abort;
    };
}

// Rotina de limpeza
routine CleaningCycle {
    show "Starting cleaning...";
    
    for cycle from 1 to 3 {
        dispense water 50 ml;
        wait 2 s;
    };
    
    show "Cleaning complete";
}

// Receita com múltiplos shots
recipe TripleShot requires coins 5, water, beans, cup steps {
    set shots = 3;
    
    repeat shots times {
        grind for 5 s;
        heat to 92 °C;
        brew for 20 s;
        wait 2 s;
    };
    
    dispense coffee 90 ml;
    show "Triple shot ready!";
}