// Hotel.h file
// Description: This class models a Hotel
// Author: Chiemi Mita
// Creation date: Jan 22, 2020
// Reference: SLL class that posted on course materials


#include "Customer.h"
#include "SLL.h"
#include "Date.h"
#include "Room.h"

#ifndef Hotel_H_INCLUDED
#define Hotel_H_INCLUDED

using namespace std;


class Hotel{
public:
	Hotel();
	Hotel (int oneBed, int twoBed, int threeBed);

	void book(string str);

	bool noVacancy(Customer& c);
	void assignRoom (Customer& c, Date in, Date out, int beds);
	int checkAllRooms(Hotel& h);

	string getCheckOutDate (Date inD, int staysDuration);
	int getNumDays(int month);

	static int getServedCustomers();

private:
    SLL<Room> oneBedRoom;
    SLL<Room> twoBedRoom;
    SLL<Room> threeBedRoom;

    static int servedCustomers;
};

#endif
