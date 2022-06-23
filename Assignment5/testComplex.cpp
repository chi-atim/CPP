/**
** CPSC 1160 - Section 003 - Assignment 5
** Program Name: Complex
** Purpose: implement a class for representing complex numbers. Implements and overloads operators for Complex class.
** Author: Chiemi Mita
** Student ID: 100320919
** Date: July 1, 2019
** Limitation: No known limitations
*/

#include <iostream>
#include "Complex.h"

using namespace std;

int main(){

    // Test Constructors
    Complex c1(1.2, 3.4);
    cout << "Expected result: (1.2+3.4i);" << endl;
    cout << "Actual result: " << c1 << endl;
    Complex c2(5.5);
    cout << "\nExpected result: (5.5+0i) " << endl;
    cout << "Actual result: " << c2 << endl;
    Complex c3;
    cout << "\nExpected result: (0+0i) " << endl;
    cout << "Actual result: " << c3 << endl;
    Complex c4(-6, -7.8);
    cout << "\nExpected result: (-6-7.8i) " << endl;
    cout << "Actual result: " << c4 << endl;

    // Test getReal() function
    cout << "\nExpected result: 1.2 " << endl;
    cout << "Actual result: " << c1.getReal() << endl;

    // Test getReal() function
    cout << "\nExpected result: -7.8 " << endl;
    cout << "Actual result: " << c4.getImag() << endl;

    // Test abs() function
    cout << "\nExpected result of absolute value of (1.2+3.4i) = 3.60555" << endl;
    cout << "Actual result: " << abs(c1) << endl;
    cout << "Expected result of absolute value of (0+0i) = 0" << endl;
    cout << "Actual result: " << abs(c3) << endl;
    cout << "Expected result of absolute value of (-6-7.8i) = 9.84073" << endl;
    cout << "Actual result: " << abs(c4) << endl;

    // Test addition
    cout << "\nExpected result of (1.2+3.4i) + (5.5+0i) = (6.7+3.4i)" << endl;
    cout << "Actual result: " << c1 + c2 << endl;
    cout << "Expected result of (0+0i) + (-6-7.8i) = (-6-7.8i)" << endl;
    cout << "Actual result: " << (c3 + c4) << endl;

    // Test subtraction
    cout << "\nExpected result of (1.2+3.4i) - (5.5+0i) = (-4.3+3.4i)" << endl;
    cout << "Actual result: " << (c1 - c2) << endl;
    cout << "Expected result of (0+0i) - (-6-7.8i) = (6+7.8i)" << endl;
    cout << "Actual result: " << (c3 - c4) << endl;

    // Test multiplication
    cout << "\nExpected result of (1.2+3.4i) * (5.5+0i) = (6.6+18.7i)" << endl;
    cout << "Actual result: " << (c1 * c2) << endl;
    cout << "Expected result of (0+0i) * (-6-7.8i) = (0+0i)" << endl;
    cout << "Actual result: " << (c3 * c4) << endl;
    cout << "Expected result of (1.2+3.4i) * (-6-7.8i) = (19.32-11.04i)" << endl;
    cout << "Actual result: " << (c1 * c4) << endl;

    // Test division: Complex / Complex
    cout << "\nExpected result of (1.2+3.4i) / (-6-7.8i) = (-0.348203-0.307311i)" << endl;
    cout << "Actual result: " << (c1 / c4) << endl;
    cout << "Expected result of (0+0i) / (-6-7.8i) = (0+0i)" << endl;
    cout << "Actual result: " << (c3 / c4) << endl;

    // Test division: Complex / real number
    cout << "\nExpected result of (1.2+3.4i) / 2.5 = (0.6+1.7i)" << endl;
    cout << "Actual result: " << (c1 / 2.5) << endl;
    cout << "Expected result of (0+0i) / 3 = (0+0i)" << endl;
    cout << "Actual result: " << (c3 / 3) << endl;
    cout << "Expected result of (-6-7.8i) / -10= (0.6+0.78i)" << endl;
    cout << "Actual result: " << (c4 / -10) << endl;

    // Test "=="
    cout << "\nExpected result of (1.2+3.4i) == (5.5+0i) = 0" << endl;
    cout << "Actual result: " << (c1 == c2) << endl;
    cout << "Expected result of (5.5+0i) == (0+0i) = 0" << endl;
    cout << "Actual result: " << (c2 == c3) << endl;
    Complex c4copy1 = c4;
    Complex c4copy2(-6, -7.8);
    cout << "Expected result of (-6-7.8i) == (-6-7.8i) = 1" << endl;
    cout << "Actual result: " << (c4 == c4copy1)  << endl;
    cout << "Expected result of (-6-7.8i) == (-6-7.8i) = 1" << endl;
    cout << "Actual result: " << (c4 == c4copy2)  << endl;

    // Test "!="
    cout << "\nExpected result of (1.2+3.4i) != (5.5+0i) = 1" << endl;
    cout << "Actual result: " << (c1 != c2) << endl;
    cout << "Expected result of (5.5+0i) != (0+0i) = 1" << endl;
    cout << "Actual result: " << (c2 != c3) << endl;
    cout << "Expected result of (-6-7.8i) != (-6-7.8i) = 0" << endl;
    cout << "Actual result: " << (c4 != c4copy1)  << endl;
    cout << "Expected result of (-6-7.8i) != (-6-7.8i) = 0" << endl;
    cout << "Actual result: " << (c4 != c4copy2)  << endl;

    // Test ">>"
    Complex c5 (9,9);
    cout << "\nExpected result of: if 2 and -0.5 entered: (2-0.5i)" << endl;
    cout << "Enter real part and imaginary part: " << endl;
    cin >> c5;
    cout << "Actual result: " << c5 << endl;

    Complex c6(-9.9, -2), c7;

    // Test Bonus "+="
    cout << "\nExpected result of (1.2+3.4i) += (5.5+0i) = (6.7+3.4i)" << endl;
    c1 += c2;
    cout << "Actual result: " << c1 << endl;
    cout << "Expected result of (0+0i) += (-6-7.8i) = (-6-7.8i)" << endl;
    c3 += c4;
    cout << "Actual result: " << c3 << endl;
    cout << "Expected result of (-6-7.8i) += (-9.9, -2) = (-15.9-9.8i)" << endl;
    c4 += c6;
    cout << "Actual result: " << c4 << endl;

    // Test Bonus "-="
    cout << "\nExpected result of (6.7+3.4i) -= (5.5+0i) = (1.2+3.4i)" << endl;
    c1 -= c2;
    cout << "Actual result: " << c1 << endl;
    cout << "Expected result of (-6-7.8i) -= (-15.9-9.8i) = (9.9+2i)" << endl;
    c3 -= c4;
    cout << "Actual result: " << c3 << endl;
    cout << "Expected result of (0+0i) -= (-15.9-9.8i) = (15.9+9.8i)" << endl;
    c7 -= c4;
    cout << "Actual result: " << c7 << endl;

    // Test Bonus unary +
    Complex c8(1, 2.3), c9(-4.5, 6), c10(-7.8, -9.9), c11;

    cout << "\nExpected result of +(1+2.3i) = (1+2.3i)" << endl;
    Complex c12 = +c8;
    cout << "Actual result: " << c12 << endl;
    cout << "Expected result of +(-4.5+6i) = (4.5+6i)" << endl;
    c12 = +c9;
    cout << "Actual result: " << c12<< endl;
    cout << "Expected result of +(-7.8-9.9i) = (7.8+9.9i)" << endl;
    c12 = +c10;
    cout << "Actual result: " << c12<< endl;
    cout << "Expected result of +(0+0i) = (0+0i)" << endl;
    c12 = +c11;
    cout << "Actual result: " << c12<< endl;

    // Test Bonus unary -
    cout << "\nExpected result of -(1+2.3i) = (-1-2.3i)" << endl;
    Complex c13 = -c8;
    cout << "Actual result: " << c13 << endl;
    cout << "Expected result of -(+4.5-6i) = (-4.5-6i)" << endl;
    c13 = -c9;
    cout << "Actual result: " << c13<< endl;
    cout << "Expected result of -(-7.8-9.9i) = (-7.8-9.9i)" << endl;
    c13 = -c10;
    cout << "Actual result: " << c13<< endl;
    cout << "Expected result of -(0+0i) = (0+0i)" << endl;
    c13 = -c11;
    cout << "Actual result: " << c13<< endl;

    // Test Bonus ++Prefix increment
    cout << "\nExpected result: (2+3.3i), (2+3.3i)" << endl;
    Complex c14 = ++c8;
    cout << "Actual result: " << c8 << ", " << c14 << endl;
    cout << "Expected result: (-6.8-8.9i), (-6.8-8.9i)" << endl;
    Complex c15 = ++c10;
    cout << "Actual result:" << c10 << ", " << c15 << endl;

    // Test Bonus Postfix++ increment
    cout << "\nExpected result: (2+3.3i), (3+4.3i)" << endl;
    Complex c16 = c8++;
    cout << "Actual result: " << c8 << ", " << c16 << endl;
    cout << "Expected result: (-6.8-8.9i), (-5.8-7.9i)" << endl;
    Complex c17 = c10++;
    cout << "Actual result: " << c10 << ", " << c17 << endl;

    // Test Bonus --Prefix increment
    cout << "\nExpected result: (1+2.3i), (1+2.3i)" << endl;
    Complex c18 = --c8;
    cout << "Actual result: " << c8 << ", " << c18 << endl;
    cout << "Expected result: (-7.8-9.9i), (-7.8-9.9i)" << endl;
    Complex c19 = --c10;
    cout << "Actual result:" << c10 << ", " << c19 << endl;

    // Test Bonus Postfix increment
    cout << "\nExpected result: (1+2.3i), (0+1.3i)" << endl;
    Complex c20 = c8--;
    cout << "Actual result: " << c8 << ", " << c20 << endl;
    cout << "Expected result: (-7.8-9.9i), (-8.8-10.9i)" << endl;
    Complex c21 = c10--;
    cout << "Actual result: " << c10 << ", " << c21 << endl;

    return 0;
}
/*Output
Expected result: (1.2+3.4i);
Actual result: (1.2+3.4i)

Expected result: (5.5+0i)
Actual result: (5.5+0i)

Expected result: (0+0i)
Actual result: (0+0i)

Expected result: (-6-7.8i)
Actual result: (-6-7.8i)

Expected result: 1.2
Actual result: 1.2

Expected result: -7.8
Actual result: -7.8

Expected result of absolute value of (1.2+3.4i) = 3.60555
Actual result: 3.60555
Expected result of absolute value of (0+0i) = 0
Actual result: 0
Expected result of absolute value of (-6-7.8i) = 9.84073
Actual result: 9.84073

Expected result of (1.2+3.4i) + (5.5+0i) = (6.7+3.4i)
Actual result: (6.7+3.4i)
Expected result of (0+0i) + (-6-7.8i) = (-6-7.8i)
Actual result: (-6-7.8i)

Expected result of (1.2+3.4i) - (5.5+0i) = (-4.3+3.4i)
Actual result: (-4.3+3.4i)
Expected result of (0+0i) - (-6-7.8i) = (6+7.8i)
Actual result: (6+7.8i)

Expected result of (1.2+3.4i) * (5.5+0i) = (6.6+18.7i)
Actual result: (6.6+18.7i)
Expected result of (0+0i) * (-6-7.8i) = (0+0i)
Actual result: (0+0i)
Expected result of (1.2+3.4i) * (-6-7.8i) = (19.32-11.04i)
Actual result: (19.32-11.04i)

Expected result of (1.2+3.4i) / (-6-7.8i) = (-0.348203-0.307311i)
Actual result: (-0.348203-0.307311i)
Expected result of (0+0i) / (-6-7.8i) = (0+0i)
Actual result: (-0+0i)

Expected result of (1.2+3.4i) / 2.5 = (0.6+1.7i)
Actual result: (0.6+1.7i)
Expected result of (0+0i) / 3 = (0+0i)
Actual result: (0+0i)
Expected result of (-6-7.8i) / -10= (0.6+0.78i)
Actual result: (0.6+0.78i)

Expected result of (1.2+3.4i) == (5.5+0i) = 0
Actual result: 0
Expected result of (5.5+0i) == (0+0i) = 0
Actual result: 0
Expected result of (-6-7.8i) == (-6-7.8i) = 1
Actual result: 1
Expected result of (-6-7.8i) == (-6-7.8i) = 1
Actual result: 1

Expected result of (1.2+3.4i) != (5.5+0i) = 1
Actual result: 1
Expected result of (5.5+0i) != (0+0i) = 1
Actual result: 1
Expected result of (-6-7.8i) != (-6-7.8i) = 0
Actual result: 0
Expected result of (-6-7.8i) != (-6-7.8i) = 0
Actual result: 0

Expected result of: if 2 and -0.5 entered: (2-0.5i)
Enter real part and imaginary part:
2
-0.5
Actual result: (2-0.5i)

Expected result of (1.2+3.4i) += (5.5+0i) = (6.7+3.4i)
Actual result: (6.7+3.4i)
Expected result of (0+0i) += (-6-7.8i) = (-6-7.8i)
Actual result: (-6-7.8i)
Expected result of (-6-7.8i) += (-9.9, -2) = (-15.9-9.8i)
Actual result: (-15.9-9.8i)

Expected result of (6.7+3.4i) -= (5.5+0i) = (1.2+3.4i)
Actual result: (1.2+3.4i)
Expected result of (-6-7.8i) -= (-15.9-9.8i) = (9.9+2i)
Actual result: (9.9+2i)
Expected result of (0+0i) -= (-15.9-9.8i) = (15.9+9.8i)
Actual result: (15.9+9.8i)

Expected result of +(1+2.3i) = (1+2.3i)
Actual result: (1+2.3i)
Expected result of +(-4.5+6i) = (4.5+6i)
Actual result: (4.5+6i)
Expected result of +(-7.8-9.9i) = (7.8+9.9i)
Actual result: (7.8+9.9i)
Expected result of +(0+0i) = (0+0i)
Actual result: (0+0i)

Expected result of -(1+2.3i) = (-1-2.3i)
Actual result: (-1-2.3i)
Expected result of -(+4.5-6i) = (-4.5-6i)
Actual result: (-4.5-6i)
Expected result of -(-7.8-9.9i) = (-7.8-9.9i)
Actual result: (-7.8-9.9i)
Expected result of -(0+0i) = (0+0i)
Actual result: (0+0i)

Expected result: (2+3.3i), (2+3.3i)
Actual result: (2+3.3i), (2+3.3i)
Expected result: (-6.8-8.9i), (-6.8-8.9i)
Actual result:(-6.8-8.9i), (-6.8-8.9i)

Expected result: (2+3.3i), (3+4.3i)
Actual result: (2+3.3i), (3+4.3i)
Expected result: (-6.8-8.9i), (-5.8-7.9i)
Actual result: (-6.8-8.9i), (-5.8-7.9i)

Expected result: (1+2.3i), (1+2.3i)
Actual result: (1+2.3i), (1+2.3i)
Expected result: (-7.8-9.9i), (-7.8-9.9i)
Actual result:(-7.8-9.9i), (-7.8-9.9i)

Expected result: (1+2.3i), (0+1.3i)
Actual result: (1+2.3i), (0+1.3i)
Expected result: (-7.8-9.9i), (-8.8-10.9i)
Actual result: (-7.8-9.9i), (-8.8-10.9i)
*/
