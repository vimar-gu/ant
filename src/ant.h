#ifndef ANT_H
#define ANT_H
#include <iostream>
#include <map>
using namespace std;

class Ant
{
private:
    int cityNum;
    int antNum;
    map<pair<int, int>, int> city2CityTau;
public:
    Ant(int antNum);
    double dealWithData();
};

#endif // PATH_H
