/**
** Program Name: LinkedList
** Purpose: Implement a structure for representing a linked list of integers and functions to illustrate its various features
** Author: Chiemi Mita
** Limitation: No known limitations
*/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

using namespace std;

struct Node {
    int value;
    Node *next;
};

//Function prototypes
int car(Node* p);
void setcar(Node* p, int x);
void setcdr(Node* p, Node* q);
Node* cons(int x, Node* p);

int length(Node* p);
Node* readList();
void printList(Node *p);
bool searchInOrder(int x, Node* p);
bool hasDuplicates(Node *p);
bool member(int x, Node* p);
Node* append(int x, Node* p);
Node* reverse(Node* p);
bool isLonger(Node *p, Node *q);
Node* ithNode(Node* p, int i);
Node* deleteList(Node* p);
Node* mergeTwoOrderedLists(Node *p, Node *q);
Node* array2List(int A[], int n);

#endif

