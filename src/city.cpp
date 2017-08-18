#include "city.h"
#include <math.h>

CCity::CCity()
{

}

double CCity::city2CityDis(int c1, int c2) {
    if (c1 != c2) {
        double xDis = city2pos.at(c1).first - city2pos.at(c2).first;
        double yDis = city2pos.at(c1).second - city2pos.at(c2).second;
        return sqrt(pow(xDis, 2) + pow(yDis, 2));
    }
    else return 0.001;
}

double CCity::city2CityEta(int c1, int c2) {
    return 1 / city2CityDis(c1, c2);
}
