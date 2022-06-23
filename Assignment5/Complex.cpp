/**
** Program Name: Complex
** Purpose: implement a class for representing complex numbers. Implements and overloads operators for Complex class.
** Author: Chiemi Mita
** Limitation: No known limitations
*/

#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

//a and b are of type double and correspond to the complex number (a + bi)
Complex::Complex(double a, double b):real(a), imag(b) {};

// a is of type double and corresponds to the real number a without an imaginary part
Complex::Complex(double a):real(a), imag(0){};

//default constructor initializes the complex number to 0 (that is, to 0 + 0i).
Complex::Complex():real(0.0), imag(0.0){};


/** Obtain the absolute value of a complex number
* @params a Complex number object c1
* @return double type, an absolute value of the complex number
* pre and post conditions: none
*/
double abs(const Complex& c1){
    return sqrt (c1.real*c1.real + c1.imag*c1.imag);
}
/** Add two complex numbers
* @params two Complex number objects, c1 and c2
* @return a Complex number object of c1 plus c2
* pre and post conditions: none
*/
Complex operator+ (const Complex& c1, const Complex& c2){
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
/** Subtract two complex numbers
* @params two Complex number objects, c1 and c2
* @return a Complex number object of c1 minus c2
* pre and post conditions: none
*/
Complex operator- (const Complex& c1, const Complex& c2){
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
/** Multiply two complex numbers
* @params two Complex number objects, c1 and c2
* @return a Complex number object of c1 multiply by c2
* pre and post conditions: none
*/
Complex operator* (const Complex& c1, const Complex& c2){
    return Complex(c1.real * c2.real - c1.imag * c2.imag, c1.imag * c2.real - c1.real * c2.imag);
}
/** Divide two complex numbers
* @params two Complex number objects, c1 and c2
* @return a Complex number object of c1 divided by c2
* pre conditions: none
*/
Complex operator/ (const Complex& c1, const Complex& c2){
    Complex c;
    c.real = ((c1.real * c2.real) + (c1.imag * c2.imag))/((c2.real*c2.real) + (c2.imag*c2.imag));
    c.imag=((c1.imag * c2.real) + (c1.real * c2.imag))/((c2.real*c2.real) + (c2.imag*c2.imag));
    return c;
}
/** Divide a complex number by a real number
* @params a Complex number object(c1) and an int type number(num)
* @return a Complex number object of c1 divided by num
* pre conditions: int number(num) must be positive
*/
Complex operator/ (const Complex& c1, const int num){
    return Complex(c1.real/num, c1.imag/num);
}
/** Test for equality between two complex numbers
* @params two Complex number objects, c1 and c2
* @return boolean "0" for false or "1" for true
* pre and post conditions: none
*/
bool operator==(const Complex& c1, const Complex& c2){
    return (c1.real == c2.real && c1.imag == c2.imag);
}
/** Test if two complex numbers are not equal
* @params two Complex number objects, c1 and c2
* @return boolean "0" for false or "1" for true
* pre and post conditions: none
*/
bool operator!=(const Complex& c1, const Complex& c2){
    return  !(c1.real == c2.real && c1.imag == c2.imag);
}
/** Overload the input operator and assign the first value to a real part, second to a imaginary part of a Complex number object)
* @params an input stream (in) and a Complex number object(c1)
* @return an input stream
* preconditions: c1 must be declared
* postconditions: both real part and imaginary part of c1 will be assigned
*/
istream& operator>> (istream& in, Complex& c1){
    in >> c1.real; //assign real part
    in >> c1.imag; //assign imaginary part
    return in;
}
/** Overload the output operator
* @params an output stream(out) and a Complex number object (c1)
* @return an output stream
* preconditions: c1 must be initialized
* postconditions: (real part of c1(double type)+imaginary part of c1(double type)i)
*/
ostream& operator<< (ostream& out, const Complex& c1){
    out << "(" << c1.real;
    if (c1.imag<0)
       out << "-";
    else
        out << "+";
    out <<  fabs(c1.imag);
    out << "i)";
    return out;
}

/* Bonus part */
/** Add the second Complex number to the first Complex number
* @params two Complex number objects, c1 and c2
* @return the first Complex number object, c1. (return by reference)
* preconditions: both c1 and c2 must be initialized
* postconditions: the real part of c1 will be real part of c1 plus real part of c2.
* The imaginary part of c1 will be imaginary part of c1 plus imaginary part of c2
*/
Complex& operator+= (Complex& c1, const Complex& c2){
    c1.real += c2.real;
    c1.imag += c2.imag;
    return c1;
}
/** Subtract the second Complex number from the first Complex number
* @params two Complex number objects, c1 and c2.
* @return the first Complex number object, c1. (return by reference)
* preconditions: both c1 and c2 must be initialized
* postconditions: the real part of c1 will be real part of c1 minus real part of c2.
* The imaginary part of c1 will be imaginary part of c1 minus imaginary part of c2
*/
Complex& operator-= (Complex& c1, const Complex& c2){
    c1.real -= c2.real;
    c1.imag -= c2.imag;
    return c1;
}
/** Changes the sign of the real and/or imaginary part of a Complex number from negative to positive
* @params a Complex number object, c1.
* @return a Complex number object (a copy of c1 with its sign(s) changed (if it was negative))
* preconditions: c1 must be initialized
* postconditions: none
*/
Complex operator+ (const Complex& c1){
    Complex c;
    //Change the sign if negative
    if (c1.real < 0)
        c.real = -(c1.real);
    else
        c.real = c1.real;
    //Change the sign if negative
    if (c1.imag < 0)
        c.imag = -(c1.imag);
    else
        c.imag = c1.imag;
    return c;
}
/** Changes the sign of the real and/or imaginary part of a Complex number from positive to negative
* @params a Complex number object, c1.
* @return a Complex number object (a copy of c1 with its sign(s) changed(if it was positive))
* preconditions: c1 must be initialized
* postconditions: none
*/
Complex operator- (const Complex& c1){
    Complex c;
    //Change the sign if positive
    if (c1.real > 0)
        c.real = -(c1.real);
    else
        c.real = c1.real;
    //Change the sign if positive
    if (c1.imag > 0)
        c.imag = -(c1.imag);
    else
        c.imag = c1.imag;
    return c;
}
/** ++Prefix increment both real and imaginary part of a Complex number by 1.
* @params a Complex number object, c1.
* @return a Complex number object, c1 (return by reference)
* preconditions: c1 must be initialized
* postconditions: the real part and the imaginary part of c1 will be incremented by 1.
*/
Complex& operator++ (Complex& c1){
    c1.real++; //increment real part
    c1.imag++; //increment imaginary part
    return c1;
}
/** Postfix++ increment both real and imaginary part of a Complex number by 1.
* @params a Complex number object, c1.
* @return a Complex number object (a copy of c1 with its real part and the imaginary part being incremented)
* pre and post conditions: none
*/
Complex operator++ (const Complex& c1, int dummy){
    return Complex (c1.real+1, c1.imag+1);
}
/** --Prefix decrement both real and imaginary part of a Complex number by 1.
* @params a Complex number object, c1.
* @return a Complex number object, c1 (return by reference)
* preconditions: c1 must be initialized
* postconditions: the real part and the imaginary part of c1 will be decremented by 1.
*/
Complex& operator-- (Complex& c1){
    c1.real--; //decrement real part
    c1.imag--; //decrement imaginary part
    return c1;
}
/** Postfix-- decrement both real and imaginary part of a Complex number by 1.
* @params a Complex number object, c1.
* @return a Complex number object (a copy of c1 with its real part and the imaginary part being decremented)
* pre and post conditions: none
*/
Complex operator-- (const Complex& c1, int dummy){
    return Complex (c1.real-1, c1.imag-1);
}

