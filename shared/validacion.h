#ifndef VALIDACION_H
#define VALIDACION_H


#include <iostream>
using namespace std;



class Validacion{

    public:
    bool tipoIntValido(string);
    int pedirEntero();
    int pedirEntero(int start,int end);

    bool tipoCharValido(string);
    string pedirtexto();
    string pedirtexto(string texto[]);

    string aMinuscula(string cadena);
};

#endif // VALIDACION_H
