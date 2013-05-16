#ifndef MATRIX_H
#define MATRIX_H
#include "nodo.h"
//typedef int coord;
//typedef double T;
class matrix   // clase celda aun no terminado
{
private:

        coord current_row, /*--fila actual--*/
              current_col, /*--columna actual--*/
              max_row, /*--maximo de espacio en filas--*/
              max_col, /*--maximo de espacio en columnas--*/
              my_incremento; /*--incremento en el resize--*/
        vector <my_row> matriz;
        void resizeh(); /*-- para ampliar columnas --*/
        void resizev(); /*--para ampliar filas--*/
        void resize(); /*--para ampliar la matriz--*/
        void inicio(coord my_incremento); /*--creo mi matriz--*/

public:
        matrix(coord my_incremento = 10);
        //T get_current_rowc(nodo** &head);
        inline coord get_current_row() const {return current_row;}
        inline coord get_current_col() const {return current_col;}
        inline coord &get_max_col() {return max_col;}
        inline coord &get_max_row() {return max_row;}
        //void imprimir_m();
        void set_nuevo_valorx(coord f, coord c,T &elem);
        void set_nuevo_valor(T &elem);
        inline void set_current_row(coord fila){current_row=fila;}
        inline void set_current_col(coord col){current_col=col;}
        inline void set_current_row_col(coord row, coord col){current_col=col; current_col=col;}
};



#endif // MATRIX_H
