#ifndef COVIDTESTCONTROLLER_H
#define COVIDTESTCONTROLLER_H
#include "controller.h"
#include "models/covidtest.h"
class CovidTestController:public Controller
{
    fstream File;
    vector<CovidTest> content;
    string fileName = "covidTest.csv";
public:
    CovidTestController();

    void SaveTest(CovidTest *test);

    CovidTest  * getTest(int id);
    bool ValidTestId(int id);

    void showData();
};

#endif // COVIDTESTCONTROLLER_H
