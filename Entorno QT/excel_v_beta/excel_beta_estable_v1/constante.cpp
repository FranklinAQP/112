#include "constante.h"
#include <stdlib.h>

/*Alternativa de Constructor*/
constante::constante(Func numero)
{
    /*Crear aqui una funcion que convierta Func(string) a T(double)*/
    nodo_valor = atof(numero.c_str());
}

/*Destructor*/
constante::~constante()
{

}
