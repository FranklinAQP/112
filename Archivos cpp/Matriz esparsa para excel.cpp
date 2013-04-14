/**************************************
Codigo de matriz dispersa arreglado en estructuras para utilizarlo con 
el entorno grafico en la hoja de calculo
**************************************/
#include <iostream>

using namespace std; //para usar variables locales

struct celda   // define un bloque de datos para la celda aun no terminado
{
	int valor;
	int fila;
	int columna;
	struct celda *prox;
};

//typedef int COORD; //Definicion del tipo de las coordenadas f,c
//typedef int T; //Definicion del tipo a valor de las celdas
                   

int **pm=NULL; //Definicion del puntero que navegara la matriz


void crear(int **&nav, int f, int c)//crea puntero que dara valores a cada celda
{
     nav = new int*[f];
     for (register int i=0; i<f; ++i)
         nav[i] = new int[c];
}

void ingresar(int **nav,int f, int c)
{
     
     
     for (register int i=0; i<f; ++i)
         for(register int j=0; j<c; ++j)
             cin >> pm[i][j];     
}

void imprimir(int **nav,int f, int c)
{
     for (register int i=0; i<f; ++i)
         for(register int j=0; j<c; ++j)
             cout << pm[i][j];         
}

void borrar (int **&pm,int f, int c)//elimina el puntero que asigna valores a las celdas
{
     for (register int i=0; i<f; ++i)
         delete [] pm[i];
     delete []pm;
     pm=0;
}     

int main()
{
    int f,c,ff,cc,op,valor;
    cout << "Filas: "; cin >> f;
    cout << "Columnas: "; cin >> c;
    int m[f][c]; //creando matriz inicial
    crear (pm,f,c);
    cout << "Desea insertar un valor(1=Si,2=No) 1/0: "; cin >> op;    
    while (op)
    {
          cout << "posicion fila y columna : "; cin >> ff >> cc;;
          cout << "valor (enteros) : ";cin >> valor;
          ingresar(pm,ff,cc);
          cout << "Desea insertar un valor(1=Si,2=No) 1/0: "; cin >> op;           
    }             
    imprimir(pm,f,c);
    borrar(pm,f,c);
    system("pause");
    return 0;
}
