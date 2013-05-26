#ifndef _NODO_CELDA_H
#define _NODO_CELDA_H
#include "nodo.h"
#include "matrix.h"

/* clase que ayuda a manejar dependencias conecta con el nodo para sacar su valor*/
class nodocelda : public expresion
{
private:
        nodoptr pnodo;/*Variable puntero a nodo*/
public:
        nodocelda(nodoptr _pnodo): pnodo(_pnodo){}/*Constructor*/
        nodocelda(class matrix* matrixptr, Func celda);/*Constructor segun su direccion en Func(string)*/
        virtual ~nodocelda();/*Destructor Virtual*/
        void address(class matrix* matrixptr, Func celda);/*puntero segun su direccion en Func(string)*/
        T get_value(){return pnodo->get_value();}/*obtiene el valor del nodo apuntado*/
};

#endif // _NODO_CELDA_H

