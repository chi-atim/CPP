/**
** CPSC 1160 - Section 003 - Assignment 7
** Program Name: LinkedList
** Purpose: Implement a structure for representing a linked list of integers and functions to illustrate its various features
** Author: Chiemi Mita
** Student ID: 100320919
** Date: July 19, 2019
** Limitation: No known limitations
*/

#include <iostream>
#include <cassert>
#include <limits>

#include "linkedList.h"

using namespace std;

int car(Node* p) {
    assert(p != nullptr);
    return(p->value);
}
Node* cdr(Node* p) {
    assert(p != nullptr);
    return(p->next);
}
void setcar(Node* p, int x) {
    assert(p != nullptr);
    p->value = x;
}
void setcdr(Node* p, Node* q) {
    assert(p != nullptr);
    p->next = q;
}
Node* cons(int x, Node* p) {
    return new Node{x, p};
}

/**Count the number of nodes in the linked list p
* @params a linked list p
* @return a total number of nodes in the linked list p
* pre-condition: the linked list must be initialized
* post-condition: none
*/
int length(Node* p){
    //Base case
    if(p==nullptr) return 0;
    //Recursive call
    return 1 + length(cdr(p));
}
/**Print a list in the order in which the elements are stored
* @params a linked list p
* @return none
* pre-condition: the linked list must be initialized
* post-condition: Result will be inside the bracket[] and printed on the screen
*/
void printList(Node* p){
    cout << "[ ";
    //Print each value
    while (p != nullptr) {
        cout << car(p) << " ";
        p = cdr(p);
    }
    cout << "]" << endl;
}
/**Searches a value x in the list pointed to by p
* @params a value x, and a linked list p
* @return true if x is in the list, false otherwise
* pre-condition: the linked list p is sorted in ascending order
* post-condition: none
*/
bool searchInOrder(int x, Node* p){
    //Base case
    //If x is larger than the current value, return false
    if(p == nullptr || car(p) > x) return false;
    // If x is in the list, return true
    if(car(p) == x) return true;
    //Recursive call
    return searchInOrder(x, cdr(p));
}
/**Determines if any elements of the linked list p appear more than once
* @params a linked list p
* @return true if a list p has duplicated nodes, false otherwise
* pre-condition: the linked list must be initialized
* post-condition: none
*/
bool hasDuplicates(Node* p){
    if(p == nullptr) return false;
    while (cdr(p) != nullptr){
        //return true when duplicated value is found
        if (member(car(p), cdr(p)))
            return true;
        //move pointer to the next node
        p = cdr(p);
    }
    return false;
}
/**A helper function for hasDuplicates function - Searches a value x in the list pointed to by p
* @params a value x, and a Node(linked list) pointed to by p
* @return true if x is in the list, false otherwise
* pre-condition: none
* post-condition: none
*/
bool member(int x, Node* p){
    if(p == nullptr) return false;
    while (p != nullptr){
        //return true when duplicated value is found
        if(car(p) == x) return true;
        //move pointer to the next node
        p = cdr(p);
    }
    return false;
}
/**Appends a new node with the value of x to the end of the list p
* @params a value x, and a linked list p
* @return a Node(linked list) with x appended to it
* pre-condition: the linked list must be initialized
* post-condition: a Node(linked list) p will have a new node attached
*/
Node* append(int x, Node* p){
    //return a linked list with one node with a given value
    if(p==nullptr) return cons(x, nullptr);
    Node* temp = p;
    //move temp pointer to the end of the linked list
    while(cdr(temp) != nullptr){
        temp = cdr(temp);
    }
    // Append the node to the end of the linked list
    setcdr(temp, cons(x, nullptr));
    return p;
}
/**Reverse a linked list
* @params a linked list p
* @return a reversed linked list pointed to by p
* pre-condition: the linked list must be initialized
* post-condition: the linked list will be reversed
*/
Node* reverse(Node* p){
    // Base case - Do nothing if 0 or 1 node
    if(p == nullptr) return nullptr;
    if (cdr(p) == nullptr) return p;
    Node* prev = nullptr;
    Node* curr = p;
    Node* next;
    while (curr != nullptr){
        next = cdr(curr);
        //reverse curr node's pointer to prev
        curr->next = prev;
        prev = curr;
        //move curr to next
        curr = next;
    }
    return prev;
}
/**Determines if the linked list p is longer than the linked list q
* @params linked list p and linked list q
* @return true if p is longer than q, false otherwise
* pre-condition: both linked lists must be initialized
* post-condition: none
*/
bool isLonger(Node* p, Node* q){
    //return false if both linked lists are empty
    if(p == nullptr && q == nullptr) return false;
    // Traverse both linked lists
    while (p != nullptr){
        // return true when pointer reaches the end of q first
        if(q == nullptr) return true;
        // move both pointers to the next node
        p = cdr(p);
        q = cdr(q);
    }
    return false;
}
/**Returns the ith node of the list starting with the 0th node.
* @params linked list p and integer i indicating the ith of node
* @return ith node of the list p
* pre-condition: i must be greater than or equal to zero (i >= 0)
* post-condition: pointer will be pointed to the ith node of the list p
*/
Node* ithNode(Node* p, int i){
    if(p == nullptr) return nullptr;
    for (int k=0; k<i; k++){
        // Return empty linked list if i is larger than the length of p
        if (cdr(p)== nullptr)
            return nullptr;
        p = cdr(p);
    }
    return p;
}
/**Takes two linked lists and returns a list that contains the elements of both lists
* @params two sorted linked list p and q
* @return a sorted list that contains the elements of both lists
* pre-condition: Both lists must be sorted
* post-condition: none
*/
Node* mergeTwoOrderedLists(Node* p, Node* q){
    //Base cases
    if(p == nullptr) return q;
    if(q == nullptr) return p;
    if(p == nullptr && q == nullptr) return nullptr;
    // a new linked list
    Node* result = nullptr;
    // Traverse both linked lists while both linked lists are not empty
    while(p != nullptr && q != nullptr){
        // Store the smaller node into result linked list
        if(car(p)<=car(q)){
            result = cons(car(p), result);
            p = cdr(p);
        }
        else{
            result = cons(car(q), result);
            q = cdr(q);
        }
    }
    // Store the remaining values of p if not empty
    while (p!= nullptr){
        result = cons(car(p), result);
        p = cdr(p);
    }
    // Store the remaining values of q if not empty
    while (q!= nullptr){
        result = cons(car(q), result);
        q = cdr(q);
    }
    // Reverse and return the result
    result = reverse(result);
    return result;
}
/**Creates a linked list from a given array
* @params an int array and a length of the array
* @return a linked list created from a given array
* pre-condition: none
* post-condition: none
*/
Node* array2List(int A[], int n){
    //Return null pointer if array is empty
    if(n==0) return nullptr;
    Node* result = nullptr;
    //Store from the end of the array
    for (int i=n-1; i>=0; i--)
        result = cons(A[i], result);
    return result;
}
/**Read integers from standard input and build a linked list
* @params none
* @return a linked list p
* pre-condition: inputs must be integer number
* post-condition: none
*/
Node* readList(){
    Node *p = NULL;
    int x;
    while (cin >> x)
        p = cons(x, p);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return reverse (p);
}
/**Delete every node of a linked list
* @params a linked list p
* @return a null pointer
* pre-condition: none
* post-condition: Every node of a linked list will be deleted
*/
Node* deleteList(Node* p){
    Node* temp;
    while(p != nullptr){
        //temp pointer to point to the node that pointer p in pointed to
        temp = p;
        //move pointer p to the next node
        p = cdr(p);
        //delete the node that temp pointer is pointed to
        delete temp;
    }
    delete p;
    p = nullptr;
    return p;
}
