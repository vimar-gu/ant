#include <QDebug>
#include "ant.h"
#include "city.h"

Ant::Ant(int antNum, int loopNum) {
    _storeNum = City::instance()->storeNum();
    _maxLoop = loopNum;
    qDebug() << _storeNum;
    _routeNum = _storeNum*(_storeNum - 1) / 2;
    this->_antNum = antNum;
    _store2StoreTau.resize(_routeNum);
    for (int i = 0; i < _routeNum; i++) {
        _store2StoreTau[i] = 0;
    }
}

Ant::~Ant() {
    vector<double>().swap(_store2StoreTau);
    vector<int>().swap(_bestRouteRec);
}

int Ant::normalize(int s1, int s2) {     //turn a pair of store num into the num in store2StoreTau
    if (s1 < s2) {
        return s1 * (_storeNum * 2 - s1 - 1) / 2 + s2 - s1 - 1;
    } else if (s1 > s2) {
        return s2 * (_storeNum * 2 - s2 - 1) / 2 + s1 - s2 - 1;
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

        //generate route
        for (int i = 1; i < _storeNum; i++) {
            vector<int> toVisit;
            for (int j = 0; j < _antNum; j++) {
                //add wait list for unvisited stores
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

                //calculate the probability of every unvisited store
                vector<double> probability;
                probability.resize(waitList.size());
                vector<int> currentPos = routeRec[i - 1];
                for (unsigned int k = 0; k < probability.size(); k++) {
                    probability[k] = (_store2StoreTau[normalize(currentPos[j], waitList[k])]) * 0.5
                            + (City::instance()->store2StoreEta(currentPos[j], waitList[k])) * 0.5; //currently
                }

                int maxPos = distance(probability.begin(), max_element(probability.begin(), probability.end()));
                toVisit.push_back(waitList[maxPos]);
            }
            routeRec.push_back(toVisit);
        }

        //calculate the length of every route
        vector<double> routeLength;
        routeLength.resize(_antNum);
        for (int i = 0; i < _antNum; i++) {
            for (int j = 0; j < _storeNum - 1; j++) {
                vector<int> currentStore = routeRec[j];
                vector<int> nextStore = routeRec[j + 1];
                routeLength[i] += City::instance()->store2StoreDis(currentStore[i], nextStore[i]);
            }
        }

        //add the best route into _bestRouteRec
        int bestRouteNum = distance(routeLength.begin(), min_element(routeLength.begin(), routeLength.end()));
        for (int i = 0; i < _storeNum; i++) {
            vector<int> tmpBestRoute = routeRec[i];
            _bestRouteRec.push_back(tmpBestRoute[bestRouteNum]);
        }

        //renew the Tau list
        vector<double> deltaTau;
        deltaTau.resize(_routeNum);
        for (int j = 0; j < _storeNum - 1; j++) {
            vector<int> currentStore = routeRec[j];
            vector<int> nextStore = routeRec[j + 1];
            deltaTau[normalize(currentStore[bestRouteNum], nextStore[bestRouteNum])] += _enFactor / routeLength[bestRouteNum];
        }
        for (int i = 0; i < _routeNum; i++) {
            _store2StoreTau[i] = (1 - _deFactor) * _store2StoreTau[i] + deltaTau[i];
        }
    }
    return -1;
}
