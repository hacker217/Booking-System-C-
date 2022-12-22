#pragma once
#include <string>

using namespace std;

class Passenger {
private:
	string passno, name, gender, departureDate;
	int ticketno;
public:
	Passenger();
	Passenger(string, string, string, string);
	void operator=(Passenger);
	void showPassenger();
	void readDatabase();
	string getPassno();
	string getGender();
	int getRandomTicket();
};

