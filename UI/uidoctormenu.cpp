#include "uidoctormenu.h"
#include <iostream>

using namespace std;

UIDoctorMenu::UIDoctorMenu()
{

}

void UIDoctorMenu::showMainMenu()
{
     cout<<"════════ Bienvenido Doctor ════════" <<endl;
     int res =  0;
            do{
            cout<<"\t╔ 1. Añadir nuevo Paciente"<<endl;
            cout<<"\t╠ 2. Atender a paciente Registrado"<<endl;
            cout<<"\t╠ 3. Mostrar todos los pacientes"<<endl;
            cout<<"\t╚ 0. Cerrar sesión"<<endl;
            res =validar.pedirEntero();
                switch (res) {
                    case 1:
                        this->addNewPacient();

                        break;
                    case 2:
                        this->attendPatient();
                        break;
                    case 3:
                        this->showAllPatients();
                        break;

                    case 0:
                        cout<<"!────Sesión cerrada────!"<<endl<<endl;
                        break;
                 default:
                    cout<<"Seleccione una opcion correcta"<<endl;
                }
            }while( res != 0);

}

void UIDoctorMenu::addNewPacient()
{
            int id;
            string name;
            string email;
            string address;
            string blood;

            cout<<"────────REGISTRAR NUEVO PACIENTE────────" <<endl;
            cout<<"Identidicacion del paciente: ";
            id = validar.pedirEntero();
            if(!patientController.ValidpatientsId(id)){
                cout<<"Nombre del paciente: ";
                name = validar.pedirtexto();

                cout<<"Email del paciente: ";
                email = validar.pedirtexto();

                cout<<"Direccion del paciente: ";
               address = validar.pedirtexto();
                cout<<"Tipo de sangre del paciente: ";
                blood = validar.pedirtexto();

                paciente = new Patient(id,name,email,address,blood);
                patientController.SavePatient(paciente);
            }else {
                cout<<"Ya existe un paciente con este id ["<<id<<"]"<<endl;
            }

            delete paciente;
            paciente = nullptr;

//aqui no debo sobre escribir el paciente
//            paciente = new Patient(id,name,email,address,blood) ;
//            patientController.SavePatient(paciente);

//            delete paciente;
//            paciente = nullptr;

}


void UIDoctorMenu::attendPatient()
{
        cout<<"────────ATENDER PACIENTE────────" <<endl;
        int res = 0;
        int id;
        cout<<"Identificacion del paciente: ";
        id = validar.pedirEntero();



        if (patientController.ValidpatientsId(id)){

        paciente = patientController.getPatient(id);
            do{

                cout<<endl<<"\t╔  1. Mostrar información del paciente"<<endl;
                cout<<"\t╠  2. Hacer Prueba Covid-19"<<endl;
                cout<<"\t╚  0. Salir al menu anterior"<<endl;
                res = validar.pedirEntero();
                    switch (res) {
                        case 1:
                            cout<<paciente->toString()<<endl;
                            break;
                        case 2:
                            if (!covidController.ValidTestId(id)){

                                covidTest = new CovidTest;
                                covidTest->menu(this->covidTest);
                                cout<<"probabilidad es de "<<this->covidTest->posibilidad(this->covidTest)<<endl;
                                covidTest->setid(paciente->getId());
                                covidController.SaveTest(this->covidTest);
                            }else{
                            cout<<"El paciente ["<<paciente->getName()<<"] ya se hizo el test de Covid!"<<endl<<endl;
                            covidTest = covidController.getTest(paciente->getId());
                            cout<<"La probabilidad de que tenga covid es de: ["<<covidTest->posibilidad(covidTest)<<"]\n";
                            }

                            delete covidTest;
                            covidTest =nullptr;

                            break;
                        case 0:
                            break;
                     default:
                        cout<<"Seleccione una opcion correcta"<<endl;
                    }
                }while( res != 0);
                delete paciente;
                paciente = nullptr;
        }else{
            cout<<"Ingrese un id de un paciente existente!"<<endl;
        }


}



void UIDoctorMenu::showAllPatients()
{
        patientController.showData();

}


