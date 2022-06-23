/**
** Program Name: Hotel Reservation
** File Name: Hotel.h
** Purpose: Declares the header for the Hotel class
** Author: Chiemi Mita
*/

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
