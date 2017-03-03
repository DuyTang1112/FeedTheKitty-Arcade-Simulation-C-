// File name: GameTable.h
// Author: Duy Tang, Almando Scott
// Date: 12/8/2016
// Compiler used: Visual C++
// Description: The header file contains the class GameTable and all function prototypes
#pragma once
#include "Game.h"
#include "Statistic.h"
class GameTable{
private:
	Game g;
	int players, dice_num, mice_num;
	int id;
	
public:
	void tablePlay();
	GameTable() {};
	GameTable(int duration) : players(duration) { };
	void showResult();
	void setID(int i) { id = i; };
	void setDuration(int dur) { players = dur; };
	int getid() { return id; };
	void setStartPLID(int i) { 
		g.setStartPLID(i); 
		tablePlay();
	};
	int getNumPlayer_Duration() { return players; }
	int returnWinnerID() { return g.returnWinnerId(); };
	int returnWinMice() { return g.returnWinMice(); };
	string getLogData();
};