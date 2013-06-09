#ifndef MATRIX_H
#define MATRIX_H
#include "nodo.h"

class matrix   /*Crea una matriz dinamica con vectores*/
{
private:
        coord current_row, /*--fila actual--*/
              current_col, /*--columna actual--*/
              max_row, /*--maximo de espacio en filas--*/
              max_col, /*--maximo de espacio en columnas--*/
              my_incremento; /*--incremento en el resize--*/
        vector <my_row> matriz;/*Declaramos variable vector 2D*/
        void resizeh(); /*-- para ampliar columnas --*/
        void resizev(); /*--para ampliar filas--*/
        void resize(); /*--para ampliar la matriz en filas y columnas--*/
        void inicio(coord my_incremento); /*--creo mi matriz--*/

public:
        friend class nodocelda;
        matrix(coord my_incremento = 10);/*Constructor de matriz por defecto en 10x10*/
        inline coord get_current_row() const {return current_row;}/*retorna valor de fila*/
        inline coord get_current_col() const {return current_col;}/*retorna valor de columna*/
        inline coord &get_max_col() {return max_col;}/*retrona maximo de columnas*/
        inline coord &get_max_row() {return max_row;}/*retorna maximo de filas*/
        nodo get_nodo(coord f,coord c);/*retorna el nodo segun coordenadas f y c*/
        void set_nuevo_valorx(coord f, coord c,T &elem);/*ingresa valor en fila F y columna C*/
        void set_nuevo_valor(T &elem);/*ingresa un valor en la fila y columna actual*/
        inline void set_current_row(coord fila){current_row=fila;}/*cambia el valor de fila actual*/
        inline void set_current_col(coord col){current_col=col;}/*cambia el valor de columna actual*/
        inline void set_current_row_col(coord row, coord col){current_row=row; current_col=col;}/*cambia el valor de fila y columna actual*/
};

#endif // MATRIX_H
