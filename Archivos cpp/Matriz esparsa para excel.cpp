/**************************************
Codigo de matriz dispersa arreglado en clases, estructuras y tipos para utilizarlo con
el entorno grafico en la hoja de calculo
**************************************/
#include <iostream>

using namespace std; //para usar variables locales
typedef int cel;  //Definicion del tipo a valor de las celdas
typedef int coord;  //Definicion del tipo de las coordenadas f,c
typedef int tip;
struct celda   // define un bloque de datos para la celda aun no terminado
{
	cel valor;
	coord fila;
	coord columna;
//	celda *proxh;
//	celda *proxv;
};

tip **pm=NULL; //Definicion del puntero que navegara la matriz

void crear(tip **&nav, coord f, coord c)//crea puntero que dara valores a cada celda
{
     nav = new tip*[f];
     for (register coord i=0; i<f; ++i)
         nav[i] = new tip[c];
}

void ingresar(tip **nav,coord f, coord c)
{
     for (register coord i=0; i<f; ++i)
         for(register coord j=0; j<c; ++j)
             pm[i][j]=0;
}

void imprimir(tip **nav,coord f, coord c)
{
     for (register coord i=0; i<f; ++i)
     {
         for(register coord j=0; j<c; ++j)
             cout << pm[i][j] << "\t";
         cout << endl;
      }
}

void borrar (tip **&pm,coord f, coord c)//elimina el puntero que asigna valores a las celdas
{
     for (register coord i=0; i<f; ++i)
         delete [] pm[i];
     delete []pm;
     pm=NULL;
}

int main()
{
    coord f,c;
    cout << "Filas: "; cin >> f;
    cout << "Columnas: "; cin >> c;
    crear (pm,f,c);
    ingresar(pm,f,c);
    imprimir(pm,f,c);
    borrar(pm,f,c);
//    system("PAUSE");
    return 0;
}
