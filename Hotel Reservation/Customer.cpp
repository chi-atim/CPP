// Customer.cpp file
// Description: This class models a Customer
// Author: Chiemi Mita
// Creation date: Jan 22, 2020

#include <iostream>
#include <string>

#include "Customer.h"

using namespace std;

// Default constructor
Customer::Customer(){}

// Constructor to create a new Customer with the given values
Customer::Customer (string id, int beds){
    customerID = id;
    requestedBeds = beds;
}

// Returns the customer ID
string Customer::getCustomerID() const{
    return customerID;
}
// Returns the number of requested beds
int Customer::getRequestedBeds() const{
    return requestedBeds;
}



