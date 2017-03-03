// File name: Dice.cpp
// Author: Duy Tang
// Date: 11/23/2016
// Compiler used: Visual C++
// Description: The .cpp file contains the detailed descriptions of member functions
// of class Dice


#include "Dice.h"

void Dice::construct(int id, int faces, int probColor[], int probLabel[])
{
	DiceID = id;
	Faces = faces;
	
	const int G = 0, R = 1;
	const int  SC = 0, B = 1, A = 2, M = 3;
	d = new DiceFace*[Faces];

	for (int i = 0; i <Faces; i++)
	{
		int randColor = rand() % 100, randLabel = rand() % 100;
	//	cout << randColor << "\t" << randLabel << "\n";
		if (randColor < probColor[G]) {
			if (randLabel < probLabel[SC]) d[i] = new SCGreenDice();
			else if (randLabel < probLabel[B]) d[i] = new BowlGreenDice();
			else if (randLabel <probLabel[A]) d[i] = new ArrowGreenDice();
			else d[i] = new MiceGreenDice();
		}
		else {
			if (randLabel < probLabel[SC]) d[i] = new SCRedDice();
			else if (randLabel < probLabel[B]) d[i] = new BowlRedDice();
			else if (randLabel <probLabel[A]) d[i] = new ArrowRedDice();
			else d[i] = new MiceRedDice();
		}
	}
	//display();
}

void Dice::display()
{
	cout << "Dice " << DiceID << ":\n";
	for (int i = 0; i < Faces; i++)
	{
		d[i]->display();
		cout << "\n";
		
	}
}

DiceFace * Dice::roll()
{
	std::random_device rd; 
	int r = rd() % Faces;
	return d[r];
}

string Dice::toString()
{
	string s = "";
	
	s+="\tDice " +std::to_string(DiceID)+":\n";

	for (int i = 0; i < Faces; i++)
	{
		s+=d[i]->getColor()+"- "+d[i]->getLabel();
		s+="\n";

	}
	return s;
}

Dice::~Dice()
{
	for (int i = 0; i < Faces; i++)
	{
		delete[] d[i];
	}
	delete[] d;
}

