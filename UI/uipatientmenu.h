#ifndef UIPATIENTMENU_H
#define UIPATIENTMENU_H

#include "menu.h"

class UIPatientMenu:public Menu
{
    Patient *usuario;
    PatientController patientController;

     CovidTestController covidController;
     CovidTest *covidTest;


public:
    UIPatientMenu();

    void showMainMenu();
    void showPersonalData();
    void showCodivTestResults();
};

#endif // UIPATIENTMENU_H
