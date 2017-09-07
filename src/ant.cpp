#include <QDebug>
#include "ant.h"
#include "city.h"

Ant::Ant(int antNum)
{
    _storeNum = City::instance()->storeNum();
    qDebug() << _storeNum;
    _routeNum = _storeNum*(_storeNum - 1) / 2;
    this->_antNum = antNum;
}

int Ant::normalize(int s1, int s2) {     //turn a pair of store num into the num in store2StoreTau
    if (s1 < s2) {
        return (_storeNum + s1 - 1) * (_storeNum - s1 - 1) / 2 + s2 - s1 - 1;
    } else if (s1 > s2) {
        return (_storeNum + s2 - 1) * (_storeNum - s2 - 1) / 2 + s1 - s2 - 1;
    }
    else return -1;
}

double Ant::dealWithData() {
    vector<int> randPosList;
    vector<int>::iterator it;
    int turn = ceil(_antNum / _storeNum);
    for (int i = 0; i < turn; i++) {
        TempList tempList(_storeNum);
        cerr << endl;
        for (int j = 0; j < _storeNum; j++) {
            int randPos = tempList.list[rand() % tempList.list.size()];
            it = find(tempList.list.begin(), tempList.list.end(), randPos);
            tempList.list.erase(it);
            randPosList.push_back(randPos);
        }
    }
    return -1;
}
