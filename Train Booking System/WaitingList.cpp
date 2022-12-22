#include "WaitingList.h"

WaitingList::WaitingList()
{
	maxSize = 11;
	rear = 0; front = 1;
	waitingArray = new Passenger[maxSize];
}

WaitingList::~WaitingList()
{
	delete[] waitingArray;
}

void WaitingList::clear()
{
	rear = 0; front = 1;
}

void WaitingList::enqueue(const Passenger& guy)
{
	if (((rear + 2) % maxSize) != front)
	{
		rear = (rear + 1) % maxSize;
		waitingArray[rear] = guy;
	}
	else
	{
		cout << "Sorry, the waiting list is full\n";
		return;
	}
}

void WaitingList::showQueue() {
	if (isEmpty()) {
		cout << "**********************************" << endl;
		cout << "*   The waiting list is empty.   *" << endl;
		cout << "**********************************" << endl;
	}
	else {
		cout << "***********************************" << endl;
		cout << "* Passengers in the waiting list: *" << endl;
		cout << "***********************************" << endl;
		for (int i = 1; i <= length(); i++) {
			waitingArray[i].showPassenger();
		}
	}
}

bool WaitingList::isEmpty()
{
	return length() == 0;
}

bool WaitingList::isFull() {
	return length() == maxSize - 1;
}

Passenger WaitingList::dequeue()
{
	Passenger person = waitingArray[front];
	front = (front + 1) % maxSize;
	return person;
}
const Passenger& WaitingList::frontValue() const
{
	return waitingArray[front];
}
