#ifndef _STX_H
#define _STX_H
#include "operacion.h"
#include "operadores.h"


typedef vector<expresion*> list_depend; /*Definimos variable de vector de dependencias*/
typedef vector<Func> list_atom; /*vector de atomos*/
class stx  /*Clase que evalua sintaxis de las cadenas de funciones*/
{
private:
    Func my_func;
    expresion *root; /*Declaramos puntero a root o raiz del arbol binario*/
    list_depend dependencies;
    list_atom list_atomos;
    void reduction();/*Para Quitar espacios de la cadena my_func*/
    void atomizer();/*Separa la cadena my_func en atomos y los inserta en el vector de atomos*/
    void starting_vector();/*Inicializa el vector de dependencias */
    size_t* Number_Operators();/*retorna la cantidad de cada operador existente por su prioridad dentro de la funcion*/
    int next_operador(size_t* number_operators);/*retorna siguiente operador a evaluar en el arbol por su prioridad*/
    bool is_constante(Func atomo);/*True si el atomo representa a un numero*/
    bool is_nodocelda(Func atomo);/*True si el atomo representa a un nodocelda*/
    bool is_function(Func atomo);/*True si el atomo representa a una operacion*/
    void expresion_ptr(Func atomo, size_t pos);/*Asigna en dependencies punteros segun el atomo de su misma posicion en list_atomos*/

public:

    stx(string text){set_func(text);}
    virtual ~stx();
    expresion* parse();
    inline void clean(){dependencies.empty();}
    inline void set_func(Func text){
        my_func.clear();
        my_func=text;
    }
    expresion* detect_root(size_t inf, size_t sup, size_t* number_operators);
    void Root();
    list_depend get_dependencies();
};

#endif // _STX_H
