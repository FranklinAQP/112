#include "analizer_stx.h"

analizer_stx::analizer_stx(coord incremento)
    : max_row(0), max_col(0), current_row(0), current_col(0)
{
    inicio(incremento);
}

/*-- Ampliacion horizontal--*/
void analizer_stx::resizeh()
{
        for (register size_t i = 0; i < analizador_stx.size(); ++i)
            analizador_stx[i].resize(get_max_col() + my_incremento);
        get_max_col() += my_incremento;
}

/*-- Ampliacion vertical--*/
void analizer_stx::resizev()
{
        analizador_stx.resize(max_row + my_incremento, vector<stx> (max_col) );
        get_max_row() += my_incremento;
}

/*--  para ampliar el vector horizontal y verticalmente--*/
void analizer_stx::resize()
{
    resizeh();
    resizev();
}

/*inicia la matriz con filas y columnas 10x10 por defecto*/
void analizer_stx::inicio(coord incremento)
{
    my_incremento = incremento;
    resize();
}

/*retorna puntero a stx*/
stx &analizer_stx::get_stx(coord fila, coord col){
    assert(fila<= max_row && col<=max_col);/*Si es falso aborta el programa*/
    return analizador_stx[fila][col];
}



