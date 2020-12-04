/*
 * Station.h
 * 
 * Comp 15 HW 3
 * Sam Lacet-Brown
 * Oct 2020
 *
 * The Station class keeps track of which station the train is at
 * and maintains a list of the different queues of people at each station
 *
 */

#ifndef __STATION_H__
#define __STATION_H__

#include <iostream>
#include <vector>
#include <string>
#include "PassengerQueue.h"
using namespace std;

class Station
{
    public:
        Station();
        Station(istream &stream);
        ~Station();
        void print(int trainAt);
        int size();
        vector<string> vec;
        vector<PassengerQueue> people;
    private:
        vector<PassengerQueue> makeQueues();
        int len;
};

#endif
