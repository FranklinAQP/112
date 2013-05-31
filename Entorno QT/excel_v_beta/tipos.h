#ifndef _TIPOS_H_
#define _TIPOS_H_
#include <string>
#include <assert.h>
using namespace std;

/* Definimos el tipo cadena para la funcion ingresada  */
typedef string Func;
/* Definimos el tipo de valor para las coordenadas  */
typedef int coord;
/* Definimos el tipo de valor con el que se trabajara */
typedef double T;
/* Definimos el tipo del puntero a funcion fnptr */
typedef T (*fnptr)(T,T);

#endif //_TIPOS_H_
