#pragma once
#include "Passenger.h"

class SeatsList {
private:
	int listSize;
	int curr;
	Passenger* listArray;
	int MSIZE = 5;
public:
	SeatsList();
	~SeatsList();
	void clear();
	void insert(const Passenger&);
	void remove(int);
	void moveToStart();
	void moveToEnd();
	void prev();
	void next();
	int length() const;
	int currPos() const;
	void showPassengers();
	void showBoardingPass(int);
	void sort();
	int searchPassenger(string);
	bool isFull();
	bool isEmpty();
	void overWritePassenger(int, const Passenger&);
	int seatsAvailable();
	void genderStatistics();
	void sorthelp(Passenger[], Passenger[], int, int);
};
