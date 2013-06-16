#ifndef _CONSTANTE_H
#define _CONSTANTE_H
#include "nodo.h"
/* Clase constante hereda de clase expresion */
class constante: public expresion
{
private:
    T nodo_valor; /*variable valor del nodo*/
public:
    constante(T _constante) : nodo_valor(_constante) {} /*Constructor*/
    constante(Func numero);/*Alternativa de Constructor*/
    virtual ~constante(); /*Destructor virtual*/
    inline T get_value(){return nodo_valor;}/*retorna el valor de la variable*/
    inline void set_value(T new_valor){ nodo_valor=new_valor;}/*cambia valor*/
};

#endif // _CONSTANTE_H
