// File name: GameTable.cpp
// Author: Duy Tang, Almando Scott
// Date: 12/8/2016
// Compiler used: Visual C++
// Description: The .cpp file contains the detailed descriptions of member functions
// of class GameTable
#include "GameTable.h"

void GameTable::tablePlay()
{	
	std::random_device rd;
	//players = rd() % 5 + 2; //number of players from 2 to 6
	g.setPlayers(players);
	dice_num = rd() % 4 + 2; //number of dices from 2 to 5
	g.setDice_num(dice_num);
	mice_num = rd() % 21 + 10;// number of mice from 10 to 30
	g.setMice_num(mice_num);
	g.createDice("input.txt");
	g.play();
	//g.results();
	
}

void GameTable::showResult()
{
	
	cout << "-----------------------------------------------------------\n";
	cout << "\tTABLE " <<id<<": \n";
	cout << "\tNumber of players:" << players << "\n";
	g.results();
	cout << "\tGame duration: " << players<<"\n";
	cout << "-----------------------------------------------------------\n";
}

string GameTable::getLogData()
{
	string s="\n\t\t##### RECORD FROM TABLE "+std::to_string(id)+" #####\n";
	s += g.getLogData();
	
	return s;
}
