/*
 * PassengerQueue.h
 * 
 * Comp 15 HW 3
 * Sam Lacet-Brown
 * Oct 2020
 *
 * The PassengerQueue class is a vector of passengers that can be inspected,
 * added, and removed. It also maintains the total number of passengers in it.
 *
 */

#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H

#include "Passenger.h"
#include <vector>
using namespace std;

class PassengerQueue
{
public:
    PassengerQueue();     
    PassengerQueue(const PassengerQueue &other);
    ~PassengerQueue(); 

    Passenger front();
    void dequeue();
    void enqueue(const Passenger& passenger);
    void printInOrder(int numStations, ostream &stream);
    int size();
    void print(ostream &stream);
    Passenger get(int index);
    void remove(int index);
private:
    vector<Passenger> waiting;
    int len;
};

#endif
