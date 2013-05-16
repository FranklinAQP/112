#ifndef _NODO_CELDA_H
#define _NODO_CELDA_H
#include "expresion.h"

class nodocelda : public expresion   /* clase celda aun no terminada */
{
private:
        nodocelda* pcelda;
public:
        nodocelda();
        ~nodocelda();
        virtual T get_value(){return pcelda->get_value();}
};



#endif // _NODO_CELDA_H
