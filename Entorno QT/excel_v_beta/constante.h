#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "expresion.h"

class constante: public expresion  // Clase operadores binarios
{
private:
    T nodo_valor; //valor del nodo
public:
    constante(); // Constructor
    ~constante(); //bye nodo
//    T get_mi_valor();
//    coord get_nodo_f();
//    coord get_nodo_c();

    /*funciones para dar nuevos valores a las variables de los nodos*/
//    void set_nodo_valor(T elem); // Insert a new element
//    void set_nodo_f(coord fila);
//    void set_nodo_c(coord columna);

};

#endif // CONSTANTE_H
