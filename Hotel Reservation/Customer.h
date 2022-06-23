// Customer.h file
// Description: This class models a Customer
// Author: Chiemi Mita


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
