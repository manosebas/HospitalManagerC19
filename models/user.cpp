#include "user.h"

User::User(int id,string name, string email,string address)
:id(id),name(name),email(email),address(address)
{
}

User::User(string name, string email, string address)
:name(name),email(email),address(address)
{

}


int User::getId(){
    return id;
}

void User::setId(int id){
    this->id = id;
}

string User::getName(){
    return name;
}

void User::setName(string name){
    this->name = name;
}

string User::getAddress(){
    return address;
}

void User::setAddress(string address){
    this->address = address;
}

string User::getEmail(){
    return email;
}

void User::setEmail(string email){
    this->email = email;
}

string User::toString()
{
    return
            "\n\t Nombre: " + this->name +
            "\n\t Identificación: " + to_string(this->id) +
            "\n\t Email: " + this->email +
            "\n\t Dirección: " + this->address ;
}

