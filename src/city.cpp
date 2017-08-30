#include <QDebug>
#include "city.h"
#include <math.h>
#include <sys/time.h>
#include <iostream>
#include <QTimer>
using namespace std;

CCity::CCity()
{

}

double CCity::city2CityDis(int c1, int c2) {
    if (c1 != c2) {
        double xDis = store[c1].x() - store[c2].x();
        double yDis = store[c1].y() - store[c2].y();
        return sqrt(pow(xDis, 2) + pow(yDis, 2));
    }
    else return 0.001;
}

double CCity::city2CityEta(int c1, int c2) {
    return 1 / city2CityDis(c1, c2);
}

void CCity::start() {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(fresh()));
    timer->start(1000);
}

void CCity::fresh() {
    emit needDraw();
}
