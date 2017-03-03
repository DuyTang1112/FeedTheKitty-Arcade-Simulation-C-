// File name: TimingWheel.h
// Author: Duy Tang, Almando Scott
// Date: 12/8/2016
// Compiler used: Visual C++
// Description: The header file contains the class TimingWheel and all function prototypes
#pragma once
#include "Partition.h"

class TimingWheel {
private:
	static const int max_delay = 6; //maximum number of players per table
	Partition* slot[max_delay + 1];
	int numPartition[max_delay + 1]; //keeping track of the number of partitions in each slot
	int current_slot;
	int numTable; 
	int curr_num_Table ;
	bool* gtb_aval; //array keeping track of the availability of game tables
	int PLID; // starting player's ID tracker
	int totalNumPlayer,bigWinnerID,bigWinnerMice,totalGames;
public:
	TimingWheel(int n) :current_slot(0), curr_num_Table(0), numTable(n), PLID(0),totalNumPlayer(0),
	bigWinnerID(-1),bigWinnerMice(-1),totalGames(0){ 
		initialize(); 
		gtb_aval = new bool[numTable];
		for (int i = 0;i < numTable;i++) {
			gtb_aval[i] = true;
		}
	};
	void initialize();
	void insert(int, GameTable*);
	void schedule();
	void clear_curr_slot();
	void inc_currSlot() { current_slot=(current_slot+1)%(max_delay+1); };
	int findFirstAvalTable();
	int getCurrentNumPlayer();
	int getTotalNumPlayer() { return totalNumPlayer; };// return total number of players so far
	int getBigWinnerID() {return bigWinnerID;};  //return the top winner
	int getBigWinMice() { return bigWinnerMice; }; //return the top winning
	string getLogAtCurSlot();
	int totalGamesPlayed() { return totalGames; };
};