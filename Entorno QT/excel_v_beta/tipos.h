#ifndef _TIPOS_H_
#define _TIPOS_H_

/*
 #include <iostream>
template <string C,int F> struct Coordenada{
    enum{c=C, f=F};
    int col ();
}
int Coordenada::col(){
    string mi_col = c;
    int temp=0;
    if(mi_col.size()>0)
        for(register int i=0; i<=mi_col.size(); ++i)
            temp = temp + ((int)mi_col[i])-65;
    return temp;
}
*/

typedef char* Func;
typedef int coord;
typedef double T;

#endif //_TIPOS_H_
