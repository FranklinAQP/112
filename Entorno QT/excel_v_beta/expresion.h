#ifndef _EXPRESION_H_
#define _EXPRESION_H_
#include "tipos.h"

/**Esta clase heredara a constante.h operacion.h y nodocelda.h**/
class expresion
{
public:
    expresion();/*Constructor*/
    virtual ~expresion();/*Destructor Virtual*/
    virtual T get_value() =0;/*Funcion Virtual Pura que convierte a la clase en abstracta*/
};


#endif // _EXPRESION_H_
