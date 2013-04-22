/***********************************
Modelo de matriz dinamica bidimensional con espacio declarado  de acuerdo
a su tamaño ingresado por el usuario
**********************************/
#include <iostream>
#include <stdlib.h>
using namespace std;
//Crea matriz dinamica
typedef int tip;
typedef int coord;
tip **crear(coord f, coord c) {
    tip **pm = (tip **)malloc(sizeof(tip *) * f); //crea espacio para las filas
    for (register coord i = 0; i < f; i++)
        pm[i] = (tip *)malloc(sizeof(tip) * c); //crea espacio para las columnas dentro de cada fila
    return pm;
}

void borrar(tip **pm, coord f, coord c) { //Destruye la matriz (libera la memoria dinamica)
    for (register coord i = 0; i < f; i++)
        free(pm[i]);
    free(pm);
}

void llenar(tip **pm, coord f, coord c) { //llenar la matriz con valores por defecto 0
    for (register coord i = 0; i < f; i++)
        for (register coord j = 0; j < c; j++)
            pm[i][j] = 0;
}

void imprimir(tip **pm, coord f, coord c) { //imprimir en pantalla
    for (register coord i = 0; i < f; i++) {
        for (register coord j = 0; j < c; j++)
            cout << pm[i][j] << "\t";
        cout << endl;
    }
}


int main ()
{
    coord f,c;
    cout << "Filas : "; cin >> f;
    cout << "Columnas : "; cin >> c;
    int **pm = crear(f, c);
    llenar(pm, f, c);
    imprimir(pm, f, c);
    borrar(pm, f, c);
    system("PAUSE");
    return 0;
}

