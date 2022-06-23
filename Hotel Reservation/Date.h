// Date.h file
// Description: This class models a Date
// Author: Chiemi Mita
// Creation date: Jan 22, 2020

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
