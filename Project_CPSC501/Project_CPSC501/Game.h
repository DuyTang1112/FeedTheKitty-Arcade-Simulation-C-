// File name: Game.h
// Author: Duy Tang, Almando Scott
// Date: 12/8/2016
// Compiler used: Visual C++
// Description: The header file contains the class Game and all function prototypes
#pragma once
#include "Dice.h"
#include "Player.h"
#include <fstream>
#include"Statistic.h"
using namespace std;
class Game {
public:
	Game() {};
	void setPlayers(int p) ;
	void setMice_num(int m) { numMiceOnBowl = m; };
	void setDice_num(int d) { numDice = d; };
	void createDice(string infile="input.txt");
	void play();
	void results();
	bool hasWinner();
	void displayState();
	void setStartPLID(int i) { startPlayerID = i; };
	int returnWinnerId();
	int returnWinMice();
	string getLogData();
private: 
	Dice* dice; 
	Player* player;
	int numMiceOnBowl, numPlayer,numDice;
	int rounds=20;
	int startPlayerID=0;
	string logData="";
};
