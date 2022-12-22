
#include "SeatsAL.h"
#include <iostream>

SeatsList::SeatsList() {
	listSize = curr = 0;
	listArray = new Passenger[MSIZE];
}

SeatsList::~SeatsList() { delete[] listArray; }

void SeatsList::clear() {
	delete[] listArray;
	listSize = curr = 0;
	listArray = new Passenger[MSIZE];
}

void SeatsList::insert(const Passenger& guy) {
	if (listSize < MSIZE) {
		for (int i = listSize; i > curr; i--)
			listArray[i] = listArray[i - 1];
		listArray[curr] = guy;
		listSize++;
	}
}

void SeatsList::remove(int index) {
	for (int i = index; i < listSize - 1; i++) {
		listArray[i] = listArray[i + 1];
	}
	listSize--;
}

void SeatsList::moveToStart() { curr = 0; }

void SeatsList::moveToEnd() { curr = listSize; }

void SeatsList::prev() { if (curr != 0) curr--; }

void SeatsList::next() { if (curr < listSize)curr++; }

int SeatsList::length() const { return listSize; }

int SeatsList::currPos() const { return curr; }

void SeatsList::showPassengers() {
	for (moveToStart(); currPos() < length(); next()) {
		listArray[curr].showPassenger();
	}
}

void SeatsList::showBoardingPass(int index) {
	listArray[index].showPassenger();
}


void SeatsList::sort() {
	Passenger* tempArray = new Passenger[MSIZE];
	if (listSize == 0 || listSize == 1)
		return;
	sorthelp(listArray, tempArray, 0, listSize - 1);
}

void SeatsList::sorthelp(Passenger A[], Passenger temp[], int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	sorthelp(A, temp, left, mid);
	sorthelp(A, temp, mid + 1, right);
	for (int i = left; i <= right; i++)
		temp[i] = A[i];
	int i1 = left;
	int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++)
	{
		if (i1 == mid + 1)
			A[curr] = temp[i2++];
		else if (i2 > right)
			A[curr] = temp[i1++];
		else if (temp[i2].getPassno() > temp[i1].getPassno())
			A[curr] = temp[i1++];
		else
			A[curr] = temp[i2++];
	}
}


int SeatsList::searchPassenger(string findpassno) {
	int low = 0;
	int high = listSize - 1;
	int mid = 0;

	while (high >= low) {
		mid = (low + high) / 2;
		if (findpassno < listArray[mid].getPassno()) {
			high = mid - 1;
		}
		else if (findpassno == listArray[mid].getPassno()) return mid;
		else low = mid + 1;
	}
	return -1;
}

bool SeatsList::isFull() {
	return listSize == MSIZE;
}

bool SeatsList::isEmpty() {
	return listSize == 0;
}

void SeatsList::overWritePassenger(int index, const Passenger& guy) {
	listArray[index] = guy;
}

int SeatsList::seatsAvailable() { return MSIZE - listSize; }

void SeatsList::genderStatistics() {
	int men = 0;
	int women = 0;
	if (!isEmpty()) {
		for (int i = 0; i < listSize; i++) {
			string temp = listArray[i].getGender();
			for (int i = 0; i < temp.length(); i++)
				temp[i] = toupper(temp[i]);
			if (temp == "MALE")
				men++;
			else
				women++;
		}
		cout << "Women aboard: " << women << endl;
		cout << "Men aboard: " << men << endl;
	}
	else
		cout << "The Train is empty." << endl;
}