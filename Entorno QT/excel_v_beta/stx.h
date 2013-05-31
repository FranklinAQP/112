#ifndef STX_H
#define STX_H
#include "operacion.h"
#include "operadores.h"

typedef vector<expresion*> list_depend; /*Definimos variable de vector de dependencias*/
typedef vector<Func> list_atom; /*vector de atomos*/
using namespace all_operators;
class stx  /*Clase que evalua sintaxis de las cadenas de funciones*/
{
private:
    Func my_func;
    list_depend dependencies;
    list_atom list_atomos;
    void reduction();/*Para Quitar espacios de la cadena my_func*/
    void starting_vector(int aumento=0);/*Inicializa el vector de atomos*/
    void atomizer();/*Separa la cadena my_func en atomos y los inserta en el vector de atomos*/
    int next_operador(size_t* );
public:

    stx(string text){set_func(text);}
    virtual ~stx();
    expresion* parse();
    inline void clean(){dependencies.empty();}
    inline void set_func(Func text){
        my_func.clear();
        my_func=text;
    }
    void insert_node(size_t inf, size_t sup, size_t* number_operators);
    void insert_root(size_t* number_operators);
    void elementos();
    list_atom tree_ordened(list_atom atomos);
    list_depend get_dependencies();
};

#endif // STX_H
