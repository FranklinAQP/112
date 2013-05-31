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

/*Para iniciar el vector de atomos*/
void stx::starting_vector(int aumento)
{
    list_atomos.resize(10 + aumento);
}

/*Para separar los atomos de la cadena Func*/
void stx::atomizer()
{
    Func atomo = "";/*valor inicial necesario para concatenar*/
    int x=-1;/*valor de ubicacion inicial necesario para ingresar en su ++ = 0*/
    for(register size_t i=0; i<my_func.size(); ++i)
        if(my_func[i]=='+' || my_func[i]=='-' || my_func[i]=='*' || my_func[i]=='/'){/*Aqui todos los operadores de size==1*/
          if(atomo.size()>0){
            list_atomos[++x]=atomo;
            atomo="";
          }
          list_atomos[++x]=my_func[i];
        }else if(atomo=="SIN"){/*Aqui operadores de size==3*/
            list_atomos[++x]=atomo;
            atomo="";
        }else
            atomo+=my_func[i];
    list_atomos[++x]=atomo;/*incluye el ultimo atomo completo*/
}

/*retorna el orden de prioridad del siguiente operador a evaluar que no tiene number_operators=0*/
int stx::next_operador(size_t* number_operators)
{
        for(register int i=0; i<5; ++i)/*Modificar 5 aqui al agregar nuevo operador(simbolo y funcion o mejorar el codigo)*/
            if(number_operators[i]>0)
                return i;
        return -1;/*en caso no haya operadores en la cadena*/
}

/*Funcion para encontrar el operador que sera la raiz del arbol*/
void stx::insert_node(size_t inf, size_t sup, size_t* number_operators)
{
    if(next_operador(number_operators)==-1)
        return;/*retornar si no existe ningun operador*/
    size_t cond=1, elected;/*variables necesarias*/
    size_t middle=(sup-inf+1)/2;/*posicion media en la lista de atomos*/
    int next_priority=next_operador(number_operators);/*valor de la prioridad mas baja existente*/
    Func operador=operator_priority(next_priority);/*simbolo del operador de prioridad next_priority*/
    size_t &cant=number_operators[next_priority];/*variable que referencia a la cantidad del operador existente*/
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
}

/*Funcion para encontrar el operador que sera la raiz del arbol*/
void stx::insert_root(size_t* number_operators)
{
    if(next_operador(number_operators)==-1)
        return;/*retornar si no existe ningun operador*/
    size_t inf=0, sup=list_atomos.size(), cond=1, elected;/*variables necesarias*/
    size_t middle=(sup-inf+1)/2;/*posicion media en la lista de atomos*/
    int next_priority=next_operador(number_operators);/*valor de la prioridad mas baja existente*/
    Func operador=operator_priority(next_priority);/*simbolo del operador de prioridad next_priority*/
    size_t &cant=number_operators[next_priority];/*variable que referencia a la cantidad del operador existente*/
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
    }   /*Si no se asigna valor para selected entonces el atomo es numero o puntero a nodo*/
    operacion n = operacion(what_function(list_atomos[elected]));/*Creo el inicio del arbol operacion* */
    //n->setKey(key);
      //  root = n;
    //if(inf+1<sup){
    //}
}

void stx::elementos()
{
    list_atom a_ordenar=list_atomos;
    list_atomos.clear();
    tree_ordened(a_ordenar);
}

/*Para ordenar los atomos en la forma de lectura del arbol binario*/
list_atom stx::tree_ordened(list_atom atomos)
{/*identificamos presencia de operadores por prioridad en este orden: + - * / SIN */
    size_t number_operators[5]={0};
    for(register size_t i=0; i<atomos.size();++i)
        if(atomos[i]=="+")
            ++number_operators[0];/*sumas*/
        else if(atomos[i]=="-")
            ++number_operators[1];/*restas*/
        else if(atomos[i]=="*")
            ++number_operators[2];/*multiplicaciones*/
        else if(atomos[i]=="/")
            ++number_operators[3];/*divisiones*/
        else if(atomos[i]=="SIN")
            ++number_operators[4];/*funciones seno*/
    insert_root(number_operators);
}


expresion* stx::parse()
{
    reduction();/*quitamos espacios de la funcion*/
    starting_vector();/*inicializar el vector de atomos*/
    atomizer();/*Separamos los atomos al vector*/
    //armar el arbol de acuerdo a la precedencia
            //comenzar a poblar
    //return new operator(new constante(5),&sumab,new constante(10));

}
