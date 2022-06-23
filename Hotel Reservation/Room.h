/**
** Program Name: Hotel Reservation
** File Name: Room.h
** Purpose: Declares the header for the Room class
** Author: Chiemi Mita
*/

#include "Date.h"
#include "Customer.h"

#ifndef Room_H_INCLUDED
#define Room_H_INCLUDED

using namespace std;

class Room{
public:

	Room();
	Room (Customer& c, Date checkIn, Date checkOut, int beds);

private:
    Customer customer;
	int bedsInRoom;

	Date checkOutDate;
    Date checkInDate;
};

#endif
