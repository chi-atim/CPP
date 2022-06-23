// Room.cpp file
// Description: This class models a Room
// Author: Chiemi Mita
// Creation date: Jan 22, 2020

#include <iostream>
#include "Room.h"

using namespace std;

// Default constructor
Room::Room(){}

// Constructor to create a new Room with the given values
Room::Room (Customer& c, Date checkIn, Date checkOut, int beds){
    customer = c;
    checkInDate = checkIn;
    checkOutDate = checkOut;
    bedsInRoom = beds;
}






