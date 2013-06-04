#include "stx.h"

/*Para reducir los espacios en blanco de la funcion*/
void stx::reduction()
{
    for(register size_t i=0; i<my_func.length(); ++i)
            if(my_func[i] == ' '){
                my_func.erase(my_func.begin()+i);/*para eliminar un caracter de la cadena*/
                --i;
            }
}

/*Para separar los atomos de la cadena Func*/
void stx::atomizer()
{
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
    list_atomos.push_back (atomo);/*incluye el ultimo atomo completo*/
}

/*Para iniciar el vector de dependencias considerando los nodos internos(operadores) del arbol*/
void stx::starting_vector()
{
    dependencies.resize(list_atomos.size()/2);
}

/*retorna el orden de prioridad del siguiente operador a evaluar que no tiene number_operators=0*/
int stx::next_operador(size_t* numbers)
{/*el orden que indica el array number_operators es:{+,-,*,/,SIN}*/
        for(register int i=0; i<all_operators::n_operators; ++i)/*bucle segun la cantidad de operadores en operadores.h*/
            if(numbers[i]>0)
                return i;
        return -1;/*en caso no haya operadores en la cadena*/
}



/*Funcion para encontrar la posicion del operador que sera la raiz del arbol
y formara parte del primer elemento del vector de dependencias*/
void stx::detect_root(size_t* number_operators)
{
    if(next_operador(number_operators)==-1)
        return;/*retornar si no existe ningun operador*/
    size_t inf=0, sup=list_atomos.size(), cond=1, elected;/*variables necesarias*/
    size_t middle=(sup-inf+1)/2;/*posicion media del vector de atomos*/
    int next_priority=next_operador(number_operators);/*posicion(0 a 4) de la prioridad mas baja existente*/
    Func operador=all_operators::operator_priority(next_priority);/*simbolo del operador en posicion de next_priority*/
    size_t &cant=number_operators[next_priority];/*variable que referencia a la cantidad de operadores del operador en posicion de next_priority*/
    elected = middle;
    while(cond){
        if(list_atomos[elected]==operador){/*Si posicion de raiz elegida cumple la condicion*/
            --cond;/*libera el while cond=0*/
            --cant;/*disminuye la cantidad del operador utilizado*/
        }else if(inf<elected && elected<middle)
            --elected;
        else if(elected==inf)
            elected = middle + 1;
        else if(elected<sup)
            ++elected;
    }   /*Si no se asigna valor para selected entonces el atomo es numero o puntero a nodo*/
    if(sup-inf>=2){
        fnptr _new_function=all_operators::what_function(list_atomos[elected]);
        operacion nueva(_new_function);
        dependencies[0] = &nueva;/*Creo el inicio o root del arbol */
    }
    /* ????? */
}

void stx::detect_node(size_t inf, size_t sup, size_t* number_operators)
{
    if(next_operador(number_operators)==-1)
        return;/*retornar si no existe ningun operador*/
    size_t cond=1, elected;/*variables necesarias condicional y posicion elegida*/
    size_t middle=(sup-inf+1)/2;/*posicion media del vector de atomos*/
    int next_priority=next_operador(number_operators);/*posicion(0 a 4) de la prioridad mas baja existente*/
    Func operador=all_operators::operator_priority(next_priority);/*simbolo del operador en posicion de next_priority*/
    size_t &cant=number_operators[next_priority];/*variable que referencia a la cantidad de operadores del operador en posicion de next_priority*/
    elected = middle;
    while(cond){
        if(list_atomos[elected]==operador){/*Si posicion de raiz elegida cumple la condicion*/
            --cond;/*libera el while cond=0*/
            --cant;/*disminuye la cantidad del operador utilizado*/
        }else if(inf<elected && elected<middle)
            --elected;
        else if(elected<middle)
            elected = middle + 1;
        else if(list_atomos[elected]==operador){/*Si posicion de raiz elegida cumple la condicion*/
            --cond;
            --cant;
        }else if(elected<sup)
            ++elected;
    }
    /* ???? */
}


/*Para ordenar los atomos en la forma de lectura del arbol binario*/
void stx::tree_ordened()
{/*identificamos presencia de operadores por prioridad en este orden: + - * / SIN */
    size_t number_operators[5]={0};
    for(register size_t i=0; i<list_atomos.size();++i)
        if(list_atomos[i]=="+")
            ++number_operators[0];/*sumas*/
        else if(list_atomos[i]=="-")
            ++number_operators[1];/*restas*/
        else if(list_atomos[i]=="*")
            ++number_operators[2];/*multiplicaciones*/
        else if(list_atomos[i]=="/")
            ++number_operators[3];/*divisiones*/
        else if(list_atomos[i]=="SIN")
            ++number_operators[4];/*funciones seno*/
    detect_root(number_operators);
    /* ????? */
}


expresion* stx::parse()
{
    dependencies.clear();/*quitamos referencias existentes en vector dependencies*/
    list_atomos.clear();/*quitamos referencias existentes en vector list_atomos*/
    reduction();/*quitamos espacios de la funcion*/
    atomizer();/*Separamos los atomos al vector*/
    starting_vector();/*inicializar el vector de punteros a expresion(nodos internos del arbol)*/
    tree_ordened();/*armar el arbol de acuerdo a la precedencia*/
            /*comenzar a poblar*/
    return dependencies[0];/*retorna la raiz del arbol*/
}
