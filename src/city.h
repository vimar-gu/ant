#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <map>
#include <QObject>
#include "singleton.hpp"
#include "ant.h"
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
    const static int _MAX_STORE = 100;
    const static int _MAX_DRIVER = 100;
    int _storeNum;
    CStore store[_MAX_STORE];
    CDriver driver[_MAX_DRIVER];
signals:
    void needDraw();
public slots:
    void fresh();
public:
    CCity();
    double store2StoreDis(int s1, int s2);
    double store2StoreEta(int s1, int s2);
    void start();
    int storeNum() {return _storeNum;}
};

typedef Singleton<CCity> City;
#endif // CITY_H
