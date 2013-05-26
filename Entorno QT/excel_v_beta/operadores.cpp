#include "operacion.h"
#include <math.h>
T sumab(T a,T b){/*Funcion suma binaria*/
    return a+b;
}
T resb(T a,T b){/*Funcion resta binaria*/
    return a-b;
}
T multb(T a,T b){/*Funcion multiplicacion binaria*/
    return a*b;
}
T divb(T a,T b){/*Funcion division binaria*/
    return a/b;
}
T sin(T a,T ){/*Funcion seno*/
    return ::sin(a);
}
T none(T a,T ){/*Funcion que no ejecuta nada, su uso puede eliminarse*/
    return a;
}
/*Definimos el puntero general a todas las funciones existentes las que estan en un array*/
fnptr allfunction[] = {&sumab,&resb,&multb,&divb,&sin,&none};

