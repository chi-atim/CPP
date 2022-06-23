// Room.h file
// Description: This class models a Room
// Author: Chiemi Mita
// Creation date: Jan 22, 2020
// Reference: SLL class that posted on course materials

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
