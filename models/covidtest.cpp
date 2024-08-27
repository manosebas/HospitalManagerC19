#include "covidtest.h"
#include <iostream>
using namespace std;


CovidTest::CovidTest(){
    temperaturaCorporal = 37;
    tos = "No";
    olfato = 0;
    gusto = 0;
    cansancio = 0;
    dolorGarganta = 0;
    dolorCuerpo = 0;
    dolorCabeza = 0;
    dolorPecho = 0;
    diarrea = "No";
    conjuntivitis = "No";
}


int CovidTest::getid()
{
    return id;
}

void CovidTest::setid(int id)
{
    this->id = id;
}

float CovidTest::getPorcentajeContagio()
{
    return porcentajeContagio;
}

void CovidTest::setPorcentajeContagio(float contagio)
{
    this->porcentajeContagio = contagio;
}

void CovidTest::setTemperaturaCorporal(int temperaturaCorporal){
    this->temperaturaCorporal = temperaturaCorporal;
}
int CovidTest::getTemperaturaCorporal(){
    return temperaturaCorporal;
}
void CovidTest::setTos(string tos){
    this->tos = tos;
}
string CovidTest::getTos(){
    return tos;
}
void CovidTest::setOlfato(int olfato){
    this->olfato = olfato;
}
int CovidTest::getOlfato(){
    return olfato;
}
void CovidTest::setGusto(int gusto){
    this->gusto = gusto;
}
int CovidTest::getGusto(){
    return gusto;
}
void CovidTest::setCansancio(int cansancio){
    this->cansancio = cansancio;
}
int CovidTest::getCansancio(){
    return cansancio;
}
void CovidTest::setDolorGarganta(int dolorGarganta){
    this->dolorGarganta = dolorGarganta;
}
int CovidTest::getDolorGarganta(){
    return dolorGarganta;
}
void CovidTest::setDolorCuerpo(int dolorCuerpo){
    this->dolorCuerpo = dolorCuerpo;
}
int CovidTest::getDolorCuerpo(){
    return dolorCuerpo;
}
void CovidTest::setDolorCabeza(int dolorCabeza){
    this->dolorCabeza = dolorCabeza;
}
int CovidTest::getDolorCabeza(){
    return dolorCabeza;
}
void CovidTest::setDolorPecho(int dolorPecho){
    this->dolorPecho=dolorPecho;
}
int CovidTest::getDolorPecho(){
    return dolorPecho;
}
void CovidTest::setDiarrea(string diarrea){
    this->diarrea = diarrea;
}
string CovidTest::getDiarrea(){
    return diarrea;
}
void CovidTest::setConjuntivitis(string conjuntivitis){
    this->conjuntivitis = conjuntivitis;
}
string CovidTest::getConjuntivitis(){
    return conjuntivitis;
}

void CovidTest::menu(CovidTest *paciente){
    string validText[2] = {"si","no"};
    cout << "\n*** Se le presentarán una serie de preguntas para respoder y aproximar posble contagio del COVID-19 ***"<<endl;
    cout << "Escriba su temperatura corporal en grados Celcius: ";
    temperaturaCorporal = validar.pedirEntero(30,50);
    paciente->setTemperaturaCorporal(temperaturaCorporal);
    cout << "Tiene tos frecuentemente? (Si/No): ";
    tos = validar.pedirtexto(validText);
    paciente->setTos(tos);
    cout << "Presenta diarrea? (Si/No): ";
    diarrea = validar.pedirtexto(validText);
    paciente->setDiarrea(diarrea);
    cout << "Le pican los ojos frecuentemente (Conjuntivitis)? (Si/No): ";
   conjuntivitis = validar.pedirtexto(validText);
    paciente->setConjuntivitis(conjuntivitis);
    cout << "Del 0 al 10 que tanto considera que ah perdido el olfato? (10 siendo que no huele nada): ";
    olfato = validar.pedirEntero(0,10);
    paciente->setOlfato(olfato);
    cout << "Del 0 al 10 que tanto considera que ah perdido el gusto? (10 siendo que no saborea nada): ";
    gusto = validar.pedirEntero(0,10);
    paciente->setGusto(gusto);
    cout << "Del 0 al 10 que tan cansado se siente? (10 siendo demasiado cansado): ";
    cansancio = validar.pedirEntero(0,10);
    paciente->setCansancio(cansancio);
    cout << "Del 0 al 10 cuanto le duele la garganta (10 siendo que le duele mucho): ";
    dolorGarganta = validar.pedirEntero(0,10);
    paciente->setDolorGarganta(dolorGarganta);
    cout << "Del 0 al 10 cuanto le duele el cuerpo (10 siendo que le duele mucho): ";
    dolorCuerpo = validar.pedirEntero(0,10);
    paciente->setDolorCuerpo(dolorCuerpo);
    cout << "Del 0 al 10 cuanto le duele el pecho (10 siendo que le duele mucho): ";
   dolorPecho = validar.pedirEntero(0,10);
    paciente->setDolorPecho(dolorPecho);
    cout << "Del 0 al 7 con cuanta frecuencia le duele la cabeza (7 siendo que le duele todos los días de la semana): ";
    dolorCabeza = validar.pedirEntero(0,7);
    paciente->setDolorCabeza(dolorCabeza);

    this->posibilidad(paciente);
}

float CovidTest::posibilidad(CovidTest *paciente){
    float puntos = 0.0;
    float porcentaje = 0.0;

    if (paciente->getTemperaturaCorporal() >= 37 and paciente->getTemperaturaCorporal() <= 38){
        puntos += 5;
    }else if (paciente->getTemperaturaCorporal() > 38){
        puntos += 10;
    }

    if (paciente->getTos() == "Si" or paciente->getTos() == "si"){
        puntos = puntos + 10;
    }

    if (paciente->getDiarrea() == "Si" or paciente->getDiarrea() == "si"){
        puntos = puntos + 10;
    }

    if (paciente->getConjuntivitis() == "Si" or paciente->getConjuntivitis() == "si"){
        puntos = puntos + 10;
    }

    puntos = puntos + paciente->getOlfato() + paciente->getGusto() + paciente->getCansancio() + paciente->getDolorGarganta() +
            paciente->getDolorCuerpo() + paciente->getDolorCabeza() + paciente->getDolorPecho();

    porcentaje = (puntos * 100)/107; //107 siendo puntaje maximo

    this->porcentajeContagio = porcentaje;
    return porcentaje;
}



