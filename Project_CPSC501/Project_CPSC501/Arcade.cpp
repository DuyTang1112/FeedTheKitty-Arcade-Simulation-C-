#include "Arcade.h"

void Arcade::initialize()
{
	TW = new TimingWheel(numTables);
	current_num_player = 0;
	total_num_player = 0;
}

void Arcade::commence()
{
	
	while (simulation_time<end_of_simulation)
	{
		//s.getOFstream() << "Time: "<<simulation_time<<"\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(0000));
		print_Status();
		TW->schedule();
		//TW.clear_curr_slot();
		TW->inc_currSlot();
		simulation_time++;
	}
	cout << "\n\t\t**** END OF SIMULATION TIME ****\n";
	out << "\n\t\t**** END OF SIMULATION TIME ****\n";
	log << "\n\t\t**** END OF SIMULATION TIME ****\n";
}

void Arcade::print_Status()
{
	//console output
	cout << "\n\n***********************************************************************************\n";
	cout << "Time instant: " << simulation_time << "\n";
	cout << "Number of tables: " << numTables << "\n";
	cout << "Current number of players: " << TW->getCurrentNumPlayer()<<"\n";
	cout << "Total number of finished games: " << TW->totalGamesPlayed() << "\n";
	cout << "Total number of players so far: " << TW->getTotalNumPlayer() << "\n";
	if (TW->getBigWinnerID()!=-1)
		cout << "Biggest winner: Player " << TW->getBigWinnerID() << "\n";
	if (TW->getBigWinMice() != -1)
		cout << "Biggest number of mice won: " << TW->getBigWinMice() << "\n";
	
	// writing to output file
	out << "\n*************************************\n";
	out << "Time instant: " << simulation_time << "\n";
	out << "Number of tables: " << numTables << "\n";
	out << "Current number of players: " << TW->getCurrentNumPlayer() << "\n";
	out << "Total number of finished games: " << TW->totalGamesPlayed() << "\n";
	out << "Total number of players so far: " << TW->getTotalNumPlayer() << "\n";
	if (TW->getBigWinnerID() != -1)
		out << "Biggest winner: Player " << TW->getBigWinnerID() << "\n";
	if (TW->getBigWinMice() != -1)
		out << "Biggest number of mice won: " << TW->getBigWinMice() << "\n";
	
	// writing to log file
	log << "*****************************************************\n";
	log << "Time instant: " << simulation_time << "\n";
	log << TW->getLogAtCurSlot();
	
}
