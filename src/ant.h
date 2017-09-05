#ifndef ANT_H
#define ANT_H
#include <iostream>
#include <vector>
#include "city.h"
using namespace std;

class Ant
{
private:
    int _storeNum = City::instance()->storeNum();
    int _routeNum = _storeNum*(_storeNum - 1) / 2;
    vector<int> _store2StoreTau;
    int _antNum;
public:
    Ant(int antNum);
    double dealWithData();
    int normalize(s1, s2);
};

#endif // PATH_H
