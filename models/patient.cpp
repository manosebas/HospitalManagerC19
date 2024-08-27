#include "patient.h"

Patient::~Patient()
{

}

Patient::Patient(int id, string name, string email, string address,string blood)
:User(id,name,email,address)
{
 this->blood = blood;
}

Patient::Patient(string name, string email,string address,string blood)
:User(name,email,address)
{
 this->blood = blood;
}


string Patient::toString(){
    return
                "Paciente: " +
                User::toString()+
                "\n\t tipo de sangre: " + this->blood;
}

string Patient::getblood()
{
    return blood;
}

void Patient::setblood(string blood)
{
    this->blood = blood;
}
