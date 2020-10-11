#include"Date.hpp"
#include<ctime>

using namespace std;

DateUtilities::DateUtilities()
{
	dd = 0;
	mm = 0;
	yyyy = 0;
	dayId = 0;
}

void DateUtilities::SetDate(int d, int m, int y)
{
	dd = d;
	mm = m;
	yyyy = y;
	dayId = GetDayID(dd, mm, yyyy);
}

void DateUtilities::DisplayDateDefault()
{
	cout << dd << "/" << mm << "/" << yyyy << " " << GetDayInString() << endl;
}

void DateUtilities::DisplayDate()
{
	int option;

	do
	{
		cout << "1.DD/MM/YYYY" << endl;
		cout << "2.DD-MM-YYYY" << endl;
		cout << "3.YYYY/MM/DD" << endl;
		cout << "4.YYYY-MM-DD" << endl;
		
		cout << "\nEnter the option to select pattern of date:";
		cin >> option;

		switch (option)
		{
			case 1: 
				cout << dd << "/" << mm << "/" << yyyy << " " << GetDayInString() << endl;
				break;
			case 2:
				cout << dd << "-" << mm << "-" << yyyy << " " << GetDayInString() << endl;
				break;
			case 3:
				cout << yyyy << "/" << mm << "/" << dd << " " << GetDayInString() << endl;
				break;
			case 4:
				cout << yyyy << "-" << mm << "-" << dd << " " << GetDayInString() << endl;
				break;
			default:
				cout << "Wrong option Selected!!" << endl;
		}
	} while (option > 0 && option <= 4);
}

string DateUtilities::GetDayInString()
{
	string dayName;

	if (dayId == 1)
	{
		dayName.append("Monday");
	}
	else if (dayId == 2)
	{
		dayName.append("Tuesday");
	}
	else if (dayId == 3)
	{
		dayName.append("Wednesday");
	}
	else if (dayId == 4)
	{
		dayName.append("Thursday");
	}
	else if (dayId == 5)
	{
		dayName.append("Friday");
	}
	else if (dayId == 6)
	{
		dayName.append("Saturday");
	}
	else if (dayId == 0)
	{
		dayName.append("Sunday");
	}
	else
	{
		cout << "Wrong Day!!" << endl;
	}

	return dayName;
}

int DateUtilities::GetDayID(int dd, int mm, int yyyy)
{
	int D, C,m = mm;          //D: last two digit  C: the first two digit
	D =yyyy%100 ;
	C = yyyy / 100;
	
	if (mm == 1)
	{
		m = 11;
	}

	else if (mm == 2)
	{
		m = 12;
	}

	else
	{
		m = m - 2;
	}
	int F = dd + int(((13 * m) - 1) / 5) + D + int(D / 4) + int(C / 4) - (2*C);

	int day = F % 7;

	return day;
}


void DateUtilities::CurrentDate()
{
	int  t_dd;
	int  t_mm;
	int  t_yy;

	// current date/time based on current system
	time_t now = time(0);
	
	tm ltm;
	localtime_s(&ltm, &now);
	t_yy = ltm.tm_year + 1900;			 //t_yy = today year
	t_mm = ltm.tm_mon + 1;				//t_mm = today month
	t_dd = ltm.tm_mday;					//t_dd = today day
	
	cout << "Current Date:" << t_dd << "/" << t_mm << "/" << t_yy << endl;
}

bool DateUtilities::checkLeapYear(int yyyy)
{
	bool leapyear = false;
	if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
	{
		leapyear = true;
	}
	return leapyear;
}

bool  DateUtilities::validMonth(int mm, int dd, int yyyy)
{
	bool validMonth = false;
	bool leapyear = checkLeapYear(yyyy);

	if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && dd <= 31 && dd > 0)
	{	
		validMonth = true;
	}
	else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd <= 30 && dd > 0)
	{
		validMonth = true;
	}
	else if (mm == 2)
	{
		if ((leapyear == true) && dd > 0 && dd <= 29)
		{
			validMonth = true;
		}
		else if (dd > 0 && dd <= 28)
		{
			validMonth = true;
		}
	}
	return validMonth;
}

void DateUtilities::DateSelection()
{
	int dd, t_dd;
	int mm, t_mm;
	int yyyy, t_yy;
	bool validDate = false;
	CurrentDate();
	
	// current date/time based on current system
	time_t now = time(0);

	tm ltm;
	localtime_s(&ltm, &now);
	t_yy = ltm.tm_year + 1900;			 //t_yy = today year
	t_mm = ltm.tm_mon + 1;				//t_mm = today month
	t_dd = ltm.tm_mday;					//t_dd = today day

	do
	{
		validDate = false;

		cout << "ENTER YEAR:";
		cin >> yyyy;

		if (yyyy > (t_yy + 1))
		{
			cout << "Enterd year booking not possible" << endl;
		}
		else
		{			
			cout << "ENTER MONTH:";
			cin >> mm;
			cout << "ENTER DAY:";
			cin >> dd;

			if (yyyy > t_yy)
			{
				validDate = false;
				validDate = validMonth(mm, dd, yyyy);

			}
			else if (yyyy == t_yy)
			{
				if (mm > t_mm)
				{
					validDate = false;
					validDate = validMonth(mm, dd, yyyy);
				}
				else if (mm == t_mm && dd > t_dd)
				{
					validDate = false;
					bool validDay = validMonth(mm, dd, yyyy);
					if ((validDay == true) && dd > t_dd)
					{
						validDate = true;
					}

				}
			}

			if (validDate == false)
			{
				cout << "\nPLEASE ENTER THE VALID DATE" << endl;
			}

			else
			{
				SetDate(dd, mm, yyyy);
			}
		}
	} while (!validDate);
}


