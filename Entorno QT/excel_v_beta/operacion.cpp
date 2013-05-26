#include "operacion.h"

/*Evalua una operacion en la cadena de la funcion*/
T operacion::get_value()
{
    T valor_a = pleft->get_value(); /*extrae el valor al que apunta pleft*/
    T valor_b = pright->get_value();/*extrae el valor al que apunta pright*/
    return (*funcion)(valor_a, valor_b); /*Devuelve T al efectuar la funcion*/
}


