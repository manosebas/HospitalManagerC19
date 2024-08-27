#include "doctor.h"


Doctor::Doctor(int id, string name, string email, string address,string specialty)
:User(id,name,email,address)
{
    this->specialty = specialty ;

}

Doctor::Doctor(string name, string email, string address, string specialty)
:User(name,email,address)
{
    this->specialty = specialty ;
}


