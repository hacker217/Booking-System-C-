
#include <sstream>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Date
{
private:
	int year, month, day;

public:
	Date();
	~Date();
	void setDay(int);
	int getDay();
	void setMonth(int);
	int getMonth();
	void setYear(int);
	int getYear();
	int maxDaysInMonth(int);
	bool isDateValid(int, int, int);
	bool isLeapYear(int);
	string enterDate();

};
