#include "operacion.h"

/*Evalua una operacion en la cadena de la funcion*/
T operacion::get_value()
{
    T valor_a, valor_b;
    if(pleft!=NULL)
        valor_a = pleft->get_value(); /*extrae el valor al que apunta pleft*/
    else
        valor_a = 0;
    if(pright!=NULL)
        valor_b = pright->get_value();/*extrae el valor al que apunta pright*/
    else
        valor_b = 0;
    return (*funcion)(valor_a, valor_b); /*Devuelve T al efectuar la funcion*/
}


