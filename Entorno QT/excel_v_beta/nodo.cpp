#include "nodo.h"

nodo::nodo()
{

}
nodo::~nodo()
{

}


 /*funciones para dar nuevos valores a las variables de los nodos*/

void nodo::set_value(T elem)
{
    nodo_valor = elem;
}
/*Inserta un puntero a nodo en el vector de dependencias*/
void nodo::set_ptrdependencies(nodo* ptr_nodo)
{
    for(register size_t i=0; i<ptrdependencies.size(); ++i)
        if(ptrdependencies[i] == ptr_nodo)
            return;
    ptrdependencies.push_back(ptr_nodo);
}

/*Elimina un vector a nodo en el vector de dependencias*/
void nodo::erase_ptrdependencies(nodo* ptr_nodo)
{
    for(register size_t i=0; i<ptrdependencies.size(); ++i)
        if(ptrdependencies[i] == ptr_nodo){
            ptrdependencies.erase(ptrdependencies.begin()+i);/*para eliminar un puntero de la cadena*/
            return;
        }
}

