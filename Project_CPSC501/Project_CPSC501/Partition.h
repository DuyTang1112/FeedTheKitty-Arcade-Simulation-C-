// File name: Partition.h
// Author: Duy Tang, Almando Scott
// Date: 8/12/2016
// Compiler used: Visual C++
// Description: The header file contains the class Partition and all function prototypes
#pragma once
#include "GameTable.h"
class Partition {
private:
	GameTable* gtp;
	Partition* nextpt;
public:
	Partition(GameTable* newg) :nextpt(NULL),gtp(newg) {};
	Partition() { };
	void setData(GameTable* g) { gtp = g; };
	void setNext(Partition* newp) { nextpt = newp; };
	GameTable* getTable()const { return gtp; };
	Partition* getNext() { return nextpt; };
	int getTableID() { return gtp->getid(); };
	int getCurNumPlayer() { return gtp->getNumPlayer_Duration(); };
	
};