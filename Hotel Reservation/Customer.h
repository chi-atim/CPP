/**
** Program Name: Hotel Reservation
** File Name: Customer.h
** Purpose: Declares the header for the Customer class
** Author: Chiemi Mita
*/


#ifndef Customer_H_INCLUDED
#define Customer_H_INCLUDED

using namespace std;

class Customer{
public:
	Customer();
	Customer (string id, int beds);

	string getCustomerID() const;
	int getRequestedBeds() const;

private:
	string customerID;
	int requestedBeds;

};

#endif
