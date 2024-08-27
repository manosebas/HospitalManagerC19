#include "uipatientmenu.h"
#include <iostream>
using namespace std;

UIPatientMenu::UIPatientMenu()
{
    //Cargar datos del paciente con controlador

}

void UIPatientMenu::showMainMenu()
{
    int res =  0;
    int id;
    cout<<"Ingresa tu id:"<<endl;
    id =validar.pedirEntero();
    if(patientController.ValidpatientsId(id)){
        this->usuario = patientController.getPatient(id);

        cout<<"═══════ Bienvenido " <<usuario->getName()<<" ═══════"<<endl;
            do{
                cout<<"\n 1. Ver mi información Personal"<<endl;
                cout<<" 2. Ver resultados del test de Covid  "<<endl;
                cout<<" 0. Cerrar sesión"<<endl;
                res =validar.pedirEntero();
                switch (res) {
                        case 1:
                             showPersonalData();
                            break;


                        case 2:
                            //resultados test covid
                            showCodivTestResults();
                            break;


                        case 0:
                            cout<<"!────────Sesión cerrada────────!"<<endl<<endl;

                            break;
                     default:
                        cout<<"Seleccione una opcion correcta"<<endl;
                    }
                }while(res != 0);


            }else{
            cout<<"!────────Ingresa tu id correctamente────────!"<<endl<<endl;
    }

}


void UIPatientMenu::showPersonalData()
{
    cout<<usuario->toString();
}


void UIPatientMenu::showCodivTestResults()
{

    if(covidController.ValidTestId(this->usuario->getId())){
        covidTest = covidController.getTest(this->usuario->getId());

        cout<<"La probabilidad de que tengas covid es de: ["<<covidTest->posibilidad(covidTest)<<"]\n";
    }else{
    cout<<"Todavia no te haz hecho una prueba de covid!!"<<endl<<endl;
    }
}

