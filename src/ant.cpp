#include "ant.h"
#include "city.h"

Ant::Ant(int antNum)
{
    cityNum = City::instance()->cityNum();
    this->antNum = antNum;
}
