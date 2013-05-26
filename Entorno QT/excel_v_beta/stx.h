#ifndef STX_H
#define STX_H
#include "operacion.h"

typedef vector<expresion*> list_depend; /*Definimos variable de vector de dependencias*/
typedef vector<Func> list_atom; /*vector de atomos*/
class stx  /*Clase que evalua sintaxis de las cadenas de funciones*/
{
private:
    Func my_func;
    list_depend dependencies;
    list_atom list_atomos;
public:
    stx(string text){set_func(text);}
    virtual ~stx();
    expresion* parse();
    inline void clean(){dependencies.empty();}
    inline void set_func(Func text){
        my_func.clear();
        my_func=text;
    }
    Func reduction(Func text);
    void starting_vector(int aumento=0);
    void atomizer(Func f_reducida);
    void insert_root(list_atom atomos, size_t inf, size_t sup,size_t* );
    void insert_child_left(list_atom atomos, size_t inf, size_t sup,size_t*);
    void insert_child_right(list_atom atomos, size_t inf, size_t sup,size_t*);
    void elementos();
    list_atom tree_ordened(list_atom atomos);
    list_depend get_dependencies();
};

#endif // STX_H
