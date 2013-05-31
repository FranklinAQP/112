#include "tree.h"

tree::tree()
{

}

tree::~tree()
{
    free_operacion(root);
}

void tree::add_operacion(fnptr funcion)
{
    // No elements. Add the root
    if ( root == NULL ) {
        expresion* n;
        n = &operacion(funcion);
        root = n;
    }
    else
        return;
}

bool tree::is_number(Func atomo)
{
    for(register size_t i=0; i<atomo.size(); ++i)
        if(atomo[i]<='0' && '9'<=atomo[i])
            return false;
    return true;
}

/*Agregando un nuevo nodo al arbol segun el lado*/
void tree::add_operacion(int lado, Func atomo, operacion* to_exp)/*lado 0=left y lado 1=right*/
{
    if(lado==0)
        if(to_exp->Left() != NULL )/*SI puntero a lado izquierdo esta ocupado*/
            add_operacion(0, atomo, to_exp->Left());
        else {
            expresion* n=new expresion;
            n = &operacion(atomo);
            to_exp->set_Left(n);
        }
    else if(lado==1)
        if(to_exp->Right() != NULL )
            add_operacion(0, atomo, to_exp->Right());
        else {
            expresion* n = &operacion(atomo);
            to_exp->set_Right(n);
        }
}


/*libera espacio y enlaces de los punteros*/
void tree::free_operacion(operacion* to_free)
{
    if ( to_free != NULL ){
        free_operacion(to_free->Left());
        free_operacion(to_free->Right());
        delete to_free;
    }
}

