#ifndef ANT_H
#define ANT_H
#include <iostream>
#include <vector>
#include "city.h"
using namespace std;

class Ant
{
private:
    int _maxLoop;
    int _antNum;
    int _storeNum;
    int _routeNum;
    double _enFactor = 0.5;
    double _deFactor = 0.5;
    vector<double> _store2StoreTau;
    vector<int> _bestRouteRec;
public:
    Ant(int antNum, int loopNum);
    ~Ant();
    vector<int> dealWithData();
    int normalize(int s1, int s2);
};

struct TempList {
    TempList(int n) {
        for (int i = 0; i < n;i++) {
            list.push_back(i);
        }
    }
    vector<int> list;
};

#endif // PATH_H
