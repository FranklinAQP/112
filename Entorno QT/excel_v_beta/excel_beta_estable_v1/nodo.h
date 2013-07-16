#ifndef _NODO_H_
#define _NODO_H_
#include <vector>
#include "expresion.h"
#include "stx.h"

class nodo   /* clase nodo aun no terminada */
{
    //friend class matrix;

private:
    T nodo_valor; /*variable que almacena el valor*/
    Func my_funcion; /*variable que almacena en string(Func) la funcion*/
    expresion *ptrexp;/*puntero a expresion que es una clase padre y nos permite navegar a las clases hijas*/
    vector <nodo*> ptrdependencies;/*vector de punteros a los nodos que dependen de este para manejar dependencias*/
public:
    nodo(); /*Constructor*/
    virtual ~nodo(); /*Destructor Virtual*/
    inline T get_value(){return nodo_valor;}/*devuelve el valor de variable nodo_valor*/
    virtual void set_value(T elem); /*Insertar un nuevo elemento*/
    inline void set_my_function(Func _my_funcion){my_funcion = _my_funcion;} /*Insertar un nuevo elemento*/
    inline Func get_my_function(){return my_funcion;}
    void set_ptrdependencies(nodo* ptr_nodo);/*Inserta un puntero a nodo en el vector de dependencias*/
    void erase_ptrdependencies(nodo* ptr_nodo);/*Elimina un vector a nodo en el vector de dependencias*/
};

typedef vector<nodo> my_row; /*defino variable de una fila de nodos como un vector*/
typedef nodo* nodoptr;/*defino variable de un puntero a nodo*/


#endif // NODO_H
