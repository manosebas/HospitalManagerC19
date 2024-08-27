#ifndef DOCTOR_H
#define DOCTOR_H

#include "user.h"

class Doctor:public User
{
private:
    string specialty;
public:
    Doctor(int id, string name, string email, string address,string specialty);
    Doctor(string name, string email, string address,string specialty);

};

#endif // DOCTOR_H
