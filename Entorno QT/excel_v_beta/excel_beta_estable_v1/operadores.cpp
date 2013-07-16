#include "operadores.h"

all_operators_::all_operators_()
{
    Func mis_operadores[5]={"+","-","*","/","SIN"};
    fnptr mis_funciones[5]= {&sumab,&resb,&multb,&divb,&sint};/*Agregar nueva funcion aqui*/
    for(int i=0; i<5; ++i){
        symbols_operators[i]=mis_operadores[i];/*Agregar nuevo simbolo aqui*/
        allfunction[i]=mis_funciones[i];
    }
    n_operators = sizeof(symbols_operators)/sizeof(symbols_operators[0]);
}


    /*retorna la direccion de la funcion requerida dependiendo del simbolo del operador(Func)*/
    fnptr all_operators_::what_function(Func op){/*retorna la direccion de la funcion requerida dependiendo del simbolo del operador(Func)*/
        for(register int i=0; i<n_operators;++i)
            if(op==symbols_operators[i])
                return allfunction[i];
    }

    /*Retorna el operador de acuerdo al orden de prioridad de mmenor(cerca a 0) a mayor(mas alejado)*/
    Func all_operators_::operator_priority(size_t _N)/*usado en stx.h y .cpp*/
    {
        return symbols_operators[_N];
    }

