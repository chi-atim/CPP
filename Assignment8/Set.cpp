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
#include <cassert>
#include "Set.h"

using namespace std;

//Provided function for Assignment 7
int Set::car(Node* p) {
    assert(p != nullptr);
    return(p->value);
}
//Provided function for Assignment 7
Set::Node* Set::cdr(Node* p) {
    assert(p != nullptr);
    return(p->next);
}
//Provided function for Assignment 7
Set::Node* Set::cons(int x, Node* p) {
    return new Node{x, p};
}

/** Check if Set is empty or not
* @return true if the Set is empty, false otherwise
* pre and post-condition: none
* cost: O(1)
*/
bool Set::isEmpty() const{
    return (list == nullptr);
}
/** Obtain the number of elements in the Set
* @return number of elements in the Set
* pre and post-condition: none
* cost: O(m)
*/
int Set::size() const{
    int numOfElements = 0;
    Node* temp=list;
    // Traverse and count the number of elements in the set
	while(temp != nullptr){
		numOfElements++;
		temp = cdr(temp);
	}
	return numOfElements;
}
/** Check if the given value x is in the Set or not
* @params int value x
* @return returns true if x is in the Set, false otherwise
* pre and post-condition: none
* cost: O(m)
*/
bool Set::member(int x) const{
    // Empty Set
    if(list == nullptr)
        return false;

    Node* temp = list;

    // Traverse through the Set and find out if the value x is in the Set
    while (temp != nullptr){
        if (car(temp) == x)
            return true;
        temp = cdr(temp);
    }
    return false;
}
/** Insert the given value into the Set in ascending order
* @params int value x
* pre-condition: Set must be sorted in ascending order without duplicates
* post-condition: a Set with a new value inserted in ascending order
* cost: O(m)
*/
void Set::insert(int x){
    // Empty Set
    if(list == nullptr)
        list = cons(x, nullptr);
    // Set is not empty and given value is not in the set
    else if(!member(x)){

        Node* head = list;
        Node* curr = cdr(list);

        // x is smaller than the value
        if(x < car(list))
            list = cons(x, list);

        // x is larger than value
        else{
            // Find the position to insert the value x
            while(curr!=nullptr && x > car(curr)){
                head = curr;
                curr = curr->next;
            }
            // Insert the value x
            head->next = cons(x, curr);
        }
    }
}
/** Delete the given value x from the Set
* @params int value x
* pre-condition: Set must be sorted in ascending order without duplicates
* post-condition: a Set with a given value removed
* cost: O(m)
*/
void Set::remove(int x){
    // Empty Set or x is not in the set
    if(list == nullptr || !member(x)) return;

    // x is the first elements in the set
    if(car(list)==x){
        Node* dis = list;
        list = cdr(list);
        delete dis;
    }
    else {
        Node* curr = list;
        Node* prev = nullptr;
        // Find the position of x as traverse through the set
        while(curr != nullptr && car(curr) != x){
            prev = curr;
            curr = cdr(curr);
        }
        prev->next = cdr(curr);
        delete curr; // Delete the value x
    }
}
/** Combines two sets
* @params Two sets
* @return a new Set which is the combination of Two Sets passed
* pre-condition: Both sets must be sorted in ascending order without duplicates
* post-condition: Two Sets passed must not be destroyed and remain the same
* cost: O(m+n)
*/
const Set operator+(const Set& a, const Set& b){
    // Create a new empty Set c
    Set c;
    Set::Node* temp = a.list;
    // Copy all the elements of Set a into the empty Set c
    while (temp != nullptr){
        c.insert(Set::car(temp));
        temp = Set::cdr(temp);
    }
    temp = b.list;
    // Copy the elements of Set b that are not already into Set c
    while (temp != nullptr){
        c.insert(Set::car(temp));
        temp = Set::cdr(temp);
    }
    return c;
}
/** Populate the set with items that are common to both Sets that are passed
* @params Two sets
* @return a new Set which contains the items that are common to both Sets
* pre-condition: Both sets must be sorted in ascending order without duplicates
* post-condition: Two Sets passed must not be destroyed and remain the same
* cost: O(m)
*/
const Set operator*(const Set& a, const Set& b){
    Set c;
    Set::Node *temp = a.list;
    // Traverse through Set a
    while(temp != nullptr){
        // Copy all the elements of Set a that are in Set b into the Set c
        if (b.member(Set::car(temp)))
            c.insert(Set::car(temp));
        temp = Set::cdr(temp);
    }
    return c;
}
/** Overload the output operator and print out all the elements of the Set
* @params output stream and Set
* @return output stream
* post-condition: { each elements in the Set }
* cost: O(m)
*/
ostream& operator<< (ostream& out, const Set& a){
    out << "{ ";
    Set::Node* temp = a.list;
    // Print all the elements in the Set
    while (temp != nullptr){
        cout << Set::car(temp) << " ";
        temp = Set::cdr(temp);
    }
    out << "}";
    return out;
}
/** Copy constructor
* @params a Set
* pre and post-condition: none
* cost: O(m)
*/
Set::Set(const Set& a){
    // Copy empty Set
    if(a.list == nullptr)
        list = nullptr;

    // Copy non-empty Set
    else{
        list = nullptr;
        Node* p = a.list;
        while (p != nullptr){
            insert(car(p));
            p = p->next;
        }
    }
}
/** Overloading assignment operator
* @params a Set
* pre and post-condition: none
* cost: O(m)
*/
Set& Set::operator=(const Set& a){
    if(this == &a)
        return *this;
    delete list;
    list = nullptr;
    Node* p = a.list;

    while (p != nullptr){
        insert(car(p));
        p = cdr(p);
    }
    return *this;
}
/** Destructor
* pre and post-condition: none
* cost: O(m)
*/
Set::~Set(){
    Node* p = list;
    // Delete each Node in the Set
    while(p != nullptr){
        list = cdr(list);
        delete p;
        p = list;
    }
}
/** Check if Set p is proper sublet of q or not
* @params Two sets p and q
* @return true is Set p is proper sublet of q, false otherwise
* post-condition: Both sets must be sorted in ascending order without duplicates
* cost: O(m+n)
*/
bool operator<(const Set& p, const Set& q){
    // p is larger or equal to than q
    if(p.size() >= q.size())
        return false;
    Set::Node* temp = p.list;
    while (temp != nullptr){
        // Check if each elements in p is in q
        if(!q.member(Set::car(temp)))
            return false;
        temp = Set::cdr(temp);
    }
    return true;
}
