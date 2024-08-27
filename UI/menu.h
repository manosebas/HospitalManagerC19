#ifndef MENU_H
#define MENU_H
#include "./models/doctor.h"
#include "./models/patient.h"
#include "./models/covidtest.h"
#include "./Controllers/patientcontroller.h"
#include "./Controllers/covidtestcontroller.h"

#include "./shared/validacion.h"


class Menu
{

public:
    Validacion validar;
    virtual ~Menu();
    Menu();
    virtual void showMainMenu();
    virtual void showUserLoggedInfo();

};

#endif // MENU_H
