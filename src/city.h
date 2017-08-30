#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <map>
#include <QObject>
#include "singleton.hpp"
using namespace std;

struct CStore {
    double _x;
    double _y;
    double x() {return _x;}
    double y() {return _y;}
};

struct CDriver {
    double _x;
    double _y;
    double x() {return _x;}
    double y() {return _y;}
};

class CCity : public QObject {
    Q_OBJECT
private:
    const static int _MAX_CITY = 100;
    const static int _MAX_DRIVER = 100;
    int _num;
    CStore store[_MAX_CITY];
    CDriver driver[_MAX_DRIVER];
signals:
    void needDraw();
public slots:
    void fresh();
public:
    CCity();
    double city2CityDis(int c1, int c2);
    double city2CityEta(int c1, int c2);
    void start();
    int cityNum() {return _num;}
};

typedef Singleton<CCity> City;
#endif // CITY_H
