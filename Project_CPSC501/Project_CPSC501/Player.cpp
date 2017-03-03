// File name: Player.cpp
// Author: Duy Tang
// Date: 11/23/2016
// Compiler used: Visual C++
// Description: The .cpp file contains the detailed descriptions of member functions
// of class Player
#include "Player.h"

Player::Player(int id, int nm)
{
	ID = id;
	numMice = nm;
}

void Player::rollDice(Dice * d, int diceNum,string& log)
{
	DF.clear(); DF = "";
	log += "\nRolling:  | ";
	//srand(time(0));
	numDice = diceNum;
	DFColor = new char[diceNum];
	DFLabel = new char[diceNum];
	for (int i = 0; i < diceNum; i++)
	{
		DiceFace* df = d[i].roll();
		log+=df->getColor()+"-"+df->getLabel();
		log+= " | ";
		DF += df->getColor().substr(0,1) + df->getLabel().substr(0,1)+" ";
		DFLabel[i] = df->getLabel().at(0);
		DFColor[i] = df->getColor().at(0);
		
	}
}

void Player::move(int & bowl, int & it, Player * p, int numPlayer,string& log)
{
	log+= "\n";
	for (int i = 0; i < numDice; i++)
	{
		switch (DFLabel[i])
		{
		case 'S':
			log += "Do nothing\n";
			break;
		case 'B':
			if (numMice > 0) {
				bowl++;
				numMice--;
				log += "Put the mice in the bowl\n";
			}
			else log+= "No mice left to put in the bowl\n";
			break;
		case'A':
			if (numMice > 0) {
				p[(it+1)%numPlayer].incMice();
				numMice--;
				log += "Put the mice to P" +std::to_string( p[(it + 1) % numPlayer].ID) + "\n";
			}
			else log += "No mice left\n";
			break;
		case 'M':
			if (bowl > 0) {
				bowl--;
				numMice++;
				log += "P" +std::to_string( ID) + " receives a mice from the bowl\n";
			}
			else log += "No mice left in bowl\n";
		default:
			break;
		}
	}
	int numRed = 0;// direction of plays depends on the number of red dice faces
	for (int i = 0; i < numDice; i++)
	{
		if (DFColor[i] == 'R') numRed++;
		
	}
	if (numRed % 2 == 0) { 
		it = (it + 1) % numPlayer; 
		log += "Direction stays.\n";
	}
	else {
		if (it ==0 ) it = numPlayer-1;
		else it--;
		log += "Direction changes.\n";
	}
	
	delete[] DFColor;
	delete[] DFLabel;
}



string Player::to_string()
{
	string s = "";
	s+= "P"+ std::to_string(ID)+ "-" + std::to_string( numMice);
	return s;
}
