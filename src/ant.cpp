#include "ant.h"
#include "city.h"

Ant::Ant(int antNum)
{
    this->_antNum = antNum;
}

double Ant::dealWithData() {

}

int Ant::normalize(s1, s2) {     //turn a pair of store num into the num in store2StoreTau
    if (s1 < s2) {
        return (_storeNum + s1 - 1) * (_storeNum - s1 - 1) / 2 + s2 - s1 - 1;
    } else if (s1 > s2) {
        return (_storeNum + s2 - 1) * (_storeNum - s2 - 1) / 2 + s1 - s2 - 1;
    }
    else return -1;
}
