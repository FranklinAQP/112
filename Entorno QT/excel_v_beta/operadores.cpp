#include "operadores.h"


T all_operators::sumab(T a,T b){/*Funcion suma binaria*/
    return a+b;
}
T all_operators::resb(T a,T b){/*Funcion resta binaria*/
    return a-b;
}
T all_operators::multb(T a,T b){/*Funcion multiplicacion binaria*/
    return a*b;
}
T all_operators::divb(T a,T b){/*Funcion division binaria*/
    return a/b;
}
T all_operators::sin(T a,T ){/*Funcion seno*/
    return ::sin(a);
}
T all_operators::none(T a,T ){/*Funcion que no ejecuta nada, su uso puede eliminarse*/
    return a;
}

/*Lista de simbolos utilizados como operadores*/
//Func operators::symbols_operators[]={"+","-","*","/","SIN"};/*Agregar nuevo simbolo aqui*/

/*Definimos el puntero general a todas las funciones existentes las que estan en un array*/
//fnptr operators::allfunction[] = {&sumab,&resb,&multb,&divb,&sin};/*Agregar nueva funcion aqui*/


/*retorna la direccion de la funcion requerida dependiendo del simbolo del operador(Func)*/
fnptr all_operators::what_function(Func op)
{
    for(register int i=0; i<5;++i)
        if(op==symbols_operators[i])
            return allfunction[i];
}

/*Retorna el operador de acuerdo al orden de prioridad de mmenor(cerca a 0) a mayor(mas alejado)*/
Func all_operators::operator_priority(size_t N)/*usado en stx.h y .cpp*/
{
    return symbols_operators[N];
}
