// File name: Player.h
// Author: Duy Tang
// Date: 11/23/2016
// Compiler used: Visual C++
// Description: The header file contains the class Player and all function prototypes
#pragma once
#include "Dice.h"
using namespace std;
class Player {
public:
	Player() {};
	Player(int, int);
	void rollDice(Dice*, int,string& ); // get random dice faces from the dices
	void move(int&,int&, Player*, int,string&);// make moves based on the current dice faces
	void setnumMice(int d) { numMice = d; };
	void setID(int id) { ID = id; };
	void incMice() { numMice++; };// increase the number of mice
	void display() { cout << "P" << ID << "-" << numMice; };
	int getId() { return ID; };
	int returnNumMice() { return numMice; };
	string getDF() { return DF; };
	string to_string();
private:
	int ID;
	int numMice;	// current number of mice the player has
	char* DFLabel; // current dice labels
	char* DFColor; // current dice faces
	int numDice;
	string DF;
};