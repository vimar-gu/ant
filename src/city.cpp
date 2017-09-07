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
        dataStream >> store[storeCount]._x >> store[storeCount]._y;
        qDebug() << storeCount << store[storeCount].x() << store[storeCount].y();
        storeCount++;
    }
    _storeNum = storeCount - 1;
    qDebug() << store2StoreDis(0, 1);

    data.close();
}

double CCity::store2StoreDis(int s1, int s2) {
    if (s1 != s2) {
        double xDis = store[s1].x() - store[s2].x();
        double yDis = store[s1].y() - store[s2].y();
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
    Ant tempAnt(10);
    tempAnt.dealWithData();

    emit needDraw();
}
