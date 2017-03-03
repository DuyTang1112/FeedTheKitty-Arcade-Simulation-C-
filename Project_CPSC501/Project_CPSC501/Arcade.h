#pragma once
#include "TimingWheel.h"
// File name: Arcade.h
// Author: Duy Tang, Almando Scott
// Date: 12/8/2016
// Compiler used: Visual C++
// Description: The header file contains the class Arcade and all function prototypes
#include <chrono>
#include <thread>
using namespace std;
class Arcade {
private:
	TimingWheel *TW;
	int end_of_simulation,simulation_time;
	ofstream out;
	ofstream log;
	int numTables;
	int current_num_player, total_num_player;
public:
	Arcade() {};
	Arcade(int efs, string of) :end_of_simulation(efs), simulation_time(0), numTables(7) { 
		out.open(of); log.open("log.txt"); 
	};
	void initialize();
	void commence();// main routine
	void print_Status();
};