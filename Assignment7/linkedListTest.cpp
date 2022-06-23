/**
** Program Name: LinkedList
** Purpose: Implement a structure for representing a linked list of integers and functions to illustrate its various features
** Author: Chiemi Mita
** Limitation: No known limitations
*/

#include <iostream>
#include "linkedList.h"

using namespace std;

int main(){

    Node* p1 = cons(33, cons(22, cons(11, nullptr)));
    Node *p2 = nullptr;
    Node* p3 = cons(99, cons(99, cons(88, cons(77, cons(77, nullptr)))));
    Node *p4 = nullptr;
    Node *p5 = nullptr;

    //Test length function
    cout << "***** Test length function *****" << endl;
    cout << "Expected result of length(p1): 3" << endl;
    cout << "Actual result: " << length(p1) << endl;
    cout << "Expected result of length(p2): 0" << endl;
    cout << "Actual result: " << length(p2) << endl;
    cout << "Expected result of length(p3): 5" << endl;
    cout << "Actual result: " << length(p3) << endl;

    // Test printList function
    cout << "\n***** Test printList function *****" << endl;
    cout << "Expected result of printList(p1): [ 33 22 11 ]" << endl;
    cout << "Actual result: ";
    printList(p1);
    cout << "Expected result of printList(p2): [ ]" << endl;
    cout << "Actual result: ";
    printList(p2) ;
    cout << "Expected result of printList(p3): [ 99 99 88 77 77 ]" << endl;
    cout << "Actual result: ";
    printList(p3) ;

    // Test append function
    cout << "\n***** Test append function *****" << endl;
    cout << "Before append: ";
    printList(p1);
    cout << "Expected result of after append(0, p1): [33 22 11 0 ]" << endl;
    cout << "Actual result: ";
    p1 = append(0, p1);
    printList(p1);
    cout << "Before append: ";
    printList(p2);
    cout << "Expected result of after append(100, p2): [ 100 ]" << endl;
    cout << "Actual result: ";
    p2 = append(100, p2);
    printList(p2);

    // Test reverse function
    cout << "\n***** Test reverse function *****" << endl;
    cout << "Before reverse(p1): ";
    printList(p1);
    cout << "Expected result of after reverse(p1): [ 0 11 22 33 ]" << endl;
    cout << "Actual result: ";
    p1 = reverse(p1);
    printList(p1);
    cout << "Before reverse(p4): ";
    printList(p4);
    cout << "Expected result of after reverse(p4): [ ]" << endl;
    cout << "Actual result: ";
    p4 = reverse(p4);
    printList(p4);

    // Test searchInOrder function
    cout << "\n***** Test searchInOrder function *****" << endl;
    cout << "Expected result of searchInOrder(11, p1): true" << endl;
    cout << "Actual result: ";
    if (searchInOrder(11, p1))
        cout << "true" << endl;
    else
        cout <<"false" << endl;
    cout << "Expected result of searchInOrder(12, p1): false" << endl;
    cout << "Actual result: ";
    if (searchInOrder(12, p1))
        cout << "true" << endl;
    else
        cout <<"false" << endl;
    cout << "Expected result of searchInOrder(0, p2): false" << endl;
    cout << "Actual result: ";
    if (searchInOrder(0, p2))
        cout << "true" << endl;
    else
        cout <<"false" << endl;


    // Test hasDuplicates function
    cout << "\n***** Test hasDuplicates function *****" << endl;
    cout << "Expected result of hasDuplicates(p1): false" << endl;
    cout << "Actual result: ";
    if (hasDuplicates(p1))
        cout << "true" << endl;
    else
        cout <<"false" << endl;
    cout << "Expected result of hasDuplicates(p2): false" << endl;
    cout << "Actual result: ";
    if (hasDuplicates(p2))
        cout << "true" << endl;
    else
        cout <<"false" << endl;
    cout << "Expected result of hasDuplicates(p3): true" << endl;
    cout << "Actual result: ";
    if (hasDuplicates(p3))
        cout << "true" << endl;
    else
        cout <<"false" << endl;

    // Test isLonger function
    cout << "\n***** Test isLonger function *****" << endl;
    cout << "Expected result of isLonger(p1, p2): true (p1 is longer than p2)" << endl;
    cout << "Actual result: ";
    if (isLonger(p1, p2))
        cout << "true" << endl;
    else
        cout <<"false" << endl;
    cout << "Expected result of isLonger(p1, p3): false (p1 is not longer than p3)" << endl;
    cout << "Actual result: ";
    if (isLonger(p1, p3))
        cout << "true" << endl;
    else
        cout <<"false" << endl;
    cout << "Expected result of isLonger(p4, p5): false (p4 is same length as p5)" << endl;
    cout << "Actual result: ";
    if (isLonger(p4, p5))
        cout << "true" << endl;
    else
        cout <<"false" << endl;

    // Test ithNode function
    cout << "\n***** Test ithNode function *****" << endl;
    cout << "Expected result of ithNode(p1, 2): [ 22 33 ]" << endl;
    cout << "Actual result: ";
    Node* ithP1_a = ithNode(p1, 2);
    printList(ithP1_a);
    cout << "Expected result of ithNode(p1, 8): [ ] (i is larger than list length)" << endl;
    cout << "Actual result: ";
    Node* ithP1_b = ithNode(p1, 8);
    printList(ithP1_b);
    cout << "Expected result of ithNode(p4, 0): [ ] (empty linked list)" << endl;
    cout << "Actual result: ";
    Node* ithP4 = ithNode(p4, 0);
    printList(ithP4);


    // Test mergeTwoOrderedLists function
    cout << "\n***** Test mergeTwoOrderedLists function *****" << endl;
    Node* m1 = cons(0, cons(2, cons(4, cons(6, cons(8, cons(15, nullptr))))));
    Node* m2 = cons(3, cons(5, cons(7, cons(7, nullptr))));
    cout << "Expected result of mergeTwoOrderedLists(m1, m2): [ 0 2 3 4 5 6 7 7 8 15 ]" << endl;
    cout << "Actual result: ";
    Node* m12 = mergeTwoOrderedLists(m1, m2);
    printList(m12);

    Node* m3 = nullptr;
    Node* m4 = cons(7, nullptr);
    cout << "Expected result of mergeTwoOrderedLists(m3, m4): [ 7 ]" << endl;
    cout << "Actual result: ";
    Node* m34 = mergeTwoOrderedLists(m3, m4);
    printList(m34);

    Node* m5 = cons(2, nullptr);
    Node* m6 = nullptr;
    cout << "Expected result of mergeTwoOrderedLists(m5, m6): [ 2 ]" << endl;
    cout << "Actual result: ";
    Node* m56 = mergeTwoOrderedLists(m5, m6);
    printList(m56);

    Node* m7 = cons(0, cons(9, nullptr));
    Node* m8 = cons(2, cons(3, cons(6, cons(8, nullptr))));
    cout << "Expected result of mergeTwoOrderedLists(m7, m8): [ 0 2 3 6 8 9 ]" << endl;
    cout << "Actual result: ";
    Node* m78 = mergeTwoOrderedLists(m7, m8);
    printList(m78);

    // Test array2List function
    cout << "\n***** Test array2List function *****" << endl;
    int A[5] = {1, 2, 6, 7, 9};
    Node* a = array2List(A, 5);
    cout << "Expected result of array2List(A, 5): [ 1 2 6 7 9 ]" << endl;
    cout << "Actual result: ";
    printList(a);

    int B[4] = {8, 8, 9, 0};
    Node* b = array2List(B, 4);
    cout << "Expected result of array2List(B, 4): [ 8 8 9 0 ]" << endl;
    cout << "Actual result: ";
    printList(b);

    int C[0];
    Node* c = array2List(C, 0);
    cout << "Expected result of array2List(C, 0): [ ]" << endl;
    cout << "Actual result: ";
    printList(c);

    // Test readList function
    cout << "\n***** Test readList function *****" << endl;
    cout << "Enter integers and exit with a non digit: 2 0 1 5 w" << endl;
    Node* p6 = readList();
    cout << "Actual result: ";
    printList(p6);
    cout << "Enter a non digit to create an empty list:" << endl;
    Node* p7 = readList();
    cout << "Actual result: ";
    printList(p7);

    // Test deleteList function
    cout << "\n***** Test deleteList function *****" << endl;
    cout << "Before deleteList: " << endl;
    cout << "p1 = ";
    printList(p1);
    cout << "p2 = ";
    printList(p2);
    cout << "p3 = ";
    printList(p3);
    cout << "p4 = ";
    printList(p4);
    cout << "p5 = ";
    printList(p5);
    cout << "p6 = ";
    printList(p6);
    cout << "p7 = ";
    printList(p7);

    cout << "Expected result of after deleteList for p1 - p7: [ ]" << endl;
    cout << "Actual result:" << endl;
    p1 = deleteList(p1);
    p2 = deleteList(p2);
    p3 = deleteList(p3);
    p4 = deleteList(p4);
    p5 = deleteList(p5);
    p6 = deleteList(p6);
    p7 = deleteList(p7);
    cout << "p1 = ";
    printList(p1);
    cout << "p2 = ";
    printList(p2);
    cout << "p3 = ";
    printList(p3);
    cout << "p4 = ";
    printList(p4);
    cout << "p5 = ";
    printList(p5);
    cout << "p6 = ";
    printList(p6);
    cout << "p7 = ";
    printList(p7);

    return 0;
}
/*output
***** Test length function *****
Expected result of length(p1): 3
Actual result: 3
Expected result of length(p2): 0
Actual result: 0
Expected result of length(p3): 5
Actual result: 5

***** Test printList function *****
Expected result of printList(p1): [ 33 22 11 ]
Actual result: [ 33 22 11 ]
Expected result of printList(p2): [ ]
Actual result: [ ]
Expected result of printList(p3): [ 99 99 88 77 77 ]
Actual result: [ 99 99 88 77 77 ]

***** Test append function *****
Before append: [ 33 22 11 ]
Expected result of after append(0, p1): [33 22 11 0 ]
Actual result: [ 33 22 11 0 ]
Before append: [ ]
Expected result of after append(100, p2): [ 100 ]
Actual result: [ 100 ]

***** Test reverse function *****
Before reverse(p1): [ 33 22 11 0 ]
Expected result of after reverse(p1): [ 0 11 22 33 ]
Actual result: [ 0 11 22 33 ]
Before reverse(p4): [ ]
Expected result of after reverse(p4): [ ]
Actual result: [ ]

***** Test searchInOrder function *****
Expected result of searchInOrder(11, p1): true
Actual result: true
Expected result of searchInOrder(12, p1): false
Actual result: false
Expected result of searchInOrder(0, p2): false
Actual result: false

***** Test hasDuplicates function *****
Expected result of hasDuplicates(p1): false
Actual result: false
Expected result of hasDuplicates(p2): false
Actual result: false
Expected result of hasDuplicates(p3): true
Actual result: true

***** Test isLonger function *****
Expected result of isLonger(p1, p2): true (p1 is longer than p2)
Actual result: true
Expected result of isLonger(p1, p3): false (p1 is not longer than p3)
Actual result: false
Expected result of isLonger(p4, p5): false (p4 is same length as p5)
Actual result: false

***** Test ithNode function *****
Expected result of ithNode(p1, 2): [ 22 33 ]
Actual result: [ 22 33 ]
Expected result of ithNode(p1, 8): [ ] (i is larger than list length)
Actual result: [ ]
Expected result of ithNode(p4, 0): [ ] (empty linked list)
Actual result: [ ]

***** Test mergeTwoOrderedLists function *****
Expected result of mergeTwoOrderedLists(m1, m2): [ 0 2 3 4 5 6 7 7 8 15 ]
Actual result: [ 0 2 3 4 5 6 7 7 8 15 ]
Expected result of mergeTwoOrderedLists(m3, m4): [ 7 ]
Actual result: [ 7 ]
Expected result of mergeTwoOrderedLists(m5, m6): [ 2 ]
Actual result: [ 2 ]
Expected result of mergeTwoOrderedLists(m7, m8): [ 0 2 3 6 8 9 ]
Actual result: [ 0 2 3 6 8 9 ]

***** Test array2List function *****
Expected result of array2List(A, 5): [ 1 2 6 7 9 ]
Actual result: [ 1 2 6 7 9 ]
Expected result of array2List(B, 4): [ 8 8 9 0 ]
Actual result: [ 8 8 9 0 ]
Expected result of array2List(C, 0): [ ]
Actual result: [ ]

***** Test readList function *****
Enter integers and exit with a non digit: 2 0 1 5 w
2 0 1 5 w
Actual result: [ 2 0 1 5 ]
Enter a non digit to create an empty list:
w
Actual result: [ ]

***** Test deleteList function *****
Before deleteList:
p1 = [ 0 11 22 33 ]
p2 = [ 100 ]
p3 = [ 99 99 88 77 77 ]
p4 = [ ]
p5 = [ ]
p6 = [ 2 0 1 5 ]
p7 = [ ]
Expected result of after deleteList for p1 - p7: [ ]
Actual result:
p1 = [ ]
p2 = [ ]
p3 = [ ]
p4 = [ ]
p5 = [ ]
p6 = [ ]
p7 = [ ]
*/
