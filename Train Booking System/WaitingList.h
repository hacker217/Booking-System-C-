#pragma once
#include "Passenger.h"
#include <iostream>

class WaitingList
{
private:
	int maxSize;
	int front;
	int rear;
	Passenger* waitingArray;

public:
	WaitingList();
	~WaitingList();
	void clear();
	void enqueue(const Passenger&);
	Passenger dequeue();
	const Passenger& frontValue() const;
	virtual int length() const
	{
		return ((rear + maxSize) - front + 1) % maxSize;
	}
	void showQueue();
	bool isEmpty();
	bool isFull();
};
