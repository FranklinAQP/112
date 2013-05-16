#ifndef _OPERACION_H_
#define _OPERACION_H_
#include "expresion.h"
class operacion : public expresion
{
private:
    expresion *pleft,*pright;
    fnptr funcion;
public:
    operacion();
    T get_value(){
        T a = pleft->get_value();
        T b = pright->get_value();
        return (*funcion)(a,b);
    }
};

#endif // _OPERACION_H_
