/*
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include "Station.h"
#include "Passenger.h"
#include "PassengerQueue.h"

using namespace std;

int main(int argc, char *argv[]) {
    if(argc == 3 || argc == 4) {
        ofstream output;
        output.open(argv[2]);
        // streambuf *coutbuf = cout.rdbuf();
        // cout.rdbuf(out.rdbuf());
        ifstream stationstext;
        ifstream commandtext;
        stationstext.open(argv[1]);
        if(!stationstext.is_open()) {
            cerr << "Error: could not open file " << argv[1] << endl;
            return 0;
        }
        Station stations = Station(stationstext);
        stationstext.close();
        if(argc == 4) {
            commandtext.open(argv[3]);
            if(!commandtext.is_open()) {
                cerr << "Error: could not open file " << argv[3] << endl;
                return 0;
            }
            MetroSim *metro = new MetroSim(stations, commandtext, output);
        } else {
            MetroSim *metro = new MetroSim(stations, output);
        }
        commandtext.close();
    } else {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]";
    }
	return 0;
}