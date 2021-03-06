#ifndef _OPERACION_H_
#define _OPERACION_H_
#include "nodo.h"

class operacion : public expresion /* Clase que maneja las operaciones de la funcion */
{
private:
    expresion *pleft,/*Declaramos puntero izquierdo a expresion*/
              *pright; /*Declaramos puntero derecho a expresion*/
    fnptr funcion; /*Declaramos una variable del tipo puntero a funcion definido en tipos.h*/
public:
    operacion(expresion *ptrleft, /* Puntero a expresion izquierda de la funcion */
              fnptr funcion_ptr, /* Puntero a la funcion */
              expresion *ptrright = 0): /* Puntero a expresion derecha de la funcion en caso de no encontrarse 0 */
        pleft(ptrleft),    /* asignamos el valor de variable pleft */
        pright(ptrright), /* asignamos el valor de variable pright */
        funcion(funcion_ptr) /* asignamos el valor de variable funcion */
        {}
    operacion(fnptr funcion_ptr){/*constructor con solo un parametro*/
        pleft = NULL;
        funcion = funcion_ptr;
        pright = NULL;
    }
    virtual ~operacion(); /*Destructor virtual*/
    T get_value();/*devuelve el valor de una funcion*/
    void set_fnptr(fnptr _funcion) { funcion = _funcion; }
    void set_Left(expresion* aLeft) { pleft = aLeft; }
    void set_Right(expresion* aRight) { pright = aRight; }
    expresion* Left() { return pleft; }
    expresion* Right() { return pright; }
};

#endif // _OPERACION_H_
