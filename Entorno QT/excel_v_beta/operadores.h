#ifndef _OPERADORES_H_
#define _OPERADORES_H_
#include "operacion.h"
#include <math.h>

namespace all_operators{
    T sumab(T a,T b);
    T resb(T a,T b);
    T multb(T a,T b);
    T divb(T a,T b);
    T sin(T a,T );
    T none(T a,T );
    Func symbols_operators[]={"+","-","*","/","SIN"};/*Agregar nuevo simbolo aqui*/
    fnptr allfunction[] = {&sumab,&resb,&multb,&divb,&sin};/*Agregar nueva funcion aqui*/
    fnptr what_function(Func op);/*retorna la direccion de la funcion requerida dependiendo del simbolo del operador(Func)*/
    Func operator_priority(size_t N);/*usado en stx.h y .cpp*/
}
#endif // _OPERADORES_H_
