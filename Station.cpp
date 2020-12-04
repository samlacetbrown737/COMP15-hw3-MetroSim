/*
 * Station.cpp
 * 
 * Comp 15 HW 3
 * Sam Lacet-Brown
 * Oct 2020
 *
 * The Station class keeps track of which station the train is at
 * and maintains a list of the different queues of people at each station
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "Station.h"

using namespace std;

//default constructor, only used for MetroSim to initalize it
Station::Station() {
    vec.push_back("placeholder");
}

//constructor, takes in an input stream
Station::Station(istream &stream) {
    string line;
    len = 0;
    while(getline(stream, line)) {
        vec.push_back(line);
    }
    people = makeQueues();
}

//deconstructor
Station::~Station() {

}

/* print
 *    Purpose: Display the current queues in each train
 *    Parameters: An int value that gives the current train stop
 *    Returns: none
 */
void Station::print(int trainAt) {
    for (size_t i = 0; i < vec.size(); i++) {
        if((trainAt-1) == i) {
            cout << "TRAIN: ";
        } else {
            cout << "       ";
        }
        cout << "[" << (i+1) << "] ";
        cout << vec[i] << " {";
        people[i].print(cout);
        cout << "}" << endl;
    }
}

/* makeQueues
 *    Purpose: To create a list for each station that can hold passengers
 *    Parameters: none
 *    Returns: A vector of PassengerQueues that lists queues for each station
 */
vector<PassengerQueue> Station::makeQueues() {
    vector<PassengerQueue> v;
    for (size_t i = 0; i < vec.size(); i++) {
        len++;
        PassengerQueue newQueue = PassengerQueue();
        v.push_back(newQueue);
    }
    return v;
}

/* size
 *    Purpose: Give the number of stations in the loop
 *    Parameters: none
 *    Returns: An int equal to the number of stations
 */
int Station::size() {
    return len;
}