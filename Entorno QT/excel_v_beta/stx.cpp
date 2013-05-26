#include "stx.h"

/*Para reducir los espacios en blanco de la funcion*/
Func stx::reduction(Func text)
{
    Func new_func="";/*valor inicial necesario para poder concatenar*/
    for(register size_t i=0; i<text.length();++i)
        if(text[i]!=' ')
            new_func+=text[i];/*Concatenando todo menos los espacios en blanco*/
    return new_func;
}

/*Para iniciar el vector de atomos*/
void stx::starting_vector(int aumento)
{
    list_atomos.resize(10 + aumento);
}

/*Para separar los atomos de la cadena Func*/
void stx::atomizer(Func formula)
{
    Func atomo = "";/*valor inicial necesario para concatenar*/
    int x=-1;/*valor de ubicacion inicial necesario para ingresar en su ++ = 0*/
    for(register size_t i=0; i<formula.size(); ++i)
        if(formula[i]=='+' || formula[i]=='-' || formula[i]=='*' || formula[i]=='/'){/*Aqui todos los operadores de size==1*/
          if(atomo.size()>0){
            list_atomos[++x]=atomo;
            atomo="";
          }
          list_atomos[++x]=formula[i];
        }else if(atomo=="SIN"){/*Aqui operadores de size==3*/
            list_atomos[++x]=atomo;
            atomo="";
        }else
            atomo+=formula[i];
    list_atomos[++x]=atomo;/*incluye el ultimo atomo completo*/
}
/*Funcion para encontrar el operador que sera la raiz del arbol*/
void stx::insert_root(list_atom atomos, size_t inf, size_t sup,size_t number_operators[])
{
    assert(sup - inf > 0);/*si es falso aborta el programa*/
    size_t cant, cond;/*variable de cantidad del operador indicado*/
    Func operador;
    if(number_operators[0]>0) {cant=number_operators[0];operador="+";}/*suma*/
    else if(number_operators[1]>0){cant=number_operators[1];operador="-";}/*Resta*/
    else if(number_operators[2]>0){cant=number_operators[2];operador="*";}/*Multiplicacion*/
    else if(number_operators[3]>0){cant=number_operators[3];operador="/";}/*Division*/
    else if(number_operators[4]>0){cant=number_operators[4];operador="SIN";}/*Seno*/
    size_t middle=(sup-inf+1)/2;
    if(inf+1<sup){
        while(cond){
          if(cant>0)
              if(atomos[middle]==operador){
                  list_atomos.push_back(operador);
                  --cond;--cant;
              }else if(middle>inf && middle<(sup-inf+1)/2)
                  --middle;
              else if(middle<(sup-inf+1)/2)
                  middle=(sup-inf+1)/2 + 1;
              else if(atomos[middle]==operador){
                  list_atomos.push_back(operador);
                  --cond;--cant;
              }else if(middle<sup)
                  ++middle;
              else
                  list_atomos.push_back(atomos[middle]);
        }        /*error si no cumple ninguna de estas condiciones*/
        insert_child_left(atomos,inf,middle-1,number_operators);
        insert_child_right(atomos,middle+1,sup,number_operators);
    }
}

void stx::insert_child_left(list_atom atomos, size_t inf, size_t sup,size_t number_operators[])
{
    /*Aqui codigo para agregar lado izquierdo del recorrido del arbol*/
}

void stx::insert_child_right(list_atom atomos, size_t inf, size_t sup,size_t number_operators[])
{
    /*Aqui codigo para agregar lado izquierdo del recorrido del arbol*/
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
    insert_root(atomos, 0, atomos.size(),number_operators);
}


expresion* stx::parse()
{
    Func f_reducida = reduction(my_func);/*quitamos espacios de la funcion*/
    starting_vector();/*inicializar el vector de atomos*/
    atomizer(f_reducida);/*Separamos los atomos al vector*/
    //armar el arbol de acuerdo a la precedencia
            //comenzar a poblar
    //return new operator(new constante(5),&sumab,new constante(10));

}
