#ifndef COVIDTEST_H
#define COVIDTEST_H
#include "./shared/validacion.h"

#include <iostream>
using namespace std;

class CovidTest{
   private:
        Validacion validar;
        int id;
        float porcentajeContagio;

        int temperaturaCorporal; //38 o mas
        string tos; //frecuente
        int olfato; //del 0 al 10 cuanto huele
        int gusto; // del 0 al 10 cuanto saborea
        int cansancio; // del 0 al 10 que tan cansado
        int dolorGarganta; // 0 al 10
        int dolorCuerpo; // 0 al 10
        int dolorCabeza; // 0 al 10 frecuencia
        int dolorPecho; // le duele el pecho
        string diarrea; // tiene diarrea
        string conjuntivitis; // le pican los ojos



 public:
        int getid();
        void setid(int id);
        float getPorcentajeContagio();
        void setPorcentajeContagio(float contagio);
        void setTemperaturaCorporal(int temperaturaCorporal);
        int getTemperaturaCorporal();
        void setTos(string tos);
        string getTos();
        void setOlfato(int olfato);
        int getOlfato();
        void setGusto(int gusto);
        int getGusto();
        void setCansancio(int cansancio);
        int getCansancio();
        void setDolorGarganta(int dolorGarganta);
        int getDolorGarganta();
        void setDolorCuerpo(int dolorCuerpo);
        int getDolorCuerpo();
        void setDolorCabeza(int dolorCabeza);
        int getDolorCabeza();
        void setDolorPecho(int dolorPecho);
        int getDolorPecho();
        void setDiarrea(string diarrea);
        string getDiarrea();
        void setConjuntivitis(string conjuntivitis);
        string getConjuntivitis();




        CovidTest();

         void menu(CovidTest *paciente);
        float posibilidad(CovidTest *paciente);


};
#endif // COVIDTEST_H
