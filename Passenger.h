/*
 * Passenger.h
 * 
 * Comp 15 HW 3
 * Sam Lacet-Brown
 * Oct 2020
 *
 * The Passenger class holds the starting station, id, and final destination
 * of each passenger, with the ability to print those details
 *
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__
#include <iostream>

using namespace std;
struct Passenger
{

    int id, from, to;

    Passenger()
    {
        id   = -1;
        from = -1;
        to   = -1;
    }

    Passenger(int newId, int arrivalStation, int departureStation)
    {
        id   = newId;
        from = arrivalStation;
        to   = departureStation;
    }

    void print(ostream &stream);

};

#endif
