#include "matrix.h"
#include <assert.h>
/*-- Ampliacion horizontal--*/
void matrix::resizeh()
{
        for (register size_t i = 0; i < matriz.size(); ++i)
            matriz[i].resize(get_max_col() + my_incremento);
        get_max_col() += my_incremento;
}
/*-- Ampliacion vertical--*/
void matrix::resizev()
{
        matriz.resize(max_row + my_incremento, my_row(max_col + my_incremento) );
        get_max_row() += my_incremento;
}


/*--  para ampliar el vector
--*/
void matrix::resize()
{
    resizeh();
    resizev();
}



void matrix::inicio(coord incremento) // crear matriz
{
    my_incremento = incremento;
    resize();
}
matrix::matrix(coord incremento) // crear matriz
    : max_row(0), max_col(0), current_row(0), current_col(0)
{
    inicio(incremento);

}/*-- Ingresar un nuevo valor en
   --*/
inline void matrix::set_nuevo_valorx(coord fila, coord col, T &elem)
{
    assert(fila<= max_row && col<=max_col);
    matriz[fila - 1][col - 1].set_nodo_valor(elem); // inserto el elemento
}
/*-- ingresar valor --*/
inline void matrix::set_nuevo_valor(T &elem)
{
    set_nuevo_valorx(current_row, current_col, elem);
}
/*--void matrix::imprimir_m()
{
    for (register unsigned int i=0; i<matriz.size(); ++i)
    {    for(register unsigned int j=0; j<matriz[i].size(); ++j)
             cout << matriz[i][j].get_nodo_valor() << "\t";
          cout << endl;
     }
}
--*/


