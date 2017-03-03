#include "TimingWheel.h"

void TimingWheel::initialize()
{
	for (int i = 0; i < max_delay+1; i++)
	{ 
		slot[i] = NULL;
		numPartition[i] = 0;
	} 
}

void TimingWheel::insert(int play_time, GameTable * pl)
{
	Partition*p = new Partition(pl);
	int pos = (current_slot + play_time) % (max_delay + 1);
	cout << "->Inserting partition at slot[" << pos << "] with delay=" <<  play_time<<" at table "<<pl->getid()<<"\n";
	
	if (numPartition[pos] == 0) slot[pos] = new Partition(pl); //if slot is empty
	else {	// else set the new partition in the front of the linked list
		Partition* temp = new Partition(pl);
		temp->setNext(slot[pos]);
		slot[pos] = temp;
	}
	numPartition[pos]++;
	curr_num_Table++; //increase the current number of tables
	//cout << current_slot << " " << numTable << " " << curr_num_Table << " " << numPartition[current_slot] << "\n";
}

void TimingWheel::schedule()
{
	cout << "Current slot: " << current_slot<<"\n";
	if (numPartition[current_slot]==0 && curr_num_Table==numTable) {
		return;
	}
	else {
		// getting the reult from finised tables
		Partition* temp = slot[current_slot];
		while (temp != NULL) {
			temp->getTable()->showResult();
			//cout << "\n";
			temp = temp->getNext();
		}
		clear_curr_slot(); //clear the partitions in the slot
		std::random_device rd;
		// insert new partitions
		while (curr_num_Table < numTable) {
			int playTime = rd() % (max_delay-1) + 2; //play time equals the number of players which is from 2 to max_delay
			GameTable* gtb = new GameTable(playTime);
			totalNumPlayer += playTime;
			gtb->setStartPLID(PLID);
			if (findFirstAvalTable() != -1) {
				gtb->setID(findFirstAvalTable()+1);
				gtb_aval[findFirstAvalTable()] = false;
			};
			insert(playTime, gtb);
			PLID += playTime;
			
		}
	}
}

void TimingWheel::clear_curr_slot()
{
	Partition* temp = slot[current_slot], *iter;
	if (temp == NULL) return;
	do {	//clearing the linked list at slot[current_slot]
		
		iter = temp;
		temp = temp->getNext();
		cout << "!! Table " << iter->getTableID() << " is available.\n";
		gtb_aval[iter->getTableID()-1] = true; //reset the availability list entry
		if (iter->getTable()->returnWinMice() > bigWinnerMice) { //set the statistic of biggest winner
			bigWinnerMice = iter->getTable()->returnWinMice();
			bigWinnerID = iter->getTable()->returnWinnerID();
		}
		totalGames++;
		delete iter;
	} while (temp != NULL);
	delete temp;
	//delete slot[current_slot];
	slot[current_slot] = NULL; //set the current slot to NULL
	curr_num_Table -= numPartition[current_slot];  //decrease the number of active tables 
	numPartition[current_slot] = 0;
	
}

int TimingWheel::findFirstAvalTable()
{
	for (int i = 0;i < numTable;i++) {
		if (gtb_aval[i] == true) return i;
	}
	return -1;
}

int TimingWheel::getCurrentNumPlayer()
{
	int count = 0;
	for (int i = 0;i < max_delay + 1;i++) {
		Partition* temp = slot[i];
		while (temp != NULL) {
			count += temp->getCurNumPlayer();
			temp = temp->getNext();
		}
	}
	return count;
}

string TimingWheel::getLogAtCurSlot()
{
	string s="";
	Partition* temp = slot[current_slot];
	while (temp != NULL) {
		s += temp->getTable()->getLogData()+"\n";
		temp = temp->getNext();
	}
	return s;
}


