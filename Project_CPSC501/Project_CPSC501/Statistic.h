#pragma once
#include <string>
using namespace std;
class Statistic {
private: 
	//ofstream of;
	int DFstats[8];
	int totalPlayers, gamesPlayed, curr_numPlayer;
	int bigWinnerID, bigMice;
	const int GSC = 0, GB = 1, GA = 2, GM = 3, RSC = 4, RB = 5, RA = 6, RM = 7;
public: 
	
	Statistic(string out="output.txt"): totalPlayers(0), 
		gamesPlayed(0), bigWinnerID(0), bigMice(0), curr_numPlayer(0) {
		//of.open(out);
		for (int i = 0; i < sizeof(DFstats); i++)
		{
			DFstats[i] = 0;
		}
		//of << "ASDAS";
	};
	
	void addTotalPlayers(int i) { totalPlayers += i; };
	void addGamesPlayed(int i) { gamesPlayed += i; };
	void setCurrNumPlayer(int i) { curr_numPlayer = i; };
	void setbigWinner(int id, int mice) ;
	
	//ofstream& getOFstream() { return of; };
};