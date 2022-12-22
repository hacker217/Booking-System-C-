#include "Passenger.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

Passenger::Passenger() {
	passno = "DEFAULT STRING";
	name = "DEFAULT STRING";
	gender = "DEFAULT STRING";
	departureDate = "DEFAULT STRING";
	ticketno = 0;
}

Passenger::Passenger(string passno, string name, string gender, string departureDate)
{
	this->passno = passno;
	this->name = name;
	this->gender = gender;
	this->departureDate = departureDate;
	ticketno = getRandomTicket();
}

void Passenger::operator=(Passenger equal) {
	this->passno = equal.passno;
	this->name = equal.name;
	this->gender = equal.gender;
	this->departureDate = equal.departureDate;
	this->ticketno = equal.ticketno;
}

void Passenger::showPassenger() {
	cout << "Passport number: " << passno << endl;
	cout << "Name: " << name << endl;
	cout << "Gender: " << gender << endl;
	cout << "Ticket number: " << ticketno << endl;
	cout << "Departure date: " << departureDate << endl;
}

/*void Passenger::readDatabase() {
	ifstream infile;
	string passno, name, gender, departureDate;
	string ticketno;
	infile.open("Passenger_DataBase.txt");
	if (infile.is_open() && !infile.eof()) {
		for (int i = 1; !infile.eof(); i++) {
			infile >> passno >> name >> gender >> departureDate >> ticketno;
			append(passno, name, gender, departureDate, ticketno)
		}

	}
	infile.close();
}
*/
string Passenger::getPassno() { return passno; }

string Passenger::getGender() { return gender; }

int Passenger::getRandomTicket() {
	int min = 10000;
	int max = 99999;
	return min + (rand() % (int)(max - min + 1));
}
