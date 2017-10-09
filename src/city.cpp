#include <QDebug>
#include "city.h"
#include <math.h>
#include <sys/time.h>
#include <iostream>
#include <QTimer>
#include <QTextStream>
#include <QFile>
#include <QString>
using namespace std;
QString DATA_DIR = "/home/ypbehere/Documents/srtp/ant1/Ant/data/data.txt";

CCity::CCity()
{
    QFile data(DATA_DIR);
    if (!data.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cout << "Open failed." << endl;
    }

    QTextStream dataStream(&data);
    int storeCount = 0;
    while(!dataStream.atEnd())
    {
        dataStream >> _store[storeCount]._x >> _store[storeCount]._y;
        storeCount++;
    }
    _storeNum = storeCount - 1;

    for (int i = 0; i < _driverNum; i++) {
        _driver[i]._x = 5;
        _driver[i]._y = 5;
    }

    data.close();
}

double CCity::store2StoreDis(int s1, int s2) {
    if (s1 != s2) {
        double xDis = _store[s1].x() - _store[s2].x();
        double yDis = _store[s1].y() - _store[s2].y();
        return sqrt(pow(xDis, 2) + pow(yDis, 2));
    }
    else return 0.001;
}

double CCity::store2StoreEta(int s1, int s2) {
    return 1 / store2StoreDis(s1, s2);
}

void CCity::start() {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(fresh()));
    timer->start(1000);
}

void CCity::fresh() {
    Ant tempAnt(10, 1);
    double tmp = tempAnt.dealWithData();

    emit needDraw();
}
