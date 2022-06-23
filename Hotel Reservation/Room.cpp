/**
** Program Name: Hotel Resesrvation
** File Name: Room.cpp
** Purpose: Implements the Room class methods
** Author: Chiemi Mita
*/

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






