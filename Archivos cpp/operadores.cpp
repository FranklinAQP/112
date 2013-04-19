#include "operadores.h"
#include <iostream>
using namespace std;
Copbin::Copbin(){
}
Copbin::~Copbin(){
}
float Copbin::sumab(float a,float b){
    return a+b;
}
float Copbin::resb(float a,float b){
    return a-b;
}
float Copbin::multb(float a,float b){
    return a*b;
}
float Copbin::divb(float a,float b){
    return a/b;
}
/* Ahora creamos una lista de punteros a las funciones de Copbin
que recibe dos float y devuelven un float todos ellos*/
float (Copbin::*apm[])(float, float) = {&Copbin::sumab,&Copbin::resb,&Copbin::multb,&Copbin::divb};
int main()
{
    Copbin *pobj = new Copbin; //Creando puntero a clase Copbin
    int opt;
    float a,b,x;
    cout << "opcion(0 suma/1 resta/2 multiplicacion/3 division): "; cin>>opt;
    cout << "valor a: ";cin>>a;
    cout << "valor b: ";cin>>b;
    x = (pobj->*apm[opt])(a,b); //
    cout << "respuesta: " << x << endl;
    system("PAUSE"); 
    return 0;
}
