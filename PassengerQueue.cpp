/*
 * PassengerQueue.cpp
 * 
 * Comp 15 HW 3
 * Sam Lacet-Brown
 * Oct 2020
 *
 * The PassengerQueue class is a vector of passengers that can be inspected,
 * added, and removed. It also maintains the total number of passengers in it.
 *
 */

#include "PassengerQueue.h"
#include <string>

//constructor
PassengerQueue::PassengerQueue() {
    len = 0;
}  

//copy constructor
PassengerQueue::PassengerQueue(const PassengerQueue &other) {
    len = other.len;
    waiting = other.waiting;
}

//deconstructor
PassengerQueue::~PassengerQueue() {

}

/* front
 *    Purpose: Lists the passenger at the front of the queue
 *    Parameters: none
 *    Returns: The Passenger instance that is at the start of the queue
 */
Passenger PassengerQueue::front() {
    return waiting.front();
}

/* dequeue
 *    Purpose: Removes a passenger from the front of the queue
 *    Parameters: none
 *    Returns: none
 */
void PassengerQueue::dequeue() {
    len = len - 1;
    waiting.erase(waiting.begin());
}

/* enqueue
 *    Purpose: Adds a passenger to the back of the queue
 *    Parameters: A passenger
 *    Returns: none
 */
void PassengerQueue::enqueue(const Passenger& passenger) {
    len++;
    waiting.push_back(passenger);
}

/* size
 *    Purpose: Give the number of passengers in the station
 *    Parameters: none
 *    Returns: An int equal to the number of passengers
 */
int PassengerQueue::size() {
    return len;
}

/* print
 *    Purpose: Prints the passenger queue to the given output stream
 *    Parameters: An output stream
 *    Returns: none
 */
void PassengerQueue::print(ostream &stream) {
    for (size_t i = 0; i < waiting.size(); i++) {
        waiting[i].print(cout);
    }
}

/* printInOrder
 *    Purpose: Prints the passenger queue to the given output stream
 *    in ascending order of "to" values
 *    Parameters: The number of stations in the loop, an output stream
 *    Returns: none
 */
void PassengerQueue::printInOrder(int numStations, ostream &stream) {
    for(int i = 1; i < numStations; i++) {
        for (size_t j = 0; j < waiting.size(); j++) {
            if(get(j).to == i) {
                get(j).print(cout);
            }
        }
    }
}

/* get
 *    Purpose: To get a specfic passenger from the queue
 *    Parameters: An index to retreive
 *    Returns: The passenger at the given index
 */
Passenger PassengerQueue::get(int index) {
    return waiting[index];
}

/* remove
 *    Purpose: Remove a selected passenger from the queue
 *    Parameters: An index to remove at
 *    Returns: none
 */
void PassengerQueue::remove(int index) {
    //get(index).print(cout);
    //dequeue();
    len = len - 1;
    waiting.erase(waiting.begin() + index);
}