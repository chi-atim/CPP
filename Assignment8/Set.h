/**
** CPSC 1160 - Section 003 - Assignment 8
** Program Name: Set
** Purpose: Implement an Abstract Data Type “set” and see the running time complexity of an ADT
** Author: Chiemi Mita
** Student ID: 100320919
** Date: August 4, 2019
** Limitation: No known limitations
*/
#include <iostream>
#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

using namespace std;

class Set {
    public:
        Set() { list = nullptr; } // Constructs the empty Set
        bool isEmpty() const;
        int size() const;
        bool member(int x) const;
        void insert(int x);
        void remove(int x);

        // Overloading operators
        friend const Set operator +(const Set& a, const Set& b);
        friend const Set operator *(const Set& a, const Set& b);
        friend ostream& operator<< (ostream& out, const Set& a);

        // Overloading operator < (for Bonus Marks)
        friend bool operator <(const Set& p, const Set& q);

        // Copy constructor
        Set(const Set& a);
        // Overloading assignment operator
        Set& operator=(const Set& a);
        // Destructor
        ~Set();

    private:
        struct Node{
            int value;
            Node* next;
        };

        Node* list;

        static int car(Node* p); // to access value
        static Node* cdr(Node* p); // to access next
        static Node* cons(int x, Node* p); //to construct a Node
};

#endif // SET_H_INCLUDED
