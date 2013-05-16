#ifndef _NODO_H_
#define _NODO_H_
#include <vector>
#include "tipos.h"


using namespace std;

class nodo   /* clase nodo aun no terminada */
{
    friend class matrix;
    friend class constante;
protected:
    T nodo_valor; //valor del nodo es interno opsss
    Func my_funcion;
    coord nodo_f; // fila actual
    coord nodo_c; // columna actual
  //   T (*funciones)(T*, T*); //puntero a funciones

public:
    nodo(); // Constructor
    //nodo *proxh=NULL;
    //nodo *proxv=NULL;
    /* funciones que devuelven el valor de variables publicas y privadas */
    T get_nodo_valor();
    virtual coord get_nodo_f();
    virtual coord get_nodo_c();
    //nodo *getproxh(){return proxh;} //esto se implementara como matriz de dependencias en la clase celda
    //nodo *getproxv(){return proxv;} //esto se implementara como matriz de dependencias en la clase celda
    /*funciones para dar nuevos valores a las variables de los nodos*/
    virtual void set_nodo_valor(T elem); // Insert a new element
    //void setproxh(nodo *& proxh){this->proxh = proxh;}
    //void setproxv(nodo *& proxv){this->proxv = proxv;}
    virtual void set_nodo_f(coord fila);
    virtual void set_nodo_c(coord columna);
};

typedef vector<nodo> my_row;


#endif // NODO_H
