#pragma once
#include "TrainLink.h"
#include "TrainLL.h"
#include "Passenger.h"

using namespace std;

class TrainList {
private:
	Train* head;
	Train* tail;
	Train* curr;
	int cnt;
	void init();
	void removeall();
public:
	TrainList();
	~TrainList();
	void clear();
	void readDatabase();
	void append(string, string, string, string, string, string);
	bool searchTrain(string, string);
	Train* searchTrainPos(string);
	void showTrain();
	string remove(string);
	void moveToStart();
	void moveToEnd();
	void prev();
	void next();
	int length() const;
	int currPos();
	void insertPassenger(string, const Passenger&);
	void showReservations();
	bool showBoardingPass(string);
	bool removePassenger(string);
	int seatsAvailable(string);
	void displayTrainHeader();
	void genderStatistics(string);
};
