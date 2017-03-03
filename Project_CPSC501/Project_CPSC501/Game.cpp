// File name: Game.cpp
// Author: Duy Tang, Almando Scott
// Date: 11/23/2016
// Compiler used: Visual C++
// Description: The .cpp file contains the detailed descriptions of member functions
// of class Game
#include "Game.h"

void Game::setPlayers(int p)
{
	numPlayer = p;
	player = new Player[numPlayer];
}

void Game::createDice(string infile)
{	// reading the input file and input's probability

	srand(time(0));
	const int G = 0, R = 1;
	const int  SC = 0, B = 1, A = 2, M = 3;
	ifstream in(infile);
	int numFace, numColor, numLabel;
	in >> numFace >> numColor >> numLabel;
	//cout << numFace << numColor << numLabel;
	int probColor[2];
	int probLabel[4];
	int sumLabel = 0;
	for (int i = 0; i < numColor; i++)
	{
		string color; in >> color;
		if (color.at(0) == 'G') in >> probColor[G];
		else if (color.at(0) == 'R') in >> probColor[R];
	}
	//cout << probColor[0] << probColor[1] << "\n";
	for (int i = 0; i < numLabel; i++)
	{
		string label; in >> label;
		switch (label.at(0))
		{
		case 'S':
			in >> probLabel[SC];
			break;
		case 'B':
			in >> probLabel[B];
			break;
		case 'M':
			in >> probLabel[M];
			break;
		case 'A':
			in >> probLabel[A];
			break;
		default:
			break;
		}
	}
	for (int i = 0; i <4; i++)
	{
		if (probLabel[i] > 0) {
			probLabel[i] += sumLabel;
			sumLabel = probLabel[i];
		}
	}
	// creating a list of dices
	dice = new Dice[numDice];
	for (int i = 0; i < numDice; i++)
	{
		dice[i].construct(i+1, numFace,probColor,probLabel);
		logData += dice[i].toString();
		//cout << dice[i].toString();
		//cout << "\n";
	}
	
}

void Game::play()
{	///*
	logData+= "---------------------------\n\tPLAYING!!!:";
	//set player's id
	for (int i = 0; i < numPlayer; i++)
	{
		player[i].setID(++startPlayerID);
		player[i].setnumMice(numMiceOnBowl / numPlayer);
	}
	numMiceOnBowl = numMiceOnBowl % numPlayer;
	int i = 0;
	int roundsPlayed = 0;
	logData += "\n";
	displayState();
	while (!hasWinner()) {
		logData+= "\n\n\nPlayer"+ std::to_string(player[i].getId())+ "'s turn: \n";
		player[i].rollDice(dice,numDice,logData);
		player[i].move(numMiceOnBowl,i,player,numPlayer,logData);
		//logData += player[i].getDF() + "\n";
		displayState();
		roundsPlayed++;
	}
	logData += "\n\n\t!!!!WINNER IS PLAYER " + std::to_string(returnWinnerId()) 
		+ "- " + std::to_string(returnWinMice())+" mice\n";
	
}

void Game::results()
{
	for (int j = 0; j < numPlayer; j++)
	{
		if (player[j].returnNumMice() > 0) {
			cout <<"\tWINNER: Player #"<< player[j].getId() <<" with "<<player[j].returnNumMice()
				<<" mice.\n" ;
			
			break;
		}
	}
	cout << "\tMice in bowl left: " << numMiceOnBowl<<"\n";
}

bool Game::hasWinner()
{
	/*if (i > rounds) {
		return true;
	}*/
	int numPHasMice=0; //count the number of players that have mice
	for (int j = 0; j < numPlayer; j++)
	{
		if (player[j].returnNumMice() >0) numPHasMice++;
	}
	if (numPHasMice == 1) return true;
	return false;
}

void Game::displayState()
{
	logData+="Bowl-" + std::to_string(numMiceOnBowl)+"\t\t";
	for (int i = 0; i < numPlayer; i++)
	{
		logData +=player[i].to_string()+"\t";
		//cout << "\t";
	}
}

int Game::returnWinnerId()
{
	if (hasWinner()) {
		for (int j = 0; j < numPlayer; j++)
		{
			if (player[j].returnNumMice() > 0) {
				return player[j].getId();
				//break;
			}
		}
	}
	return -1;
}

int Game::returnWinMice()
{
	if (hasWinner()) {
		for (int j = 0; j < numPlayer; j++)
		{
			if (player[j].returnNumMice() > 0) {
				return player[j].returnNumMice();
				//break;
			}
		}
	}
	
	return -1;
}

string Game::getLogData()
{
	return logData;
}
