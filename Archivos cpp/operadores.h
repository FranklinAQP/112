#ifndef OPERADORES_H
#define OPERADORES_H
#include <iostream>
//#include <principal.h>
using namespace std;
class Copbin // Clase operadores binarios
{
public:
    Copbin();
    ~Copbin();
    float sumab(float, float);
    float resb(float, float);
    float multb(float, float);
    float divb(float, float);
};

#endif // OPERADORES_H
int main(int){
    treenodo *nodo;   // puntero al nodo
    nodo= new treenodo;
    crear(nodo);
    preorden(nodo);
    getch();
    system("PAUSE");
    return 0;
}
