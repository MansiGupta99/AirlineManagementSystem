/**********************************************************************************************
Owner: Mansi Gupta
In the following Code there are 3 classes: 
1. Date 
2. Booked Ticket 
3. Booking Utility

Date class: 
To set date and display Date.

Booked Ticket class: 
It stores all the ticket information that is booked by the user. 
Following data will stored in this class,
1. PNR
2. Name of passenger
3. Flight details, etc.

BookingUtility class:
This class will provide utility functions to gather information from user to book ticket.
Like,
1. Flight information to book
2. Get user payment and passenger booking information.

Global Function: 
Cancel Ticket: To delete/cancel the ticket which is booked earlier.
**********************************************************************************************/

//header files


#include<vector>
#include"Date.hpp"

using namespace std;

class BookedTicket;                  //class forward Declaration
class Date;							 //class forward Declaration
class BookingUtility;				 //class forward Declaration

static int  pnrInc = 239023;		//static inital value for pnr generation

vector<BookedTicket*> TicketBooked;   //vector declaration of class BookedTicket


//*************************************************************************************************

class BookedTicket
{
private:
	DateUtilities* date;														
	int pnr;												 
	string name, flightName, Dtime, Atime;					
public:
	BookedTicket();
	int getPNR();
	void displayInfo();
	void setFightName(string Name);
	void setDepartureTime(string timeOfDeparture);
	void setArrivalTime(string timeofArrival);
	void SetPassengerName(string Pname);
	DateUtilities* getDate();
	void setDate(DateUtilities* d);
};

///////////////////////////////////
// Booked Ticket constructor
///////////////////////////////////
BookedTicket::BookedTicket()		
{
	date = nullptr;
	Dtime.clear();
	Atime.clear();
	pnrInc = pnrInc + 10;
	pnr = pnrInc;
	name.clear();
	flightName.clear();
}

int BookedTicket::getPNR()
{
	return pnr;
}

DateUtilities* BookedTicket::getDate()
{
	return date;
}
void BookedTicket::setDate(DateUtilities* d)
{
	date = d;
}

void BookedTicket::setFightName(string Name)
{
	flightName = Name;
}

void BookedTicket::setDepartureTime(string timeOfDeparture)
{
	Dtime = timeOfDeparture;
}

void BookedTicket::setArrivalTime(string timeofArrival)
{
	Atime = timeofArrival;
}

void BookedTicket::SetPassengerName(string Pname)
{
	name = Pname;
}

void BookedTicket::displayInfo()
{
	cout << "PNR : " << pnr << endl;
	cout << "NAME  OF PASSENGER : " << name << endl;
	date->DisplayDateDefault();
	cout << "FLIGHT NAME : " << flightName << endl;
	cout << "TIME OF DEPARTURE: " << Dtime << endl;
	cout << "TIME OF ARRIVAL: " << Atime << endl;

}

//*************************************************************************************************

class  BookingUtility
{
private:
	int SourceID, TargetID;
	string Pname;
public:
	string getPassengerInfo(BookedTicket* b);
	void setPassengerInfo(string name);
	Date* getDate();
	void displayFlightInfo(int From, int To);
	void displayCities();
	void getSourceDestination();
	void paymentOfJouney();
	void StartBooking();
	void SelectedFlight(BookedTicket* b);
	string getTravellerName();
};

string BookingUtility::getPassengerInfo(BookedTicket* b)
{
	return  Pname;
}

void BookingUtility::setPassengerInfo(string name)
{
	name = getTravellerName();
	Pname = name;
}

void BookingUtility::displayFlightInfo(int SourceID, int TargetID)
{
	if ((SourceID == 1 && TargetID == 2) || (SourceID == 2 && TargetID == 1))
	{
		cout << "\t \t \tFlights Found" << endl << endl;
		cout << "   Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
		cout << "1. Air India(1)\t08:00\t\t11:00\t\tRs.5980\t\tNon-Refundable\n";
		cout << "2. Vistara(2)\t14:35\t\t17:35\t\tRs.4550\t\tNon-Refundable\n";
		cout << "3. Go Air(3)\t2:30\t\t5:30\t\tRs.6000\t\tNon-Refundable\n";
	}

	else if ((SourceID == 1 && TargetID == 3) || (SourceID == 3 && TargetID == 1))
	{
		cout << "\n**********Flights Found**********\n" << endl << endl;
		cout << "   Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
		cout << "1. Air India(1)\t09:00\t\t12:05\t\tRs.5980\t\tNon-Refundable\n";
		cout << "2. Vistara(2)\t15:35\t\t18:35\t\tRs.5500\t\tNon-Refundable\n";
		cout << "3. Go Air(3)\t1:00\t\t4:05\t\tRs.6000\t\tNon-Refundable\n";
	}

	else if ((SourceID == 1 && TargetID == 4) || (SourceID == 4 && TargetID == 1))
	{
		cout << "\n**********Flights Found**********\n" << endl << endl;
		cout << "   Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
		cout << "1. Air India(1)\t07:00\t\t10:05\t\tRs.5980\t\tNon-Refundable\n";
		cout << "2. Vistara(2)\t12:00\t\t3:05\t\tRs.5500\t\tNon-Refundable\n";
		cout << "3. Go Air(3)\t18:00\t\t21:05\t\tRs.6100\t\tNon-Refundable\n";
	}

	else if ((SourceID == 2 && TargetID == 3) || (SourceID == 3 && TargetID == 2))
	{
		cout << "\n**********Flights Found**********\n" << endl << endl;
		cout << "   Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
		cout << "1. Air India(1)\t08:00\t\t11:05\t\tRs.5980\t\tNon-Refundable\n";
		cout << "2. Vistara(2)\t14:00\t\t17:05\t\tRs.2500\t\tNon-Refundable\n";
		cout << "3. Go Air(3)\t19:00\t\t22:05\t\tRs.5500\t\tNon-Refundable\n";
	}

	else if ((SourceID == 2 && TargetID == 4) || (SourceID == 4 && TargetID == 2))
	{
		cout << "\n**********Flights Found**********\n" << endl << endl;
		cout << "   Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
		cout << "1. Air India(1)\t08:00\t\t11:05\t\tRs.2500\t\tNon-Refundable\n";
		cout << "2. Vistara(2)\t14:00\t\t17:05\t\tRs.5500\t\tNon-Refundable\n";
		cout << "3. Go Air(3)\t19:00\t\t22:05\t\tRs.6000\t\tNon-Refundable\n";
	}
	else if ((SourceID == 3 && TargetID == 4) || (SourceID == 4 && TargetID == 3))
	{
		cout << "\n**********Flights Found**********\n" << endl << endl;
		cout << "   Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
		cout << "1. Air India(1)\t08:00\t\t11:05\t\tRs.5800\t\tNon-Refundable\n";
		cout << "2. Vistara(2)\t14:00\t\t17:05\t\tRs.5508\t\tNon-Refundable\n";
		cout << "3. Go Air(3)\t19:00\t\t22:05\t\tRs.6050\t\tNon-Refundable\n";
	}
	else if (SourceID == TargetID)
	{
		cout << "\nSourceID and TargetID can't be same.\nPlease Enter Valid IDs\n\n\n" << endl;
		getSourceDestination();
	}
	else
	{
		cout << "\nWrong input entered\nPlease Enter Valid IDs\n\n\n" << endl;
		getSourceDestination();
	}
}

void BookingUtility::SelectedFlight(BookedTicket* b)
{
	int choice;
	string flightName, timeOfDeparture, timeofArrival;
	do
	{
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\n**********Flight selected:**********" << endl;
			cout << "Air India" << endl;
			flightName.assign("Air India");
			cout << "Departure Time : 08:00" << endl;
			cout << "Arrival Time: 11:05" << endl;
			timeOfDeparture.assign("8:00");
			timeofArrival.assign("11:05");
			cout << "\n************************************" << endl;
			break;

		case 2:
			cout << "\n**********Flight selected:**********" << endl;
			cout << "Vistara" << endl;
			flightName.assign("Vistara");
			cout << "Departure Time : 14:00" << endl;
			cout << "Arrival Time: 17:05" << endl;
			timeOfDeparture.assign("14:00");
			timeofArrival.assign("17:05");
			cout << "\n************************************" << endl;
			break;

		case 3:
			cout << "\n**********Flight selected:**********" << endl;
			cout << "Go Air" << endl;
			flightName.assign("Go Air");
			cout << "Departure Time : 19:00" << endl;
			cout << "Arrival Time: 22:05" << endl;
			timeOfDeparture.assign("19:00");
			timeofArrival.assign("22:05");
			cout << "\n************************************" << endl;
			break;

		default:
			cout << "Wrong input entered.\nTry again" << endl;
		}
	} while (choice < 1 || choice > 3);

	b->setFightName(flightName);
	b->setDepartureTime(timeOfDeparture);
	b->setArrivalTime(timeofArrival);
}

void BookingUtility::displayCities()
{
	cout << "----------CITIES LIST---------" << endl;
	cout << "1. PUNE" << endl;
	cout << "2. BOMBAY" << endl;
	cout << "3. BANGLORE" << endl;
	cout << "4. DELHI" << endl;
	cout << "----------CITIES LIST ENDED---------" << endl;
}

void BookingUtility::getSourceDestination()
{
	int To, From;
	bool ValidSourceID = false;
	bool ValidTargetID = false;

	displayCities();
	do
	{
		cout << "\nENTER SOURCE ID : ";
		cin >> To;
		if (To > 0 && To < 5)
		{
			SourceID = To;
			ValidSourceID = true;
		}
		else
		{
			cout << "Enter correct Source ID" << endl;
			ValidSourceID = false;
		}
	} while (!ValidSourceID);

	do
	{
		cout << "\nENTER DESTINATION ID : ";
		cin >> From;

		if (From > 0 && From < 5)
		{
			TargetID = From;
			ValidTargetID = true;
		}
		else
		{
			cout << "Enter correct Destination ID" << endl;
			ValidTargetID = false;
		}
	} while (!ValidTargetID);

	displayFlightInfo(SourceID, TargetID);
}

string getAValidNumberOfInputs(int numberOfInput)
{
	string number; 
	bool valid = true;

	do
	{
		valid = true;
		cout << "\nEnter the " << numberOfInput << " numbers:";
		cin >> number;

		if (number.length() > numberOfInput || number.length() < numberOfInput)
		{
			valid = false;
		}

		if (valid != false)
		{
			auto c = *(number.begin());

			if (c == '0')
			{
				valid = false;
			}
		}

		if (valid == false)
		{
			cout << "Please enter the valid number!!!" << endl;
		}
	} while (valid == false);
	return number;
}

void BookingUtility::paymentOfJouney()
{
	int option, bank;
	string number;
	string mmyy, card, cvv, otp, user_id;

	cout << "\n\n\nSELECT THE PAYMENT MODE:\n";
	do
	{
		cout << "\n 1. Debit Card(1) \n 2. Credit Card(2) \n 3. Net Banking(3) \n 4. Paytm(4)";
		cout << "\n\nEnter your option to be performed: ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "\nEnter Debit card no.: ";
			card = getAValidNumberOfInputs(12);
			cout << "\nEnter cvv: ";
			cvv = getAValidNumberOfInputs(3);
			cout << "\nEnter card validity date(mmyy): ";
			cin >> mmyy;
			cout << "\nTransaction Successful\n";
			cout << "\n************************************" << endl;
			break;
		case 2:
			cout << "\nEnter Credit card no.:";
			card = getAValidNumberOfInputs(12);
			cout << "\nEnter cvv: ";
			cvv = getAValidNumberOfInputs(3);
			cout << "\nEnter card validity date(mmyy): ";
			cin >> mmyy;
			cout << "\nTransaction Successful\n";
			cout << "\n************************************" << endl;
			break;
		case 3:
			cout << "Banks Available:  \n 1. ICICI Bank(1) \n 2. State Bank(2)  \n 3. Axis Bank(3) \n 4. Others(4)";
			cout << "\nSelect your bank: ";
			cin >> bank;
			cout << "\nYou have selected: " << bank;
			cout << "\nEnter user id: ";
			user_id = getAValidNumberOfInputs(10);
			cout << "\nEnter  OTP:";
			otp = getAValidNumberOfInputs(4);
			cout << "\nTransaction Successful\n";
			cout << "\n************************************" << endl;
			break;
		case 4:
			cout << "Enter your paytm number: ";
			number = getAValidNumberOfInputs(10);
			cout << "\nEnter OTP: ";
			otp = getAValidNumberOfInputs(6);
			cout << "\nTransaction Successful\n";
			cout << "\n************************************" << endl;
			break;
		default:
			cout << "\nChoose the write option";
		}
	} while (option < 0 || option > 4);
}

void BookingUtility::StartBooking()
{
	BookedTicket *b = new BookedTicket();
	string name = getTravellerName();
	b->SetPassengerName(name);
	DateUtilities* d = new DateUtilities();
	d->DateSelection();
	b->setDate(d);
	getSourceDestination();
	SelectedFlight(b);
	paymentOfJouney();
	TicketBooked.push_back(b);
	b->displayInfo();
}

string BookingUtility::getTravellerName()
{
	string name;
	getchar();
	cout << "ENTER THE PASSENGER NAME:";
	getline(cin, name);

	return name;
}

void CancelTicket()
{
	int pnr;
	int sureity;
	vector<BookedTicket*>::iterator itr;
	BookedTicket *b = nullptr;

	cout << "ENTER THE PNR YOU WANT TO CANCEL:";
	cin >> pnr;

	for (itr = TicketBooked.begin(); itr != TicketBooked.end(); ++itr)
	{
		if (pnr == (*itr)->getPNR())
		{
			(*itr)->displayInfo();
			b = *itr;
			break;
		}
	}

	if (b != nullptr)
	{
		cout << "\nAre you sure you want to delete: \t 1. yes \t 2. No : ";
		cin >> sureity;

		if (sureity == 1)
		{
			TicketBooked.erase(itr);
			delete b;
		}
	}
	else
	{
		cout << "NO TICKET FOUND WITH THIS PNR!!" << endl;
	}
}

int main()
{
	BookingUtility b;
	int choice;
	cout << "\n\n**********WELCOME TO THE AIRLINE BOOKING SERVICES**********" << endl;
	do
	{
		cout << "\n************************************" << endl;
		cout << "1. TICKET BOOKING" << endl;
		cout << "2. TICKET CANCEL" << endl;
		cout << "3. EXIT" << endl;
		cout << "ENTER THE OPTION TO BE PERFORMED : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			b.StartBooking();
			break;
		case 2:
			CancelTicket();
			break;
		}
	} while (choice > 0 && choice < 3);

	cout << "\n\n**********THANK YOU**********" << endl;
	cout << "\n\n!!!!!!!!!!VISIT AGAIN YOU!!!!!!!!!!" << endl;
	getchar();
	return 0;
}
