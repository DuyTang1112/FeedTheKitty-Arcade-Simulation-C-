// File name: DiceFace.cpp
// Author: Duy Tang
// Date: 11/23/2016
// Compiler used: Visual C++
// Description: The .cpp file contains the detailed descriptions of member functions
// of class DiceFace's subclasses
#include "DiceFace.h"

void GreenDice::display()
{
	cout << color;
}

void RedDice::display()
{
	cout << color;
}

void BowlGreenDice::display()
{
	GreenDice::display();
	cout << "- " << label;
}

void SCGreenDice::display()
{
	GreenDice::display();
	cout << "- " << label;
}

void MiceGreenDice::display()
{
	GreenDice::display();
	cout << "- " << label;
}

void ArrowGreenDice::display()
{
	GreenDice::display();
	cout << "- " << label;
}

void BowlRedDice::display()
{
	RedDice::display();
	cout << "- " << label;
}

void SCRedDice::display()
{
	RedDice::display();
	cout << "- " << label;
}

void MiceRedDice::display()
{
	RedDice::display();
	cout << "- " << label;
}

void ArrowRedDice::display()
{
	RedDice::display();
	cout << "- " << label;
}
