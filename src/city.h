#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <map>
#include "singleton.hpp"
using namespace std;

class CCity
{
private:
    int n;
    pair<int, int> pos;
    map<int, pair<int, int>> city2pos;
public:
    CCity();
    double calcCity2CityDis(int city);
    double calcCity2CityEta(int city);
};

typedef Singleton<CCity> City;
#endif // CITY_H
