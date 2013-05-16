#ifndef _EXPRESION_H_
#define _EXPRESION_H_
#include "nodo.h"
class expresion
{
public:
    expresion();
    virtual ~expresion();
    virtual T get_value() =0;
};
typedef T (*fnptr)(T,T);
#endif // _EXPRESION_H_
