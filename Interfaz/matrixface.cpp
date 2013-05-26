#include "matrixface.h"

/*-- Ampliacion horizontal--*/
void matrixface::resizeh()
{
        for (register size_t i = 0; i < matriz.size(); ++i)
            matriz[i].resize(get_max_col() + my_incremento);
        get_max_col() += my_incremento;
}

/*-- Ampliacion vertical--*/
void matrixface::resizev()
{
        matriz.resize(max_row + my_incremento, my_row(max_col + my_incremento) );
        get_max_row() += my_incremento;
}

/*--  para ampliar el vector horizontal y verticalmente--*/
void matrixface::resize()
{
    resizeh();
    resizev();
}

/*inicia la matriz con filas y columnas 10x10 por defecto*/
void matrixface::inicio(coord incremento)
{
    my_incremento = incremento;
    resize();
}

/*constructor dando valor inicial a todas las variables privadas*/
matrixface::matrixface(coord incremento) // crear matriz
    : max_row(0), max_col(0), current_row(0), current_col(0)
{
    inicio(incremento);

}

/*-- Ingresar un nuevo valor en una determinada fila y columna--*/
inline void matrixface::set_nuevo_valorx(coord fila, coord col, T &elem)
{
    assert(fila<= max_row && col<=max_col);/*Si es falso aborta el programa*/
    matriz[fila - 1][col - 1].set_value(elem); /*inserto el elemento*/
}

/*-- ingresar valor en fila y columna actual--*/
inline void matrixface::set_nuevo_valor(T &elem)
{
    set_nuevo_valorx(current_row, current_col, elem);
}
