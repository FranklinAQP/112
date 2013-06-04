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
    list_depend dependencies;
    list_atom list_atomos;
    void reduction();/*Para Quitar espacios de la cadena my_func*/
    void atomizer();/*Separa la cadena my_func en atomos y los inserta en el vector de atomos*/
    void starting_vector();/*Inicializa el vector de dependencias */
    int next_operador(size_t* number_operators);
public:

    stx(string text){set_func(text);}
    virtual ~stx();
    expresion* parse();
    inline void clean(){dependencies.empty();}
    inline void set_func(Func text){
        my_func.clear();
        my_func=text;
    }
    void detect_node(size_t inf, size_t sup, size_t* number_operators);
    void detect_root(size_t* number_operators);
    void tree_ordened();
    list_depend get_dependencies();
};

#endif // _STX_H
