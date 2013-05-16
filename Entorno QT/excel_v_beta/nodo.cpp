#include "nodo.h"

nodo::nodo()
{

}
inline T nodo::get_nodo_valor()
{
    return nodo_valor;
}
inline coord nodo::get_nodo_f()
{
    return nodo_f;
}
coord nodo::get_nodo_c()
{
    return nodo_c;
}

 /*funciones para dar nuevos valores a las variables de los nodos*/

void nodo::set_nodo_f(coord fila)
{
    nodo_f = fila;
}
void nodo::set_nodo_c(coord columna)
{
    nodo_c = columna;
}
void nodo::set_nodo_valor(T elem)
{
    nodo_valor = elem;
}



