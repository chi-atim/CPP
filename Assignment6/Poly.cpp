/**
** Program Name: Poly
** Purpose: Implement a structure for representing polynomial with integer coefficients.
** Author: Chiemi Mita
** Limitation: No known limitations
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Poly.h"

using namespace std;

/**Reads the degree and coefficients of a polynomial from standard input and creates a poly struct
* @params none
* @return a pointer to the poly
*/
Poly* readPoly() {
    int resultDeg;

    //Read and assign degree
    cout << "Input the degree: ";
    cin >> resultDeg;
    if (resultDeg<0){
        cout << "Invalid input" << endl;
        exit(1);
    }
    int *resultCoeffs = new int[resultDeg+1];

    //Read and assign each coefficient
    for (int i=0; i<resultDeg+1; i++){
        cout << "Input a coefficient [" << i << "]: ";
        cin >> resultCoeffs[i];
    }
    //Create a new polynomial
    Poly* resultPoly = new Poly;
    resultPoly->degree = resultDeg;
    resultPoly->coeff = resultCoeffs;
    return resultPoly;
}

/**Outputs a polynomial to standard output with the variable x
* @params Polynomial p, char x
* @return none
* precondition: degree must be positive
* postcondition: print the poly with a form of "(coefficient)*(char)^(index of coefficient array)"
*/
void outputPoly(const Poly* p, char x){
    //if degree of the poly is 0 (a constant)
    if (p->degree==0)
        //print the constant
        cout << p->coeff[0];
    //if degree is larger than 0
    else{
        //if the constant is not 0
        if (p->coeff[0]!=0)
            //print the constant
            cout << p->coeff[0];
    }
    //print the rest of the polynomial
    for (int i=1; i<= p->degree; i++){
        //if the coefficient is positive
        if(p->coeff[i]>0)
            //print additional plus sign(+) and the the rest of polynomial
            cout << " + " << p->coeff[i] << "*"<< x << "^" << i;
        //if the coefficient is negative
        else if (p->coeff[i]<0)
            //simply print the the rest of polynomial
            cout << p->coeff[i] << "*"<< x << "^" << i;
    }
    cout << endl;
}
/**Computes the sum of two polynomials
* @params two Polynomials, a and b
* @return a pointer * @return a pointer to the polyto the new poly struct which is the sum of a and b
*/
Poly* addPoly(const Poly* a, const Poly* b){
    int i, resultDeg;

    // assign the largest degree of a and b as resultDeg
    if(a->degree >= b->degree)
        resultDeg = a->degree;
    else
        resultDeg = b->degree;

    int *resultCoeffs = new int[resultDeg+1];

    //if a->degree is larger than b->degree
    if (a->degree > b->degree) {
        //Assign sum of coeffs of a and b to resultCoeffs until degree of b
        for (i=0; i<=b->degree; i++)
            resultCoeffs[i] = a->coeff[i]+b->coeff[i];
        //Assign coeff of a to the rest of resultCoeffs
        for (i=b->degree+1; i<resultDeg+1; i++)
            resultCoeffs[i] = a->coeff[i];
    }
    //if b->degree is larger than a->degree
    else if (a->degree < b->degree) {
        //Assign sum of coeffs of a and b to resultCoeffs until degree of a
        for (i=0; i<=a->degree; i++)
            resultCoeffs[i] = a->coeff[i]+b->coeff[i];
        //Assign coeff of b to the rest of resultCoeffs
        for (i=a->degree+1; i<resultDeg+1; i++)
            resultCoeffs[i] = b->coeff[i];
    }
    //b->degree and a->degree are the same
    else{
        //Assign sum of coeffs of a and b to resultCoeffs
        for (i=0; i<resultDeg+1; i++)
            resultCoeffs[i] = a->coeff[i]+b->coeff[i];
    }

    //Create a new polynomial
    Poly *resultPoly;
    resultPoly = new Poly;
    resultPoly->degree = resultDeg;
    resultPoly->coeff = resultCoeffs;

    return resultPoly;
}

/**Computes the product of two polynomials
* @params two Polynomials, a and b
* @return a pointer to the new poly struct which is the product of a and b
* pre and post condition: none
*/
Poly* multPoly(const Poly* a, const Poly* b){
    int resultDeg = a->degree + b->degree;
    int* resultCoeffs = new int[resultDeg+1];

    //Initialize all coefficients to 0
    for (int i=0; i<resultDeg+1; i++)
        resultCoeffs[i]=0;
    //Multiply coefficients and add to the index of the degree
    for (int i=0; i<a->degree+1; i++)
        for (int j=0; j<b->degree+1; j++)
            resultCoeffs[i+j] += a->coeff[i] * b->coeff[j];

    //Create a new polynomial
    Poly* resultPoly = new Poly;
    resultPoly->degree = resultDeg;
    resultPoly->coeff = resultCoeffs;
    return resultPoly;
}

/**Delete a polynomial
* @params a pointer to a poly
* @return none
* post condition: sets p to the nullptr
*/
void deletePoly(Poly* &p) {
   delete[] p->coeff; // Delete array first
   delete p;
   p = nullptr;
}
