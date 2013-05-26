#ifndef _NODO_FACE_H_
#define _NODO_FACE_H_
#include <vector>

class celdaface   /* clase celdaface aun no terminada */
{
    //friend class matrixface;

private:
    T celdaface_valor; /*variable que almacena el valor*/

public:
    celdaface(); /*Constructor*/
    virtual ~celdaface(); /*Destructor Virtual*/
    inline T get_value(){return celdaface_valor;}/*devuelve el valor de variable celdaface_valor*/
    virtual void set_value(T elem); /*Insertar un nuevo elemento*/
};

typedef vector<celdaface> my_row; /*defino variable de una fila de celdafaces como un vector*/

#endif // _NODO_FACE_H_
