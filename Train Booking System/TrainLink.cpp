#include "TrainLink.h"
#include <iostream>

using namespace std;

Train::Train(string trainNo, string dtime, string atime, string dplace, string aplace, string fare, Train* nextval) {
	this->trainNo = trainNo;
	this->dtime = dtime;
	this->atime = atime;
	this->dplace = dplace;
	this->aplace = aplace;
	this->fare = fare;
	next = nextval;
	seats = new SeatsList;
	queue = new WaitingList;
}

Train::Train(Train* nextval) { next = nextval; }

string Train::gettrainNo() { return trainNo; }

string Train::getdplace() { return dplace; }

string Train::getaplace() { return aplace; }

void Train::showTrain() {
	cout << left << setw(15) << trainNo << left << setw(16) << dtime << setw(18) << dplace 
		 << setw(8) << atime << setw(20) << aplace << setw(8) << ("$" + fare) << endl;
}

void Train::insertPassenger(const Passenger& guy) {
	if ((*seats).isFull() == false) {
		(*seats).insert(guy);
		cout << "The train is booked!" << endl;
	}
	else {
		char choice;
		cout << "************************************************************" << endl; 
		cout << "Sorry, the train is fully booked." << endl << endl;
		cout << "Would you like to be enlisted into the waiting list? (Y/N): ";
		cin >> choice;
		cout << "************************************************************" << endl;
		if (choice == 'Y') {
			(*queue).enqueue(guy);
			cout << "#################################################" << endl;
			cout << "#  You've been enlisted into the waiting list!  #" << endl;
			cout << "#################################################" << endl;
		}
		else return;
	}
}

int Train::getLength() { return (*seats).length(); }

void Train::showPassengers() {
	(*seats).showPassengers();
}

void Train::showBoardingPass(int index) {
	cout << "*****************************************************************************************" << endl;
	cout << "*                                BOARDING PASS                                          *" << endl;
	cout << "*****************************************************************************************" << endl;
	cout << "*Train Code  Departure Time      From       Arrival Time  To                 Fare      *" << endl;
	cout << "*****************************************************************************************" << endl;
	showTrain();
	cout << endl;
	(*seats).showBoardingPass(index);
	cout << "*****************************************************************************************" << endl;
}

void Train::showQueue() { (*queue).showQueue(); }

void Train::sortPassengers() {
	(*seats).sort();
}

int Train::findPassenger(string findpassno) {
	return (*seats).searchPassenger(findpassno);
}

void Train::removePassenger(int index) {
	if (!(*queue).isEmpty()) {
		Passenger temp = (*queue).dequeue();
		(*seats).overWritePassenger(index, temp);
		cout << "********************************************************************************************" << endl;
		cout << "The passenger with a passport number " << temp.getPassno() << " has been removed from the train." << endl;
		cout << "********************************************************************************************" << endl;
	}
	else
		(*seats).remove(index);
}

bool Train::isEmpty() {
	return (*seats).isEmpty();
}

int Train::seatsAvailable() {
	return (*seats).seatsAvailable();
}

void Train::genderStatistics() { 
	(*seats).genderStatistics();
}
