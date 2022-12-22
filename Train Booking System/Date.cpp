#include "Date.h"
#include <ctime>

Date::Date()
{
	time_t ttime = time(0);
	char* dt = ctime(&ttime);
	cout<< dt << endl;
	tm *gmt_time = gmtime(&ttime);
}

Date::~Date()
{}

void Date::setDay(int d)
{
	day = d;
}

int Date::getDay()
{
	return day;
}

void Date::setMonth(int m)
{
	month = m;
}

int Date::getMonth()
{
	return month;
}

void Date::setYear(int y)
{
	year = y;
}

int Date::getYear()
{
	return year;
}

int Date::maxDaysInMonth(int d)
{
	int max = 0;
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		max = 31;
		break;
	case 4: case 6: case 9: case 11:
		max = 30;
		break;
	case 2:
	{
		if (isLeapYear(year))
			max = 29;
		else
			max = 28;
	}
	break;
	default:
		cout << "Error in month's days.";

	}
	return max;

}

bool Date::isDateValid(int d, int m, int y)
{
	bool flag, validDay, validMonth, validYear;
	flag = validDay = validMonth = validYear = false;


	if (y < 2020)
	{
		cout << "Please enter a year greater than 2020: ";
		cin >> y;
		while (y < 1582)
		{
			cout << "Please enter a year greater than 2020: ";
			cin >> y;
		}
		validYear = true;
		setYear(y);
	}
	else
	{
		validYear = true;
		setYear(y);
	}


	if (m >= 1 && m <= 12)
	{

		validMonth = true;
		setMonth(m);
	}
	else
	{
		cout << "Please enter a month between 1 and 12: ";
		cin >> m;
		while (m < 1 || m > 12)
		{
			cout << "Please enter a month between 1 and 12: ";
			cin >> m;
		}
		validMonth = true;
		setMonth(m);
	}

	int num = maxDaysInMonth(month);
	if (d < 1 || d > num)
	{
		cout << "Please enter a day between 1 and " << num << ": " << endl;
		cin >> d;
		while (d < 1 || d> num)
		{
			cout << "Please enter a day between 1 and " << num << ": " << endl;
			cin >> d;
		}
		validDay = true;
		setDay(d);

	}
	else
	{
		validDay = true;
		setDay(d);
	}

	if ((validDay == true) && (validMonth == true) && (validYear == true))
		flag = true;
	return flag;
}


bool Date::isLeapYear(int y)
{
	bool leap = false;
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		leap = true;

	return leap;
}

string Date::enterDate()
{
	string departureDate = "Not stated";
	int d, m, y;
	cout << "Day: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
	cout << "\n";


	if (isDateValid(d, m, y))
	{
		string str1 = static_cast<ostringstream*>(&(ostringstream() << getDay()))->str();
		string str2 = static_cast<ostringstream*>(&(ostringstream() << getMonth()))->str();
		string str3 = static_cast<ostringstream*>(&(ostringstream() << getYear()))->str();
		departureDate = str1 + "/" + str2 + "/" + str3;
	}
	return  departureDate;
}
