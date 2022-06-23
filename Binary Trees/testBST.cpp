// testBST.cpp file
// Description: Tests BST program
// Author: Chiemi Mita
// Creation date: March 8, 2020


#include <iostream>
#include <ctime>
#include <vector>
#include "BST.h"


using namespace std;

// Function declaration
int getInput();
vector<int>* genData(int n);
void printList(vector<int> *v);
BST<int> makeBST(vector<int> *v);
void printBT(BST<int> b);
void printBT(BSTNode<int> *p);
int height(BST<int> b);
int height(BSTNode<int> *p);
void remove(int key, BST<int> b);

BST<int> mergeBST(BST<int> b1, BST<int> b2);
void copyBST(BSTNode<int>* origin, BSTNode<int>* clone);

int main(){
    srand(time(0));

    int n1 = getInput();
    vector<int> *list1 = genData(n1);
    cout << "The List1 (" << n1 << "): ";
    printList(list1);

    int n2 = getInput();
    vector<int> *list2 = genData(n2);
    cout << "The List2 (" << n2 << "): ";
    printList(list2);

    BST<int> bst1;
    bst1 = makeBST(list1);
    cout << "In-order traversal of bst1 is: ";
    printBT(bst1);

    int key = list1->at(n1/2);
    remove(key, bst1);
    cout << "In-order traversal of bst1 after deleting " << key << " is: ";
    printBT(bst1);

    BST<int> bst2;
    bst2 = makeBST(list2);
    cout << "In-order traversal of bst2 is: ";
    printBT(bst2);

    BST<int> bst3;
    bst3 = mergeBST(bst1, bst2);
    cout << "In_order traversal of bst3 is: ";
    printBT(bst3);

    cout << "The height of bst1 is " << height(bst1) << endl;
    cout << "The height of bst2 is " << height(bst2) << endl;
    cout << "The height of merged tree is " << height(bst3) << endl;


    return 0;
}

// Generates a randomly non-negative integer
int getInput(){
    return (rand() % 30) + 10;
}
// Given an integer n, generates a list of n random integer [-n, n]
vector<int>* genData(int n){
    vector<int> *list = new vector<int>(n);
    for(int i=0; i<n; i++){
        list->at(i) = rand()%((2*n) + 1) - n;
    }
    return list;
}
// Prints elements of the given list
void printList(vector<int> *v){
    int n = v->size();
    cout << "{ " ;
    for(int i=0; i<n ; i++){
        cout << v->at(i)<< " ";
    }
    cout << "}" << endl;
}

// Given a list of data, generates a binary search tree
BST<int> makeBST(vector<int> *v){
    BST<int> b;
    int n = v->size();
    for(int i=0; i<n ; i++){
        b.insert(v->at(i));
    }
    return b;
}
// Given a binary tree, prints the tree’s elements using an in-order traversal
void printBT(BST<int> b){
    printBT(b.getRoot());
    cout << "\n";
}
void printBT(BSTNode<int> *p){
    if (p != nullptr){
        printBT(p->left);
        cout << p->elm << " ";
        printBT(p->right);
    }
}
// Finds and returns the height of the binary tree
int height(BST<int> b){
    return height(b.getRoot());
}
int height(BSTNode<int> *p){
    if (p == nullptr)
        return -1;
    else{
        int hLeft = height(p->left);
        int hRight = height(p->right);

        if (hLeft > hRight)
            return hLeft + 1;
        else
            return hRight + 1;
    }
}
// Delete a given key from a given BST. It removes at most one node.
void remove(int key, BST<int> b){

    BSTNode<int> *keyNode = b.getRoot(), *prev;

    // Find a node with a given key value
    while(keyNode != nullptr && keyNode->elm != key){
        if(key < keyNode->elm)
            keyNode = keyNode->left;
        else
            keyNode = keyNode->right;
    }

    BSTNode<int> *tmp = keyNode;

    // The key node is a leaf
    if(keyNode->left == nullptr && keyNode->right == nullptr){
        delete keyNode;
        keyNode = nullptr;
    }
    // The key node has no left child
    else if (keyNode->left == nullptr){
        keyNode->elm = keyNode->right->elm;
        tmp = tmp->right;
    }

    // The key node has no right child
    else if (keyNode->right == nullptr){
        keyNode->elm = keyNode->left->elm;
        tmp = tmp->left;
    }

    // The key node has two children
    else{
        tmp = keyNode->left;
        prev = keyNode;
        while (tmp->right != nullptr){
            prev = tmp;
            tmp = tmp->right;
        }
        keyNode->elm = tmp->elm;
        if(prev == keyNode)
            prev->left = tmp->left;
        else
            prev->right = tmp->left;
    }
    delete tmp;
    tmp = nullptr;
}

// Given two binary search trees, merges them into one binary search tree.
// The origin BSTs mus remain unchanged
BST<int> mergeBST(BST<int> b1, BST<int> b2){

    BST<int> newBST;
    if (b1.empty())
        copyBST(b2.getRoot(), newBST.getRoot());
    if (b2.empty())
        copyBST(b1.getRoot(), newBST.getRoot());

    else{
        vector<int> list;
        b1.getList(list);
        b2.getList(list);
        newBST = makeBST(&list);

    }
    return newBST;
}

void copyBST(BSTNode<int>* origin, BSTNode<int>* clone){
    if (origin == nullptr)
        clone == nullptr;
    else {
        clone = new BSTNode<int>;
        clone->elm = origin->elm;
        copyBST(origin->left, clone->left);
        copyBST(origin->right, clone->right);
    }
}






