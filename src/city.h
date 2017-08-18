#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <map>
#include "singleton.hpp"
using namespace std;

class CCity
{
private:
    int _num;
    pair<int, int> pos;
    map<int, pair<int, int>> city2pos;
public:
    CCity();
    double city2CityDis(int c1, int c2);
    double city2CityEta(int c1, int c2);
    int cityNum() {return _num;}
};

typedef Singleton<CCity> City;
#endif // CITY_H
