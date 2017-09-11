#include <QDebug>
#include "ant.h"
#include "city.h"

Ant::Ant(int antNum, int loopNum) {
    _storeNum = City::instance()->storeNum();
    _maxLoop = loopNum;
    qDebug() << _storeNum;
    _routeNum = _storeNum*(_storeNum - 1) / 2;
    this->_antNum = antNum;

    _store2StoreTau.resize(_storeNum * (_storeNum - 1) / 2);
    _store2StoreTau.clear();
}

int Ant::normalize(int s1, int s2) {     //turn a pair of store num into the num in store2StoreTau
    if (s1 < s2) {
        return s1 * (_storeNum * 2 - s1 - 1) / 2 + s2 - s1 - 2;
    } else if (s1 > s2) {
        return s2 * (_storeNum * 2 - s2 - 1) / 2 + s1 - s2 - 2;
    }
    else return -1;
}

double Ant::dealWithData() {
    vector<vector<int>> routeRec;

    //input the info of stores
    vector<int> randPosList;
    vector<int>::iterator it;
    int turn = ceil(_antNum / _storeNum);
    for (int i = 0; i < turn; i++) {
        TempList tempList(_storeNum);
        for (int j = 0; j < _storeNum; j++) {
            int randPos = tempList.list[rand() % tempList.list.size()];
            it = find(tempList.list.begin(), tempList.list.end(), randPos);
            tempList.list.erase(it);
            randPosList.push_back(randPos);
        }
    }
    routeRec.push_back(randPosList);
    qDebug() << routeRec.size();

    //start main loop
    for (int cnt = 0; cnt < _maxLoop; cnt++) {
        for (int i = 1; i < _storeNum; i++) {
            vector<int> toVisit;
            for (int j = 0; j < _antNum; j++) {
                //add wait list for unvisited cities
                vector<int> waitList;
                for (int k = 0; k < _storeNum; k++) {
                    waitList.push_back(k);
                }
                for (int k = 0; k < i; k++) {
                    vector<int> visited = routeRec[k];
                    it = find(waitList.begin(), waitList.end(), visited[j]);
                    waitList.erase(it);
                }
                qDebug() << waitList;

                //calculate the probability of every unvisited city
                vector<double> probability;
                probability.resize(waitList.size());
                vector<int> currentPos = routeRec[i - 1];
                for (unsigned int k = 0; k < probability.size(); k++) {
                    probability[k] = (store2StoreTau(currentPos[j], waitList[k])) * 0.5
                            + (City::instance()->store2StoreEta(currentPos[j], waitList[k])) * 0.5; //currently
                }

                int maxPos = distance(probability.begin(), max_element(probability.begin(), probability.end()));
                toVisit.push_back(waitList[maxPos]);
            }
            routeRec.push_back(toVisit);
        }
    }
    return -1;
}

double Ant::store2StoreTau(int s1, int s2) {
    return _store2StoreTau[normalize(s1, s2)];
}
