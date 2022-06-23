/**
** CPSC 1160 - Section 003 - Assignment 5
** Program Name: Complex
** Purpose: implement a class for representing complex numbers. Implements and overloads operators for Complex class.
** Author: Chiemi Mita
** Student ID: 100320919
** Date: July 1, 2019
** Limitation: No known limitations
*/

#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

using namespace std;

class Complex{
    public:

        // Define constructors
        Complex(double a, double b);
        Complex(double a);
        Complex();

        // Define accessors
        double getReal() const { return real; }
        double getImag() const { return imag; }

        // Define abs() function
        friend double abs(const Complex& c1);

        // Define overload operators
        friend Complex operator+ (const Complex& c1, const Complex& c2);
        friend Complex operator- (const Complex& c1, const Complex& c2);
        friend Complex operator* (const Complex& c1, const Complex& c2);
        friend Complex operator/ (const Complex& c1, const Complex& c2);
        friend Complex operator/ (const Complex& c1, const int num);
        friend bool operator==(const Complex& c1, const Complex& c2);
        friend bool operator!=(const Complex& c1, const Complex& c2);
        friend istream& operator>> (istream& in, Complex& c1);
        friend ostream& operator<< (ostream& out, const Complex& c1);
        friend Complex& operator+= (Complex& c1, const Complex& c2);
        friend Complex& operator-= (Complex& c1, const Complex& c2);
        friend Complex operator+ (const Complex& c1);//unary +
        friend Complex operator- (const Complex& c1);//unary -
        friend Complex& operator++ (Complex& c1); //++Prefix increment
        friend Complex operator++ (const Complex& c1, int dummy);//Postfix++ increment
        friend Complex& operator-- (Complex& c1); //+--Prefix increment
        friend Complex operator-- (const Complex& c1, int dummy);//Postfix-- increment

    private:
        double real, imag;
};
//Define a constant i
const Complex i (0, 1);

#endif
