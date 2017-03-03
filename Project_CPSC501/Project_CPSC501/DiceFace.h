// File name: DiceFace.h
// Author: Duy Tang
// Date: 11/23/2016
// Compiler used: Visual C++
// Description: The header file contains the class DiceFace, its hierachy of 
// subclasses and all function prototypes

#pragma once
#include <string>
#include <iostream>
using namespace std;

class DiceFace {
public:
	DiceFace() {};
	virtual void display() = 0;
	virtual string getColor() = 0;
	virtual string getLabel() = 0;
};

//Color Dice
class GreenDice : public DiceFace {
public:
	GreenDice() {};
	void display();
	virtual string getColor() { return color; };

protected:
	const string color = "Green";
};

class RedDice : public DiceFace {
public:
	RedDice() {};
	void display();
	virtual string getColor() { return color; };
protected:
	const string color = "Red";
};

//GreenDice derived class
class BowlGreenDice : public GreenDice {
public:
	BowlGreenDice() {};
	void display();
	string getLabel() { return label; };
protected:
	const string label = "Bowl";
};

class SCGreenDice : public GreenDice {
public:
	SCGreenDice() {};
	void display();
	string getLabel() { return label; };
protected:
	const string label = "Sleeping cat";
};

class MiceGreenDice : public GreenDice {
public:
	MiceGreenDice() {};
	void display();
	string getLabel() { return label; };
protected:
	const string label = "Mice";
};

class ArrowGreenDice : public GreenDice {
public:
	ArrowGreenDice() {};
	void display();
	string getLabel() { return label; };
protected:
	const string label = "Arrow";
};

//RedDice derived class
class BowlRedDice : public RedDice {
public:
	BowlRedDice() {};
	void display();
	string getLabel() { return label; };
protected:
	const string label = "Bowl";
};

class SCRedDice : public RedDice {
public:
	SCRedDice() {};
	void display();
	string getLabel() { return label; };
protected:
	const string label = "Sleeping cat"; 
};

class MiceRedDice : public RedDice {
public:
	MiceRedDice() {};
	void display();
	string getLabel() { return label; };
protected:
	const string label = "Mice";
};

class ArrowRedDice : public RedDice {
public:
	ArrowRedDice() {};
	void display();
	string getLabel() { return label; };
protected:
	const string label = "Arrow";
};