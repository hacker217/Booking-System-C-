#include "TrainLL.h"
#include <fstream>
#include <iomanip>
#include <iostream>

void TrainList::init() {
	curr = tail = head = new Train;
	cnt = 0;
}

void TrainList::removeall() {
	while (head != NULL) {
		curr = head;
		head = head->next;
	}
}

TrainList::TrainList() {
	init(); 
}

TrainList::~TrainList() {
	removeall();
}

void TrainList::clear() {
	removeall();
	init();
}	

void TrainList::readDatabase() {
	ifstream inFile;
	string trainNo, dtime, atime, dplace, aplace, fare;
	moveToStart();
	inFile.open("database.txt");
	if (inFile.is_open() && !inFile.eof()) {
		for (int i = 1; !inFile.eof(); i++) {
			inFile >> trainNo >> dtime >> dplace >> atime >> aplace >> fare;
			append(trainNo, dtime, atime, dplace, aplace, fare);
		}
	}
	inFile.close();
}

bool TrainList::searchTrain(string dplace, string aplace) {
	int count = 0;
	bool isFound = false;
	moveToStart();
	for (int i = 0; i < cnt; i++) {
		if ((dplace == curr->next->getdplace()) && (aplace == curr->next->getaplace())) {
			if (count == 0)
				displayTrainHeader();
			curr->next->showTrain();
			count++;
			isFound = true;
		}
		next();
	}
	return true;
}

Train* TrainList::searchTrainPos(string findtrainNo) {
	moveToStart();
	for (int i = 0; i < cnt; i++) {
		if (findtrainNo == curr->next->gettrainNo())
			return curr;
		else
			next();
	}
	return NULL;
}

void TrainList::showTrain() {
	displayTrainHeader();
	moveToStart();
	for (int i = 0; i < cnt; i++) {
		curr->next->showTrain();
		next();
	}
}

string TrainList::remove(string trainNo) { 
	if (cnt == 0) return "EMPTY";
	else {
		for (moveToStart(); currPos() < cnt; next()) {
			if (trainNo == curr->next->gettrainNo()) {
				string removetrain = curr->next->gettrainNo();
				Train* ltemp = curr->next;
				if (tail == curr->next) tail = curr;
				curr->next = curr->next->next;
				delete ltemp;
				cnt--;
				return removetrain;
			}
		}
		return "NA";
	}
}

void TrainList::append(string trainNo, string dtime, string atime, string dplace, string aplace, string fare) {
	tail = tail->next = new Train(trainNo, dtime, atime, dplace, aplace, fare, NULL);
	cnt++;
}

void TrainList::moveToStart(){
	curr = head;
}

void TrainList::moveToEnd() {
	curr = tail; 
}

void TrainList::prev() {
	if (curr == head) return;
	Train* temp = head;
	while (temp->next != curr)temp = temp->next;
	curr = temp;
}

void TrainList::next() {
	if (curr != tail)curr = curr->next;
}

int TrainList::length() const { return cnt; }

int TrainList::currPos() {
	Train* temp = head;
	int i;
	for (i = 0; curr != temp; i++)
		temp = temp->next;
	return i;
}

void TrainList::insertPassenger(string trainNo, const Passenger& guy) { 
	moveToStart();
	for (int i = 0; i < cnt; i++) {
		if (trainNo == curr->next->gettrainNo()) {
			curr->next->insertPassenger(guy);
		}
		next();
	}
}


void TrainList::showReservations() {
	bool exist = false;
	moveToStart();
	for (int i = 0; i < cnt; i++) {
		if (!curr->next->isEmpty()) {
			displayTrainHeader();
			curr->next->showTrain();
			curr->next->sortPassengers();
			curr->next->showPassengers();
			curr->next->showQueue();
			next();
			exist = true;
		}
	}
	if (exist == false) {
		cout << "No reservations." << endl;
	}
}

bool TrainList::showBoardingPass(string findpassno) {
	int index;
	moveToStart();
	for (int i = 0; i < cnt; i++) {
		curr->next->sortPassengers();
		index = curr->next->findPassenger(findpassno);
		if (index != -1) {
			curr->next->showBoardingPass(index);
			return true;
		}
		else {
			next();
		}
	}
	return false;
}


bool TrainList::removePassenger(string findpassno) {
	int index;
	moveToStart();
	for (int i = 0; i < cnt; i++) {
		curr->next->sortPassengers();
		index = curr->next->findPassenger(findpassno);
		if (index != -1) {
			curr->next->removePassenger(index);
			return true;
		}
		else {
			next();
		}
	}
	return false;
}

int TrainList::seatsAvailable(string trainNo) {
	Train* temp = searchTrainPos(trainNo);
	if (temp != NULL)
		return temp->next->seatsAvailable();
	else
		return -1;
}

void TrainList::displayTrainHeader() {
	cout << "**************************************************************************************************\n";
	cout << "Train Code  Departure Time      From       Arrival Time  To                 Fare" << endl;
	cout << "**************************************************************************************************\n";
}

void TrainList::genderStatistics(string trainNo) {
	Train* temp = searchTrainPos(trainNo);
	if (temp != NULL)
		temp->next->genderStatistics();
	else
		cout << "The train is not found!" << endl;
}
