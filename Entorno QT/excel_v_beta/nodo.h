#ifndef _NODO_H_
#define _NODO_H_
#include <vector>
#include "expresion.h"

class nodo   /* clase nodo aun no terminada */
{
    //friend class matrix;

private:
    T nodo_valor; /*variable que almacena el valor*/
    Func my_funcion; /*variable que almacena en string(Func) la funcion*/
    expresion *ptrexp;/*puntero a expresion que es una clase padre y nos permite navegar a las clases hijas*/
    vector <nodo*> ptrdependencies;/*vector de punteros para manejar dependencias*/

public:
    nodo(); /*Constructor*/
    virtual ~nodo(); /*Destructor Virtual*/
    inline T get_value(){return nodo_valor;}/*devuelve el valor de variable nodo_valor*/
    virtual void set_value(T elem); /*Insertar un nuevo elemento*/
};

typedef vector<nodo> my_row; /*defino variable de una fila de nodos como un vector*/
typedef nodo* nodoptr;/*defino variable de un puntero a nodo*/


#endif // NODO_H
