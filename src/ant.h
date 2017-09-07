#ifndef ANT_H
#define ANT_H
#include <iostream>
#include <vector>
#include "city.h"
using namespace std;

class Ant
{
private:
    int _storeNum;
    int _routeNum;
    vector<int> _store2StoreTau;
    int _antNum;
public:
    Ant(int antNum);
    double dealWithData();
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
