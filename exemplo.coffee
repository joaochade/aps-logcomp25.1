// Exemplo de programa CoffeeLang
// Este programa faz um espresso simples

set max_temp = 95;
set coffee_count = 0;

recipe SimpleEspresso requires coins 2, water, beans, cup steps {
    show "Preparing espresso...";
    
    grind for 5000 ms;
    heat to 93 °C;
    brew for 25000 ms;
    dispense coffee 30 ml;
    
    set coffee_count = coffee_count + 1;
    show "Espresso ready!";
}

routine CleaningCycle {
    show "Starting cleaning...";
    
    for cycle from 1 to 3 {
        dispense water 50 ml;
        wait 2000 ms;
    };
    
    show "Cleaning complete";
}

recipe TripleShot requires coins 5, water, beans, cup steps {
    set shots = 3;
    
    repeat shots times {
        grind for 5000 ms;
        heat to 92 °C;
        brew for 20000 ms;
        wait 2000 ms;
    };
    
    dispense coffee 90 ml;
    show "Triple shot ready!";
}