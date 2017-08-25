#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <map>
#include <QObject>
#include "singleton.hpp"
using namespace std;

class CCity : public QObject {
    Q_OBJECT
private:
    int _num;
    pair<int, int> pos;
    map<int, pair<int, int>> city2pos;
signals:
    void needDraw();
public:
    CCity();
    double city2CityDis(int c1, int c2);
    double city2CityEta(int c1, int c2);
    void fresh();
    int cityNum() {return _num;}
};

typedef Singleton<CCity> City;
#endif // CITY_H
