// testHotelReservation.cpp file
// Description: Tests the Hotel Reservation program
// Author: Chiemi Mita
// Creation date: Jan 22, 2020


#include <iostream>
#include <string>
#include <fstream>
#include "Hotel.h"


using namespace std;


int main() {

    // Create a Hotel with 100 one bedrooms, 50 two bedrooms, and 30 three bedrooms
    Hotel myHotel(100, 50, 30);

    int totalCustomers = 0;
    ifstream inFile( "Customers.txt" );
    string line;
    getline( inFile, line );
    while(getline( inFile, line )) {
        totalCustomers++;
        // Book each Customer
        myHotel.book(line);
    }

    cout << "\nTotal customers have been serviced: " << Hotel::getServedCustomers() << " / " << totalCustomers << endl;



    inFile.close();

    return 0;
}

