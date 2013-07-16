#ifndef _OPERADORES_H_
#define _OPERADORES_H_
//#include "operacion.h"
#include "tipos.h"
#include <math.h>

namespace all_operators_
{
    T sumab(T a,T b){/*Funcion suma binaria*/
        return a+b;
    }
    T resb(T a,T b){/*Funcion resta binaria*/
        return a-b;
    }
    T multb(T a,T b){/*Funcion multiplicacion binaria*/
        return a*b;
    }
    T divb(T a,T b){/*Funcion division binaria*/
        return a/b;
    }
    T sint(T a,T ){/*Funcion seno*/
        return sin(a);
    }
    T none(T a,T ){/*Funcion que no ejecuta nada, su uso puede eliminarse*/
        return a;
    }
/*    Func symbols_operators[5];
    fnptr allfunction[5];
    int n_operators;
    fnptr what_function(Func op);
    Func operator_priority(size_t _N);
    */
    static Func symbols_operators[]={"+","-","*","/","SIN"};/*Agregar nuevo simbolo aqui*/
    static fnptr allfunction[] = {&sumab,&resb,&multb,&divb,&sint};/*Agregar nueva funcion aqui*/
    static int n_operators = sizeof(symbols_operators)/sizeof(symbols_operators[0]);
    /*retorna la direccion de la funcion requerida dependiendo del simbolo del operador(Func)*/
    static fnptr what_function(Func op){/*retorna la direccion de la funcion requerida dependiendo del simbolo del operador(Func)*/
        for(register int i=0; i<n_operators;++i)
            if(op==symbols_operators[i])
                return allfunction[i];
    }
    /*Retorna el operador de acuerdo al orden de prioridad de mmenor(cerca a 0) a mayor(mas alejado)*/
    static Func operator_priority(size_t _N)/*usado en stx.h y .cpp*/
    {
        return symbols_operators[_N];
    }

}
#endif // _OPERADORES_H_
