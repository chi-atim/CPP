/**
** Program Name: Poly
** Purpose: Implement a structure for representing polynomial with integer coefficients.
** Author: Chiemi Mita
** Limitation: No known limitations
*/

#include <iostream>
#include "Poly.h"

using namespace std;

int main(){

    // Test readPoly and outputPoly
    cout << "Expected result of (input degree: 3, Input coefficients: 2 -7 0 4): 2-7*x^1 + 4*x^3" << endl;
    Poly *p1 = readPoly();
    cout << "Actual result: ";
    outputPoly(p1, 'x');

    int deg = 3;
    int* coefficient;
    // create a dynamic array of coefficients
    coefficient = new int[deg+1];
    coefficient[0] = 2;
    coefficient[1] = -7;
    coefficient[2] = 0;
    coefficient[3] = 4;
    Poly *p = new Poly;
    p->degree = deg;
    p->coeff = coefficient;

    //Test addPoly, multPolly, and deletePoly for a = 1 + 2*x^1 + 3*x^2 and b = 1 + 1*x^1 + x^2
    //create a Polly a = 1 + 2*x^1 + 3*x^2
    int degA1 = 2;
    int* coefficientA1;
    coefficientA1 = new int[degA1+1];
    coefficientA1[0] = 1;
    coefficientA1[1] = 2;
    coefficientA1[2] = 3;
    Poly *pA1 = new Poly;
    pA1->degree = degA1;
    pA1->coeff = coefficientA1;

    //create a Polly b = 1 + 1*x^1 + x^2*
    int degB1 = 2;
    int* coefficientB1;
    coefficientB1 = new int[degB1+1];
    coefficientB1[0] = 1;
    coefficientB1[1] = 1;
    coefficientB1[2] = 1;
    Poly *pB1 = new Poly;
    pB1->degree = degB1;
    pB1->coeff = coefficientB1;

    // Test addPoly
    cout << "\nExpected result: 2 + 3*x^1 + 4*x^2" << endl;
    cout << "Actual result: ";
    outputPoly(addPoly(pA1, pB1), 'x');

    // Test multPolly
    cout << "Expected result: 1 + 3*x^1 + 6*x^2 + 5*x^3 + 3*x^4"<< endl;
    cout << "Actual result: ";
    outputPoly(multPoly(pA1, pB1), 'x');

    // Test deletePolly
    deletePoly(pA1);
    deletePoly(pB1);


    //Test addPoly, multPolly, and deletePoly for a = 1 + 1*x^1 + 1*x^2 and b = 1 + 1*x^1 + 1*x^2 + 1*x^3 + 1*x^4
    //create a Polly a = 1 + 1*x^1 + 1*x^2
    int degA2 = 2;
    int* coefficientA2;
    coefficientA2 = new int[degA2+1];
    coefficientA2[0] = 1;
    coefficientA2[1] = 1;
    coefficientA2[2] = 1;
    Poly *pA2 = new Poly;
    pA2->degree = degA2;
    pA2->coeff = coefficientA2;

    //create a Polly b = 1 + 1*x^1 + 1*x^2 + 1*x^3 + 1*x^4
    int degB2 = 4;
    int* coefficientB2;
    coefficientB2 = new int[degB2+1];
    coefficientB2[0] = 1;
    coefficientB2[1] = 1;
    coefficientB2[2] = 1;
    coefficientB2[3] = 1;
    coefficientB2[4] = 1;
    Poly *pB2 = new Poly;
    pB2->degree = degB2;
    pB2->coeff = coefficientB2;

    // Test addPoly
    cout << "\nExpected result: 2 + 2*x^1 + 2*x^2 + 1*x^3 + 1*x^4" << endl;
    cout << "Actual result: ";
    outputPoly(addPoly(pA2, pB2), 'x');

    // Test multPolly
    cout << "Expected result: 1 + 2*x^1 + 3*x^2 + 3*x^3 + 3*x^4 + 2*x^5 + 1*x^6"<< endl;
    cout << "Actual result: ";
    outputPoly(multPoly(pA2, pB2), 'x');

    // Test deletePollyb = 1 + x + x^2
    deletePoly(pA2);
    deletePoly(pB2);


    //Test addPoly, multPolly, and deletePoly for a = 0 and b = 1 + x + x^2
    //create a Polly a = 0
    int degA3 = 0;
    int* coefficientA3;
    coefficientA3 = new int[degA3+1];
    coefficientA3[0] = 0;
    Poly *pA3 = new Poly;
    pA3->degree = degA3;
    pA3->coeff = coefficientA3;

    //create a Polly b = 1 + 1*x^1 + x^2
    int degB3 = 2;
    int* coefficientB3;
    coefficientB3 = new int[degB3+1];
    coefficientB3[0] = 1;
    coefficientB3[1] = 1;
    coefficientB3[2] = 1;
    Poly *pB3 = new Poly;coefficientA3[0] = 0;
    pB3->degree = degB3;
    pB3->coeff = coefficientB3;

    // Test addPoly
    cout << "\nExpected result: 1 + 1*x^1 + 1*x^2" << endl;
    cout << "Actual result: ";
    outputPoly(addPoly(pA3, pB3), 'x');

    // Test multPolly
    cout << "Expected result: 0"<< endl;
    cout << "Actual result: ";
    outputPoly(multPoly(pA3, pB3), 'x');

    // Test deletePolly
    deletePoly(pA3);
    deletePoly(pB3);


    //Test addPoly, multPolly, and deletePoly for a = 1 + 2*x^1 + 3*x^2 and b = 1 - 2*x^1 - 3*x^2
    //create a Polly a = 1 + 2*x^1 + 3*x^2
    int degA4 = 2;
    int* coefficientA4;
    coefficientA4 = new int[degA4+1];
    coefficientA4[0] = 1;
    coefficientA4[1] = 2;
    coefficientA4[2] = 3;
    Poly *pA4 = new Poly;
    pA4->degree = degA4;
    pA4->coeff = coefficientA4;

    //create a Polly b = 1 - 2*x^1 - 3*x^2
    int degB4 = 2;
    int* coefficientB4;
    coefficientB4 = new int[degB4+1];
    coefficientB4[0] = 1;
    coefficientB4[1] = -2;
    coefficientB4[2] = -3;
    Poly *pB4 = new Poly;
    pB4->degree = degB4;
    pB4->coeff = coefficientB4;

    // Test addPoly
    cout << "\nExpected result: 2" << endl;
    cout << "Actual result: ";
    outputPoly(addPoly(pA4, pB4), 'x');

    // Test multPolly
    cout << "Expected result: 1-4*x^2-12*x^3-9*x^4"<< endl;
    cout << "Actual result: ";
    outputPoly(multPoly(pA4, pB4), 'x');

    // Test deletePolly
    deletePoly(pA4);
    deletePoly(pB4);


    //Test addPoly, multPolly, and deletePoly for a = -2 + 3*x^2 and b = -2 - 2*x^1 + 2*x^3
    //create a Polly a = -2 + 3*x^2
    int degA5 = 2;
    int* coefficientA5;
    coefficientA5 = new int[degA5+1];
    coefficientA5[0] = -2;
    coefficientA5[1] = 0;
    coefficientA5[2] = 3;
    Poly *pA5 = new Poly;
    pA5->degree = degA5;
    pA5->coeff = coefficientA5;

    //create a Polly b = -2 - 2*x^1 + 2*x^3
    int degB5 = 3;
    int* coefficientB5;
    coefficientB5 = new int[degB5+1];
    coefficientB5[0] = -2;
    coefficientB5[1] = -2;
    coefficientB5[2] = 0;
    coefficientB5[3] = 2;
    Poly *pB5 = new Poly;
    pB5->degree = degB5;
    pB5->coeff = coefficientB5;

    // Test addPoly
    cout << "\nExpected result: -4-2*x^1 + 3*x^2 + 2*x^3" << endl;
    cout << "Actual result: ";
    outputPoly(addPoly(pA5, pB5), 'x');

    // Test multPolly
    cout << "Expected result: 4 + 4*x^1-6*x^2-10*x^3 + 6*x^5"<< endl;
    cout << "Actual result: ";
    outputPoly(multPoly(pA5, pB5), 'x');

    // Test deletePolly
    deletePoly(pA5);
    deletePoly(pB5);

    //Test addPoly, multPolly, and deletePoly for a = -2 -2*z^2 and b = 2 -2*z^1
    //create a Polly a = -2 -2*x^2
    int degA6 = 2;
    int* coefficientA6;
    coefficientA6 = new int[degA6+1];
    coefficientA6[0] = -2;
    coefficientA6[1] = 0;
    coefficientA6[2] = -2;
    Poly *pA6 = new Poly;
    pA6->degree = degA6;
    pA6->coeff = coefficientA6;

    //create a Polly b = 2 -2*x^1
    int degB6 = 1;
    int* coefficientB6;
    coefficientB6 = new int[degB6+1];
    coefficientB6[0] = 2;
    coefficientB6[1] = -2;
    Poly *pB6 = new Poly;
    pB6->degree = degB6;
    pB6->coeff = coefficientB6;

    // Test addPoly
    cout << "\nExpected result: -2*z^1-2*z^2" << endl;
    cout << "Actual result: ";
    outputPoly(addPoly(pA6, pB6), 'z');

    // Test multPolly
    cout << "Expected result: -4 + 4*z^1-4*z^2 + 4*z^3"<< endl;
    cout << "Actual result: ";
    outputPoly(multPoly(pA6, pB6), 'z');

    // Test deletePolly
    deletePoly(pA6);
    deletePoly(pB6);

    return 0;
}
/*output
Expected result of (input degree: 3, Input coefficients: 2 -7 0 4): 2-7*x^1 + 4*x^3
Input the degree: 3
Input a coefficient [0]: 2
Input a coefficient [1]: -7
Input a coefficient [2]: 0
Input a coefficient [3]: 4
Actual result: 2-7*x^1 + 4*x^3

Expected result: 2 + 3*x^1 + 4*x^2
Actual result: 2 + 3*x^1 + 4*x^2
Expected result: 1 + 3*x^1 + 6*x^2 + 5*x^3 + 3*x^4
Actual result: 1 + 3*x^1 + 6*x^2 + 5*x^3 + 3*x^4

Expected result: 2 + 2*x^1 + 2*x^2 + 1*x^3 + 1*x^4
Actual result: 2 + 2*x^1 + 2*x^2 + 1*x^3 + 1*x^4
Expected result: 1 + 2*x^1 + 3*x^2 + 3*x^3 + 3*x^4 + 2*x^5 + 1*x^6
Actual result: 1 + 2*x^1 + 3*x^2 + 3*x^3 + 3*x^4 + 2*x^5 + 1*x^6

Expected result: 1 + 1*x^1 + 1*x^2
Actual result: 1 + 1*x^1 + 1*x^2
Expected result: 0
Actual result:

Expected result: 2
Actual result: 2
Expected result: 1-4*x^2-12*x^3-9*x^4
Actual result: 1-4*x^2-12*x^3-9*x^4

Expected result: -4-2*x^1 + 3*x^2 + 2*x^3
Actual result: -4-2*x^1 + 3*x^2 + 2*x^3
Expected result: 4 + 4*x^1-6*x^2-10*x^3 + 6*x^5
Actual result: 4 + 4*x^1-6*x^2-10*x^3 + 6*x^5

Expected result: -2*z^1-2*z^2
Actual result: -2*z^1-2*z^2
Expected result: -4 + 4*z^1-4*z^2 + 4*z^3
Actual result: -4 + 4*z^1-4*z^2 + 4*z^3
*/
