#include "validacion.h"
using namespace std;

int Validacion::pedirEntero(){
    string numero;
    bool esValido = false;

    while(! esValido){
        numero = "";
        try {

            getline(cin, numero);
            esValido = tipoIntValido(numero);

            if(! esValido)
                throw numero;
        } catch (string numero) {
            cout << "Lo ingresado ( "<< numero << " ) no es valido, intente otra vez..."<<endl;
        }

    }
    return stoi(numero);
}


int Validacion::pedirEntero(int start,int end){
    string numero;
    bool esValido = false;

    while(! esValido){
        numero = "";
        try {
            getline(cin, numero);
            esValido = tipoIntValido(numero);
            if(! esValido)
                throw numero;
            if(stoi(numero)<start || stoi(numero)>end){
                esValido = false;
                throw numero;
            }
        } catch (string numero) {
            cout << "Lo ingresado ( "<< numero << " ) no es valido, debe ser un número entre "<<start<<" - "<<end<<" intente otra vez..."<<endl;
        }
    }
    return stoi(numero);
}


bool Validacion::tipoIntValido(string numero){
    int inicio = 0;


    if(numero.length() == 0){ //espacio vacio
        return 0;
    }

    if(numero[0] == '+' or numero[0]== '-'){
        inicio = 1;
        if(numero.length() == 1){ //solo es un signo
            return 0;
        }
    }

    for(int i=inicio; i < numero.length(); i++){
        if(! isdigit(numero[i])){
            return 0;
        }
    }
    return 1;
}


string Validacion::pedirtexto(){
    string caracter;
    bool esValido = false;


    while(! esValido){
        caracter ="";
        try {
            getline(cin, caracter);
            esValido = tipoCharValido(caracter);
            if(! esValido)
                throw caracter;
        } catch (string caracter) {
            cout << "Lo ingresado ( "<< caracter << " ) no es valido, intente otra vez..."<<endl;
        }
    }
    return caracter;
}


string Validacion::pedirtexto(string texto[]){
    string caracter;
    bool esValido = false;


    while(! esValido){
        caracter ="";
        try {
            getline(cin, caracter);
            esValido = tipoCharValido(caracter);
            if(! esValido)
                throw caracter;

            caracter  = aMinuscula(caracter);
            esValido = false;

            for (int i = 0; i < texto->length(); i++) {
              string textoActual = texto[i];

              if (textoActual == caracter) {
                    esValido = true;
                    break;
              }
            }
            if(!esValido) throw caracter;


        } catch (string caracter) {
            cout << "Lo ingresado ( "<< caracter << " ) no es valido, intente otra vez..."<<endl;
        }
    }
    return aMinuscula(caracter);
}


bool Validacion::tipoCharValido(string caracter){
    if(caracter.length() == 0){ //espacio vacio
            return 0;
    }

        if(! isalpha(caracter[0])){
            return 0;
    }
    return 1;
    }


string Validacion::aMinuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++) {
  cadena[i] = tolower(cadena[i]);

  }
  return cadena;
}
