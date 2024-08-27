#include "controller.h"
using namespace std;

Controller::Controller()
{

}

vector<string>  Controller::split(string s, string del)
{
    vector<string> results;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        results.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    results.push_back( s.substr(start, end - start));
    return results;
}


string Controller::splitId(string s, string del)
{
    int end = s.find(del);
    return  s.substr(0,end);
}
