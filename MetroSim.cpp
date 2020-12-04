/*
 * MetroSim.cpp
 * 
 * Comp 15 HW 3
 * Sam Lacet-Brown
 * Oct 2020
 *
 * The MetroSim class holds the train which can receive commands and move to
 * various stations, letting passangers on and off at each and tracking who is
 * on board at any given time
 *
 */

#include "MetroSim.h"
#include "Station.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//constructor if given command file
MetroSim::MetroSim(Station stationlist,
    istream &commandtext,
    ostream &outstream) {
    trainAt = 1;
    Station stations = stationlist;
    print(stations);
    getCommands(commandtext, outstream, stations);
    //passCount = 0;
}

//default constructor
MetroSim::MetroSim(Station stationlist, ostream &outstream) {
    trainAt = 1;
    Station stations = stationlist;
    print(stations);
    getCommands(stations, outstream);
    //passCount = 0;
}

//deconstructor
MetroSim::~MetroSim() {

}

/* getCommands
 *    Purpose: Processes the commands in the command file
 *    Parameters: An input source and a Station instance with all of the stops
 *    and a output stream to print exiting passengers to
 *    Returns: none
 */
 void MetroSim::getCommands(istream &stream,
    ostream &outstream,
    Station stations) {
    string command, action, arrive, dest;
    while(command!="quit") {
        cout << "Command? ";
        stream >> command;
        if(command=="m") {
            stream >> action;
            if(action == "m") {
                move(stations, outstream);
            } else if (action == "f") {
                command = "quit";
            }
        } else if (command == "p") {
            stream >> arrive >> dest;
            passCount++;
            addPass(stoi(arrive), stoi(dest), stations);
        }
    }
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
}

/* getCommands
 *    Purpose: Processes the commands entered via cin
 *    Parameters: A Station instance with all of the stops
 *    and a output stream to print exiting passengers to
 *    Returns: none
 */
void MetroSim::getCommands(Station stations, ostream &outstream) {
    string command, action, arrive, dest;
    while(command!="quit") {
        cout << "Command? ";
        cin >> command;
        if(command=="m") {
            cin >> action;
            if(action == "m") {
                move(stations, outstream);
            } else if (action == "f") {
                command = "quit";
            }
        } else if (command == "p") {
            cin >> arrive >> dest;
            passCount++;
            addPass(stoi(arrive), stoi(dest), stations);
        }
    }
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
}

/* move
 *    Purpose: Moves the train forward a stop, processes letting people on/off
 *    Parameters: A pointer to a Station instance with the current stop
 *    and a output stream to print exiting passengers to
 *    Returns: none
 */
void MetroSim::move(Station &stations, ostream &outstream) {
    onBoard(stations);
    trainAt++;
    if(trainAt == stations.size() + 1) {
        trainAt = 1;
    }
    offBoard(stations, outstream);
    print(stations);
    // cout << "Passengers on the train: ";
    // onTrain.print(cout);
    // // for (size_t i = 0; i < onTrain.size(); i++) {
    // //     onTrain[i].print(cout);
    // // }
    // cout << endl;
    // stations.print(trainAt);
    
}

/* addPass
 *    Purpose: Place passenger in the queue for the station they're coming from
 *    Parameters: A destination and arrival station and 
 *    a pointer to a Station instance with the current stop
 *    Returns: none
 */
void MetroSim::addPass(int arrive, int dest, Station &stations) {
    Passenger *newPass = new Passenger(passCount, arrive, dest);
    stations.people[
        last(arrive, -1, stations.people.size())
    ].enqueue(*newPass);
    print(stations);
}

/* offBoard
 *    Purpose: Remove all the  passangers who have arrived at 
 *    their destination station from the train
 *    Parameters: A pointer to a Station instance with the current stop
 *    and a output stream to print exiting passengers to
 *    Returns: none
 */
void MetroSim::offBoard(Station &stations, ostream &outstream) {
    //trainAt;
    //if this is a passengers to
    //they should be removed
    for (size_t i = 0; i < onTrain.size(); i++) {
        if (onTrain.get(i).to == trainAt) {
            outstream << "Passenger " << onTrain.get(i).id;
            outstream << " left train at station ";
            outstream << stations.vec[last(trainAt, -1, stations.size())];
            outstream << endl;
            onTrain.remove(i);
        }
    }
}

/* onBoard
 *    Purpose: Move all passengers from a station to the train when it comes
 *    Parameters: A pointer to a Station instance with the current stop
 *    Returns: none
 */
void MetroSim::onBoard(Station &stations) {
    //if trainAt is station id
    //all in  station queue
    //should be added to onTrain
    //stations.people[last(trainAt, -1, stations.len)].print(cout);
    int train = last(trainAt, -1, stations.size());
    int size = stations.people[train].size();
    for(int i = 0; i < size; i++) {
        //stations.people[train].print(cout);
        onTrain.enqueue(
            stations.people[train].front()
        );
        stations.people[train].dequeue();
    }
}

/* last
 *    Purpose: Reduce val by one but wrap-around to set if out of range
 *    Parameters: 3 ints, val to reduce, limit to set boundary, set to reassign
 *    Returns: An int value that is between limit and set
 */
int MetroSim::last(int val, int limit, int set) {
    int last = val - 1;
    if(last == limit) {
        last = set;
    }
    return last;
}

/* print
 *    Purpose: Display the current state of the simulation via cout
 *    Parameters: A Station instance with all of the stops
 *    Returns: none
 */
void MetroSim::print(Station stations) {
    cout << "Passengers on the train: {";
    onTrain.printInOrder(stations.size(), cout);
    cout << "}" << endl;
    stations.print(trainAt);
}
