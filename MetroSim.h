/*
 * MetroSim.h
 * 
 * Comp 15 HW 3
 * Sam Lacet-Brown
 * Oct 2020
 *
 * The MetroSim class holds the train which can receive commands and move to
 * various stations, letting passangers on and off at each and tracking whose
 * on board at any given time
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Station.h"
#include "PassengerQueue.h"
#include <iostream>
#include <vector>
using namespace std;

class MetroSim {
    public:
        MetroSim(Station stations, ostream &outstream);
        MetroSim(Station stations, istream &commandtext, ostream &outstream);
        ~MetroSim();
    private:
        void getCommands(istream &istream,
            ostream &outstream,
            Station stations);
        void getCommands(Station stations, ostream &outstream);
        void move(Station &stations, ostream &outstream);
        void addPass(int arrive, int dest, Station &stations);
        void onBoard(Station &stations);
        void offBoard(Station &stations, ostream &outstream);
        int last(int val, int limit, int set);
        void print(Station stations);
        PassengerQueue onTrain;
        int passCount = 0;
        int trainAt;
};

#endif