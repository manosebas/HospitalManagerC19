#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;
class User
{

private:
    int id;
    string name;
    string email;
    string address;

public:
    User();
    User(int id, string name, string email, string address);
    User(string name, string email, string address);

    virtual int getId();
    virtual void setId(int id);

    virtual string getName();
    virtual void setName(string name);

    virtual string getAddress();
    virtual void setAddress(string address);

    virtual string getEmail();
    virtual void setEmail(string email);

    virtual  string toString();

};

#endif // USER_H
