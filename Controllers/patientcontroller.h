#ifndef PATIENTCONTROLLER_H
#define PATIENTCONTROLLER_H

#include "controller.h"
#include "models/patient.h"
using namespace std;



class PatientController:public Controller
{
    fstream File;
    vector<Patient> content;
    string fileName = "patientData.csv";

public:


    PatientController();

    void SavePatient(Patient *patient);

    Patient  * getPatient(int id);
    bool ValidpatientsId(int id);

    void showData();


};

#endif // PATIENTCONTROLLER_H
