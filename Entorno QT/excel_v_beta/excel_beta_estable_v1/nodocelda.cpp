#include "nodocelda.h"

nodocelda::nodocelda(class matrix* matrixptr, Func celda)
{
    address(matrixptr, celda);
}

nodocelda::~nodocelda()
{

}

/*construye la clase dando un valor a su puntero a nodo segun su direccion en string(Func)*/
void nodocelda::address(class matrix* matrixptr, Func celda)
{
    assert(celda[0]>='A' && celda[0]<='Z');/*Si la direccion de nodo en la matriz no empieza con letra A-Z aborta el programa*/
    coord col=0,fil=0,fcol=0;/*defino variables que seran coordenadas de fila, columna y fcol factor dependiente del numero de letras que indican la columna*/
    for(register size_t i=celda.size(); i>0; --i)
        if(celda[i]>='A' && celda[i]<='Z'){
            col += 26*fcol + ((int)celda[i])-65;/*Considerando que la columna A=Coord 0*/
            ++fcol;/*aumenta en 1 el factor de cols*/
        }
        else if(celda[i]>='0' && celda[i]<='9')
            fil = 10*fil + ((int)celda[i])-48;/*Considerando que la fila 1=Coord 1*/
        else{
            /*Aqui levantar y manejar el error*/}
    --fil;/*Para considerar que fila 1= Coord 0*/
    pnodo = &matrixptr->get_nodo(fil,col);/*Asigna al puntero la direccion del nodo requerido*/
}
