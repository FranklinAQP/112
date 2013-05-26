#ifndef _TIPOS_H_
#define _TIPOS_H_
#include <string>
#include <assert.h>
using namespace std;

/*
template <string C,int F> struct Coordenada{
    enum{c=C, f=F};
    int col ();
}
int Coordenada::col(){
    string mi_col = c;
    int temp=0;
    if(mi_col.size()>0)
        for(register size_t i=0; i<=mi_col.size(); ++i)
            temp = temp + ((int)mi_col[i])-65;
    return temp;
}
*/
/* Definimos el tipo cadena para la funcion ingresada  */
typedef string Func;
/* Definimos el tipo de valor para las coordenadas  */
typedef int coord;
/* Definimos el tipo de valor con el que se trabajara */
typedef double T;
/* Definimos el tipo del puntero a funcion fnptr */
typedef T (*fnptr)(T,T);

#endif //_TIPOS_H_
