#include <thread>/*libreria c++11*/
#include <algorithm>
#include "stx.h"
#include "constante.h"
#include "nodocelda.h"
#include "matrix.h"
#include "operadores.h"/*no incluir en .h por error de multidefinicion*/
#include <cassert>

stx::stx()
    : root(0)
{
    number_operators_.resize(all_operators_::n_operators,0);
    next_op = -1;
}

stx::stx(string text)
    : root(0)
{
    set_func(text);
    number_operators_.resize(all_operators_::n_operators,0);
    next_op = -1;
}
/*
stx::~stx()
{

}
*/
/*Paso 1: Reduce los espacios en blanco de la funcion*/
void stx::reduction()
{
    for(register size_t i=0; i<my_func.length(); ++i)
            if(my_func[i] == ' '){
                my_func.erase(my_func.begin()+i);/*para eliminar un caracter de la cadena*/
                --i;
            }
}

/*Paso 2: Separa los atomos de la cadena colocandolos al vector<Func> list_atomos*/
void stx::atomizer()
{
    list_atomos.resize(0);
    Func atomo = "";/*valor inicial necesario para concatenar*/
    for(register size_t i=0; i<my_func.size(); ++i)
        if(my_func[i]=='+' || my_func[i]=='-' || my_func[i]=='*' || my_func[i]=='/'){/*Aqui todos los operadores de size==1*/
          if(atomo.size()>0){
            list_atomos.push_back (atomo);
            atomo="";
          }
          atomo+=my_func[i];
          list_atomos.push_back (atomo);
          atomo="";
        }else if(atomo=="SIN"){/*Aqui operadores de size==3*/
          list_atomos.push_back (atomo);
          atomo="";
        }else
          atomo+=my_func[i];
    if(atomo!="")
        list_atomos.push_back (atomo);/*incluye el ultimo atomo completo*/
}

/*usado en Paso 3a: Confirma si un atomo indicado es del tipo constante(numero)*/
bool stx::is_constante(const Func &atomo)
{
    int point=0;/*numero de puntos en el atomo*/
    for(register size_t i=0; i<atomo.size(); ++i)
        if(atomo[i] < '0' || '9' < atomo[i] ){
            if(atomo[i]=='.')
                ++point;
            else
                return false;
        }
    if(point>1)
        return false;
    return true;
}

/*usado en Paso 3a: Confirma si un atomo indicado es del tipo nodocelda(puntero a nodo)*/
bool stx::is_nodocelda(const Func &atomo)
{
    if(atomo[0]<'A' || 'Z'<atomo[0])
        return false;
    int tipo=0;/*=0 para caracter alfabetico y =1 para caracter numerico*/
    for(register size_t i=1; i<atomo.size(); ++i)
        if(tipo==0 &&(atomo[i]<'A' || 'Z'<atomo[i]))
            tipo=1;
        else if(tipo==1 &&(atomo[i]<'0' || '9'<atomo[i]))
            return false;
    if(tipo==0)/*Si solo existen caracteres alfabeticos*/
        return false;
    return true;
}

/*usado en Paso 3a: Confirma si el atomo corresponde a una funcion*/
bool stx::is_function(const Func &atomo)
{
    size_t n=0;
    while(n<all_operators_::n_operators)
        if(atomo == all_operators_::symbols_operators[n])
            return true;
        else
            ++n;
    return false;
}

/*Paso 3a(usado en paso 3): crea punteros a expresion dependiendo de la sintaxis de los atomos*/
void stx::expresion_ptr(const int &pos)
{
    if(is_constante(list_atomos[pos]))
        dependencies[pos]=new constante(list_atomos[pos]);
    else if(is_nodocelda(list_atomos[pos]))
        dependencies[pos]=new nodocelda(logic_matrix_, list_atomos[pos]);
    else if(is_function(list_atomos[pos]))
        return;/*esta clase de punteros lo creamos recien en detect_root()*/
    else{/*Error al no corresponder a un tipo conocido*/
        }
}

/*Paso 3: Inicializa el vector de dependencias usando hebras considerando todos los nodos -> internos(operadores) y hojas(constantes y nodocelda) del arbol*/
void stx::starting_vector()
{
    dependencies.resize(list_atomos.size());/*el numero de punteros es equivalente al numero de atomos*/
    for(int i=0; i<int (list_atomos.size()); ++i)/*creamos punteros segun la sintaxis de cada atomo*/
        expresion_ptr(i);
}

/*Usado en paso 4a: Para contar el numero de operadores de cada tipo en el vector de atomos */
void stx::Number_Operators()
{/*identificamos presencia de operadores por prioridad en este orden: + - * / SIN */
    //vector<size_t> number_operators_(all_operators_::n_operators);
    //for (size_t &item: number_operators_) item = 0;//for()={0,0,0,0,0};/*Modificar aqui si aumentan el num de operadores o crear una funcion que retorne un array dinamico*/
    bool found;
    size_t pos;
    for(register size_t i=0; i<list_atomos.size();++i){
        found=false;
        pos=0;
        while(found==false && pos<all_operators_::n_operators){
            if(list_atomos[i]==all_operators_::symbols_operators[pos]){
                ++number_operators_[pos];
                found =true;
            }
            else
                ++pos;
        }
    }
    //return number_operators_;
}

/*Usado en Paso 4a: retorna el orden de prioridad del siguiente operador a evaluar que no tiene number_operators=0*/
void stx::next_operator()//const vector<size_t> &numbers
{/*el orden que indica el array number_operators es:{+,-,*,/,SIN}*/
    next_op = -1;
    for(register int i=0; i<=(int)all_operators_::n_operators; ++i)/*bucle segun la cantidad de operadores en operadores.h*/
        if(number_operators_[i]>0){
            next_op = i;
            return;
        }
    return;
        /*en caso no haya operadores en la cadena*/
}

/*Paso 4a(Usado en paso 4): Funcion para encontrar la posicion del operador que sera la raiz del arbol
y formara parte del primer elemento del vector de dependencias*/
expresion* stx::detect_root(size_t inf, size_t supp)
{
    next_operator();
    if(next_op == -1 || supp-inf<=1)
        return dependencies[inf];/*retornar si no existe ningun operador *///(int)inf;
    size_t sup=supp-1, cond=1, elected;/*variables necesarias*/
    size_t middle=(supp+inf)/2;/*posicion media del vector de atomos*/
    Func operador=all_operators_::operator_priority(next_op);/*simbolo del operador en posicion de next_priority*/
    int &cant=number_operators_[next_op];/*variable que referencia a la cantidad de operadores del operador en posicion de next_priority*/
    elected = middle;
    while(cond){
        if(list_atomos[elected]==operador){//Si posicion de raiz elegida cumple la condicion
            --cond;//libera el while cond=0
            --cant;//disminuye la cantidad del operador utilizado
        }else if(inf<elected && elected<middle)
            --elected;
        else if(elected==inf)
            elected = middle + 1;
        else if(elected<sup)
            ++elected;
        else if(elected==sup)
            elected = middle - 1;
    }   /*Si no se asigna valor para selected entonces el atomo es puntero a constante o puntero a nodocelda*/
    //return (int)elected;
    dependencies[elected]=new operacion(detect_root(inf, elected),all_operators_::what_function(list_atomos[elected]),detect_root(elected+1, supp));
    return dependencies[elected];
}

/*Paso 4: Asigna al puntero root la direccion del puntero a expresion raiz del arbol creado*/
void stx::Root()
{
    Number_Operators();
    if (list_atomos.size()==1)
        root = dependencies[0];
    else
        root = detect_root(size_t(0), list_atomos.size());
}

/*Ejecuta el parse pasos del 1 al 4 y devueleve el valor de root*/
void stx::parse()
{
    dependencies.clear();/*quitamos referencias existentes en vector dependencies*/
    list_atomos.clear();/*quitamos referencias existentes en vector list_atomos*/
    reduction();/*quitamos espacios de la funcion*/
    atomizer();/*Separamos los atomos al vector*/
    starting_vector();/*inicializar el vector de punteros a expresion(nodos del arbol)*/
    Root();/*armar el arbol de acuerdo a la precedencia y terminar de poblar*/
    //return root;/*retorna la raiz del arbol*/
}
