#ifndef _STX_H_
#define _STX_H_
#include "operacion.h"


typedef vector<expresion*> list_depend; /*Definimos variable de vector de dependencias*/
typedef vector<Func> list_atom; /*vector de atomos*/
class stx /*Clase que evalua sintaxis de las cadenas de funciones*/
{
private:
public:
    Func my_func;/*funcion a evaluar*/
    expresion *root; /*puntero a root o raiz del arbol binario*/
    list_depend dependencies;/*vector de punteros a expresion (nodocelda, constante u operacion)*/
    list_atom list_atomos;/*Vector para almacenar los atomos*/
    class matrix *logic_matrix_;/*indica la matriz logica donde se realizan las operaciones*/
    vector<int> number_operators_;
    int next_op;

//public:
    void reduction();/*Paso 1: reduce espacios de la cadena my_func*/
    void atomizer();/*Paso 2: Separa la cadena my_func en atomos y los inserta en el vector de atomos*/
    bool is_constante(const Func &atomo);/*Usado en paso 3a: True si el atomo representa a un numero*/
    bool is_nodocelda(const Func &atomo);/*Usado en paso 3a: True si el atomo representa a un nodocelda*/
    bool is_function(const Func &atomo);/*Usado en paso 3a: True si el atomo representa a una operacion*/
    void expresion_ptr(const int &pos);/*Paso 3a ->3: Asigna en dependencies punteros segun el atomo de su misma posicion en list_atomos*/
    void starting_vector();/*Paso 3: Inicializa el vector de dependencias */
    void Number_Operators();/*Usado en paso 4a: retorna la cantidad de cada operador existente por su prioridad dentro de la funcion*/
    void next_operator();/*Usado en paso 4a: retorna siguiente operador a evaluar en el arbol por su prioridad*/


    //
    stx();/*construye sin datos*/
    stx(string text);/*Construye stx en base al valor de funcion ingresado*/
    //virtual ~stx();/*Destructor Virtual*/
    expresion* detect_root(size_t inf, size_t supp);/*Paso 4a->4: Devuelve el puntero a expresion(nodocelda, constante u operacion) que sera la raiz en el intervalo de atomos indicados*/
    void Root();/*Paso 4: Asigna al puntero root la direccion del puntero a expresion raiz del arbol creado*/
    void parse();/*Ejecuta pasos del 1 al 4 y devuelve el root*/
    inline void clean(){dependencies.empty();}/*Limpia el vector de dependencias*/
    inline void set_func(Func text){/*limpia y asigna la nueva funcion a evaluar*/
        number_operators_.clear();
        number_operators_.resize(5,0);
        next_operator();
        my_func.clear();
        my_func=text;
    }
    list_depend get_dependencies();
    void free_expresion(expresion* _ptr);/*liberar punteros a expresiones*/
    void edit_ptr_matrix (matrix *ptr_matrix_){ logic_matrix_ = ptr_matrix_;}
};

#endif // _STX_H_
