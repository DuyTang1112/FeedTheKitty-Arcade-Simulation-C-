// File name: FeedTheKittyTest.cpp
// Author: Duy Tang, Almando Scott
// Date: 11/23/2016
// Compiler used: Visual C++
// Description: The .cpp file that interact with the client

#include <time.h>
#include "Arcade.h"
#include <iostream>


int main() {

	int simulation_time;
	string outfile;
	do {
		cout << "Please input the simulation time (must be greater than 0): ";
		cin >> simulation_time;
	} while (simulation_time <= 0);
	do {
		cout << "Please input the output file name (cannot be 'input.txt'): ";
		cin >> outfile;
	} while (outfile == "input.txt");
	Arcade ac(simulation_time, outfile);
	ac.initialize();
	ac.commence();

	return 0;
}
