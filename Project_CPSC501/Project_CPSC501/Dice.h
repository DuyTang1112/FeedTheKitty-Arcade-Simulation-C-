// File name: Dice.h
// Author: Duy Tang
// Date: 11/23/2016
// Compiler used: Visual C++
// Description: The header file contains the class Dice and all function prototypes
#pragma once
#include "DiceFace.h"
#include <time.h>
#include <random>
using namespace std;
class Dice {
public:
	void construct(int, int, int[], int[]);// construct a new dice
	void display();
	int getNumFaces() { return Faces; };
	DiceFace* roll();// get a random dice face
	string toString();
	~Dice();
private:
	int DiceID;
	int Faces;
	DiceFace** d;
	
};
