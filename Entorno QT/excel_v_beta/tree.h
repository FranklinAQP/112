#ifndef _TREE_H
#define _TREE_H
#include "operacion.h"

/*Clase que permite construir el arbol y obtener el resultado de get_value*/
class tree: public expresion
{
private:
    expresion *root;/*Declaramos el node raiz o operacion raiz*/
    void free_operacion(expresion* to_free);
    bool is_number(Func atomo);
public:
    tree();
    ~tree();
    expresion* Root() { return root; }
    void add_operacion(int lado, Func funcion, operacion* to_exp);
    void add_operacion(fnptr funcion);
    void inOrder(expresion* n);
    void preOrder(expresion* n);
    void postOrder(expresion* n);
    T get_value(){return root->get_value();}
};

#endif // _TREE_H
