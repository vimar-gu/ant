#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <map>
#include <QObject>
#include "singleton.hpp"
#include "ant.h"
using namespace std;

struct pos {
    double _x;
    double _y;
    double x() {return _x;}
    double y() {return _y;}
};

struct CStore {
    pos _pos;
    double x() {return _pos.x();}
    double y() {return _pos.y();}
};

struct CDriver {
    pos _pos;
    int tempPos;
    double x() {return _pos.x();}
    double y() {return _pos.y();}
};

class CCity : public QObject {
    Q_OBJECT
private:
    const static int _MAX_STORE = 100;
    const static int _MAX_DRIVER = 100;
    int _storeNum;
    int _driverNum = 1; //waiting to be changed with regex
    CStore _store[_MAX_STORE];
    CDriver _driver[_MAX_DRIVER];
signals:
    void needDraw();
public slots:
    void fresh();
public:
    CCity();
    double store2StoreDis(int s1, int s2);
    double store2StoreEta(int s1, int s2);
    CStore& store(int n) {return _store[n];}
    CDriver& driver(int n) {return _driver[n];}
    void start();
    void clearStore(int i);
    int storeNum() {return _storeNum;}
    int driverNum() {return _driverNum;}
};

typedef Singleton<CCity> City;
#endif // CITY_H
