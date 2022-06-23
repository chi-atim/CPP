/**
** Program Name: Hotel Reservation
** File Name: Date.cpp
** Purpose: Implements the Date class methods
** Author: Chiemi Mita
*/

#include <iostream>
#include <string>

#include "Date.h"

using namespace std;

// Default constructor
Date::Date(){}

// Constructor
Date::Date (string s){

    string deli = "/";
    day = stoi(s.substr(0, s.find(deli)));
    month = stoi(s.substr(s.find(deli)+1, s.find(deli)));
    year = 2018;

}
int Date::getYear() const{ return year;}
int Date::getMonth() const{ return month;}
int Date::getDay() const{ return day;}





