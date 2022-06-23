/**
** CPSC 1160 - Section 003 - Assignment 6
** Program Name: Poly
** Purpose: Implement a structure for representing polynomial with integer coefficients.
** Author: Chiemi Mita
** Student ID: 100320919
** Date: July 7, 2019
** Limitation: No known limitations
*/

#ifndef POLY_H_INCLUDED
#define POLY_H_INCLUDED

using namespace std;

struct Poly {
    int degree;
    int *coeff;
};

//Function prototypes
Poly* readPoly();
void outputPoly(const Poly* p, char x );
Poly* addPoly(const Poly* a, const Poly* b);
Poly* multPoly(const Poly* a,const Poly* b);
void deletePoly(Poly* &p);


#endif // POLY_H_INCLUDED
