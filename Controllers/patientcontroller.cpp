#include "patientcontroller.h"


PatientController::PatientController()
{
    fstream ValidarArchivo(fileName,ios::in);
    if(!ValidarArchivo){
    fstream CreateFile(fileName,ios::out);
    CreateFile<<"Id,Nombre,Email,Direccion,TipoSangre"<<endl;
    }

}



void PatientController::SavePatient(Patient *patient)
{

     cout << "\nPaciente: [id:" <<patient->getId()
                            <<", name: "<<patient->getName()
                            <<", email: "<<patient->getEmail()
                           <<", address: "<<patient->getAddress()
                          <<", blood: "<<patient->getblood()
                             <<"]"<<endl;


    //obtenemos numero de lineas que ya estan escritas y no debemos tomar en cuenta
    File.open(fileName);
     int cuenta=0;
     string line;
     vector<string> lineas;
    while(getline(File,line)){
              ++cuenta;
              lineas.push_back(line);
              }
    File.close();


    File.open(fileName);
    if(!File.is_open()) cout<<"ERROR: Abrir archivo"<<endl;


    if (File.is_open()) {
        int id = patient->getId();
        string name = patient->getName();
        string email = patient->getEmail();
        string address = patient->getAddress();
        string blood = patient->getblood();




        do{
            for(int i = 0; i<cuenta;++i){
            File<<lineas[i]<<endl; //sobreescribimos las lineas y al final ponemos la nueva
                if(i == cuenta-1){
                    File<<to_string(id)<< ","<<name<<","<<email<<","<<address<<","<<blood<<endl;
                }
            }

            cout<<"!!Guardado con exito!!"<<endl<<endl;
        }while(false);
    }else{
    cout<<"Error al abrir archivo";
    }
    File.close();

}


Patient * PatientController::getPatient(int id)
{
        string line ;
        vector<string> patientData;

        File.open(fileName);
        if(!File.is_open()) cout<<"ERROR: Abrir archivo"<<endl;
        while(getline(File,line))
        {
        patientData= split(line,",");
         if(patientData[0] == "Id" || patientData[0] == "0" || patientData[0] == "" )continue;
         if(patientData[0]== to_string(id)){
         break;
         }
        }
        File.close();

        Patient *patient = new  Patient(stoi(patientData[0]),patientData[1],patientData[2],patientData[3],patientData[4]);
        return  patient;
}

bool PatientController::ValidpatientsId(int id)
{
     File.open(fileName);
     if(!File.is_open()) cout<<"ERROR: Abrir archivo"<<endl;
     string line;
     string ids;
    vector<int> patientsId;

    while(getline(File,line))
        {
        ids = splitId(line,",");
        if(ids == "Id")continue;

        try{
            patientsId.push_back(stoi(ids));
        } catch (...) {
        continue;
        }

         }
         File.close();

         vector<int >::iterator it;
         for (it = patientsId.begin();
                 it != patientsId.end();
                 it++) {

                  if(*it == id){
                      return true;
                  }
          }

    return false;
}




void PatientController::showData()
{
        cout<<"=============================="<<endl;
        cout<<"\tPACIENTES"<<endl;

        File.open(fileName);
        if(!File.is_open()) cout<<"ERROR: Abrir archivo"<<endl;

        string id;
        string name;
        string email;
        string address;
        string blood;
        vector<string> data;

        string line;
         while (getline(File, line)) {
                 try{

                 data = split(line,",");
                 if(data[0] == "Id")continue;

                    id= data[0];
                    name = data[1];
                    email = data[2];
                    address = data [3];
                    blood = data [4];

                    cout << "Paciente: [id:" <<id
                            <<", name: "<<name
                            <<", email: "<<email
                           <<", address: "<<address
                          <<", blood: "<<blood
                             <<"]"<<endl;
            } catch (...) {
                cout<<"Error garda dato de paciente"<<endl;
                continue;
                }
        }
          this->File.close();
          cout<<"=============================="<<endl;
}

