/*
 * Passenger.cpp
 * 
 * Comp 15 HW 3
 * Sam Lacet-Brown
 * Oct 2020
 *
 * The Passenger class holds the starting station, id, and final destination
 * of each passenger, with the ability to print those details
 *
 */

#include <iostream>
#include <string>
#include "Passenger.h"
using namespace std;

/* print
 *    Purpose: Prints an overview of the passenger to the given output stream
 *    Parameters: An output stream
 *    Returns: none
 */
void Passenger::print(ostream &output)
{
    output << "[" << id << ", " << from << "->" << to << "]";
}
