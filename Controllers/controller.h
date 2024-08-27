#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Controller
{
public:
    Controller();

    vector<string> split(string s, string del);
    string splitId(string s, string de);
};

#endif // CONTROLLER_H
