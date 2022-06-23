// Hotel.cpp file
// Description: This class models a Hotel
// Author: Chiemi Mita
// Creation date: Jan 22, 2020
// Reference: SLL class that posted on course materials

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Hotel.h"
#include "Room.h"
#include "SLL.h"
#include "Date.h"

using namespace std;

int Hotel::servedCustomers = 0;

// Returns the number of served customers
int Hotel::getServedCustomers(){
	return servedCustomers;
}

// Default constructor
Hotel::Hotel(){}

// Constructor to create a new Hotel with the given values
Hotel::Hotel (int oneBed, int twoBed, int threeBed){

    oneBedRoom;
    twoBedRoom;
    threeBedRoom;

}

void Hotel::book (string str){

    // Trim all white spaces
    str.erase( remove( str.begin(), str.end(), ' ' ), str.end() );

	istringstream ss(str);
	string item;
	vector<string> vect;

	while(getline(ss, item, ',')) {
		vect.push_back(item);
	}
	// Assign each information
	string checkInDate = vect[0];
    string id = vect[1];
    int beds = stoi(vect[2]);
    int staysDuration = stoi(vect[3]);

    Date checkIn(checkInDate);
    string checkOutDate = getCheckOutDate (checkIn, staysDuration);
    Date checkOut(checkOutDate);

    // Create a new Customer
    Customer c(id, beds);

    // Check vacancy
    // Assign a room if there's enough room available
    if (noVacancy(c))
        cout << "Sorry. Not available." << endl;
    else
        assignRoom(c, checkIn, checkOut, beds);
}

string Hotel::getCheckOutDate (Date inD, int staysDuration){
    string out;
    int day, month;
    int year = inD.getYear();
    int numOfDays = getNumDays(inD.getMonth());

    if ( numOfDays < inD.getDay() + staysDuration ){
        month = inD.getMonth() + 1;
        day = staysDuration - (numOfDays - inD.getDay());
    }else{
        month = inD.getMonth();
        day = inD.getDay() + staysDuration;
    }
    out = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

    return out;
}

bool Hotel::noVacancy(Customer& c){
    int totalBeds = 290;

    int availableBeds = totalBeds - (oneBedRoom.getSize() + twoBedRoom.getSize() + threeBedRoom.getSize());

    if (c.getRequestedBeds() > availableBeds )
        return true;
    return false;
}

void Hotel::assignRoom(Customer& c, Date in, Date out, int beds){
    servedCustomers++;

    Room r (c, in, out, beds);

    int remaining = c.getRequestedBeds();

    while (remaining > 0){
        if(remaining >= 3){
            threeBedRoom.addFirst(r);
            remaining -= 3;
        }
        else if (remaining == 2){
            twoBedRoom.addFirst(r);
            remaining -= 2;
        }
        else if (remaining == 1){
            oneBedRoom.addFirst(r);
            remaining -= 1;
        }
    }
}

int Hotel::getNumDays(int month){
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 28;
}


