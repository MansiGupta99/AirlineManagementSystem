#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class DateUtilities
{
private:
	int dd, mm, yyyy;
	int dayId;

	void CurrentDate();
	bool checkLeapYear(int yyyy);
	bool validMonth(int mm, int dd, int yyyy);
	int GetDayID(int dd, int mm, int yyyy);
	string GetDayInString();

public:

	DateUtilities();
	void SetDate(int d, int m, int y);
	void DateSelection();
	void DisplayDate();
	void DisplayDateDefault();
};

