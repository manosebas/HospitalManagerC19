#ifndef PATIENT_H
#define PATIENT_H

#include "user.h"

class Patient: public User
{
private:
    string blood;
public:
    virtual ~Patient();
    Patient(int id, string name, string email, string address ,string blood);
    Patient( string name, string email, string ,string blood);
    string toString();

    string getblood();
    void setblood(string blood);
};

#endif // PATIENT_H
