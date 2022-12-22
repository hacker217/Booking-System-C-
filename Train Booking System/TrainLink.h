#pragma once
#include <string>
#include <iomanip> 
#include "SeatsAL.h"
#include "Passenger.h"
#include "WaitingList.h"

using namespace std;

class Train {
private:
	string trainNo, dtime, atime, dplace, aplace, fare;
	SeatsList* seats;
	WaitingList* queue;

public:
	Train* next;
	Train(string, string, string, string, string, string, Train*);
	Train(Train* nextval = NULL);
	string gettrainNo();
	string getdplace();
	string getaplace();
	void showTrain();
	void insertPassenger(const Passenger&);
	int getLength();
	void showPassengers();
	void showBoardingPass(int);
	void showQueue();
	void sortPassengers();
	int findPassenger(string);
	void removePassenger(int);
	bool isEmpty();
	int seatsAvailable();
	void genderStatistics();
};
