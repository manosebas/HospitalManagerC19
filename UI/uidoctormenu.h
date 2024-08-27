#ifndef UIDOCTORMENU_H
#define UIDOCTORMENU_H
#include "menu.h"

class UIDoctorMenu:public Menu
{
    private:
        PatientController patientController;
        Patient *paciente;

        CovidTestController covidController;
        CovidTest *covidTest;

    public:
        UIDoctorMenu();
        void showMainMenu();

        void addNewPacient();
        void attendPatient();
        void showAllPatients();


};

#endif // UIDOCTORMENU_H
