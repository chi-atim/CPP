/**
** Program Name: Hotel Reservation
** File Name: Date.h
** Purpose: Declares the header for the Date class
** Author: Chiemi Mita
*/

#ifndef Date_H_INCLUDED
#define Date_H_INCLUDED

using namespace std;

class Date{
public:

	Date();

	Date (string s);

	int getYear() const;
	int getMonth() const;
	int getDay() const;

private:
	int year, month, day;
};

#endif
