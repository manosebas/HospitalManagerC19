#include <iostream>
#include "UI/menu.h"
#include "UI/uidoctormenu.h"
#include "UI/uipatientmenu.h"

#include"Controllers/patientcontroller.h"

using namespace std;

void authUser(int userType);
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
Validacion validar;

int main()
{

    cout<<"╔═════════════════════════════════════════╗"<<endl;
    cout<<"\tBIENVENIDO A PRUEBAS DE COVID"<<endl;


    int res = 0;
        do {
        cout<<"Como quieres ingresar?"<<endl;
            cout<<"1. Doctor"<<endl;
            cout<<"2. Paciente"<<endl;
            cout<<"0. Salir"<<endl;
            res = validar.pedirEntero();

            switch (res){
                case 1:
                    cout<<"═════════════ Doctor ═════════════"<<endl;
                    authUser(1);
                    break;

                case 2:
                    cout<<"═════════════ Paciente ═════════════"<<endl;
                    authUser(2);
                    break;

                case 0:
                    res = 0;
                    cout<<endl<<"Gracias por su visita!"<<endl;
                    break;
                default:
                    cout<<"!!Seleccione una opcion correcta!!"<<endl;
            }
        }while (res != 0);


    return 0;
}




void authUser(int userType){

        Menu *displayMenu;

        //simulacion de cuentas de cuentas de doctores
        string doctores[3] = { "kevin@gmail.com","doctor@gmail.com", "karen@gmail.com"};
        bool validLoggin = false;
        string email;

        do {
            if (userType == 1){

                cout<<"Si no estas registrado ingresa como: doctor@gmail.com "<<endl;
                 cout<<"Ingresa tu email:"<<endl;
                 email = validar.pedirtexto();
                for(int i = 0; i < 2; i++){
                     if(doctores[i] == email){
                            validLoggin = true;
                                displayMenu = new UIDoctorMenu();
                                displayMenu->showMainMenu();
                                delete displayMenu;
                                displayMenu =nullptr;
                         break;
                     }
                }
                if(email == "0") break;
                if(validLoggin == false){
                    cout<<"\nIngresa un correo valido!"<<endl;
                    cout<<"0. Para salir al menu anterior"<<endl<<endl;
                }

            }



            if (userType == 2){
                                validLoggin = true;
                                displayMenu = new UIPatientMenu();
                                displayMenu->showMainMenu();
                                delete displayMenu;
                                displayMenu =nullptr;
                         break;
                     }

        }while (!validLoggin);


    }

