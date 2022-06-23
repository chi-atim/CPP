/*
 * Name: Chiemi Mita
 * ID: 100320919
 * Instructor: Bita Shadgar
 * Section: CPSC 2150 - 001
 * testAVL.cpp: Tests AVL tree function
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include "AVLTree.h"
#include "BST.h"

using namespace std;

int getInput();
void genInputFile(int n, string filename);
AVLTree<int>* BuildAVLTree(string filename);
void InsertNodeAVL(AVLTree<int>* tree, int element);
void DeleteNodeAVL(AVLTree<int>* tree, int element);
BSTNode<int>* deleteNode(BSTNode<int>*& node, int element);
void DeleteAVLTree(AVLTree<int>* tree);
void deleteAllNode(BSTNode<int>*& node);
void printAVL(AVLTree<int>* tree);

int n;
string filename = "AVL_input0.txt";

// Reads the number of data n from input file
// generates a random non-negative integer if the file doesn't exist
int getInput(){

    // Read from the text file
    ifstream infile(filename);
    string line;
    // generates number of data if the file doesn't exist
    if (!infile.is_open()){
        n = (rand() % 30) + 10; // the number of data in the file(n)
    }
    // The first number in the file(n) represents the number of data
    else{
        getline(infile, line);
        n = stoi(line);
    }
    infile.close();
    return n;
}

// Generates an input file
void genInputFile(int n, string filename){

    // Read from the text file
    ifstream infile(filename);
    string line;
    // Create/open a text file
    ofstream outfile;
    // generates an input file if the given file doesn't exist
    if (!infile.is_open()){
        outfile.open(filename);
        outfile << n << endl; // the number of data
        for (int i=0; i<n; i++){
            int data = (rand() % 4999) + 1001; // generates an input file integers (greater than 1000 and less than 5000)
            outfile << data << endl; // Add data in the file
        }
    }
    infile.close();
    outfile.close();
}

// Builds an AVL tree from the information in the given file
AVLTree<int>* BuildAVLTree(string filename){

    // Read from the text file
    ifstream infile(filename);
    string line;

    // Skip the first line (number of element)
    getline(infile, line);

    // Create an AVL tree with n nodes
    AVLTree<int>* avlTree = new AVLTree<int>();

    while(getline (infile, line)) {
        InsertNodeAVL(avlTree, stoi(line));
    }
    infile.close();
    return avlTree;
}

// Inserts a node into an AVL tree
void InsertNodeAVL(AVLTree<int>* tree, int element){

    BSTNode<int>*& node = tree->getRoot();
    // Insert an element into BST
    tree->insert(element);

    // Re-balance the tree
    int balance = tree->getBF(node);
    if (balance > 1){
        if (element <= node->left->elm)
            node = tree->singleRightRotate(node);
        else
            node = tree->doubleRightRotate(node);
    }
    else if(balance < -1){
        if (element > node->right->elm)
            node = tree->singleLeftRotate(node);
        else
            node = tree->doubleLeftRotate(node);
    }
}

// Delete only one node if there is duplicate nodes
void DeleteNodeAVL(AVLTree<int>* tree, int element){

    BSTNode<int>*& node = tree->getRoot();

    // Delete a node with given value
    node = deleteNode(node, element);

    // Re-balance the tree
    int balance = tree->getBF(node);
    if (balance > 1){
        if (element > node->left->elm)
            node = tree->singleRightRotate(node);
        else
            node = tree->doubleRightRotate(node);
    }
    else if(balance < -1){
        if (element <= node->right->elm)
            node = tree->singleLeftRotate(node);
        else
            node = tree->doubleLeftRotate(node);
    }
}

BSTNode<int>* deleteNode(BSTNode<int>*& node, int element){

    // Element not found
    if (node == nullptr)
        return nullptr;

    // Element is smaller than node element
    if (element < node->elm)
        node->left = deleteNode(node->left, element);

    // Element is larger than node element
    else if (element > node->elm)
        node->right = deleteNode(node->right, element);

     // Element found
     else if (element == node->elm){
        BSTNode<int>* r = node->right;

        if(node->right == nullptr){
            BSTNode<int>* l = node->left;
            delete node;
            node = l;
        }
        else if(node->left == nullptr){
            delete node;
            node = r;
        }
        else{
            while(r->left != nullptr)
                r = r->left;
            node->elm = r->elm;
            node->right = deleteNode(node->right, r->elm);
        }
    }
    return node;
}

// Frees an AVL tree and all its nodes
void DeleteAVLTree(AVLTree<int>* tree){
    deleteAllNode(tree->getRoot());
    BSTNode<int>*& node = tree->getRoot();
    delete node;
    node = nullptr;
}

// Helper function for deleting avl tree
// Delete each node recursively
void deleteAllNode(BSTNode<int>*& node){
    if (node != nullptr){
        // Delete nodes in the left subtree
        deleteAllNode(node->left);
        // Delete nodes in the right subtree
        deleteAllNode(node->right);
        delete node;
    }
    node = nullptr;
}

// Prints pre-order and in order traversal of the given AVL tree
void printAVL(AVLTree<int>* tree){
    cout << "pre-order:" << endl;
    tree->preOrder(tree->getRoot());
    cout << endl;
    cout << "in-order:" << endl;
    tree->inOrder(tree->getRoot());
    cout << endl;
}

int main(){

    srand(time(0));

    // declaration of your variables ...
    n = getInput(); // either generates a random non-negative integer or reads it from input
    genInputFile(n, filename); // generates an input file as explained in part B

    cout << "****** First AVL tree test ******" << endl;
    AVLTree<int>* avl;
    avl = BuildAVLTree(filename);
    cout << "height of AVL tree is: " << avl->height() << endl;
    printAVL(avl);

    cout << endl;

    int node;
    cout << "Enter a value to insert: ";
    cin >> node;
    InsertNodeAVL(avl, node);
    cout << "height of AVL tree is: " << avl->height() << endl;
    printAVL(avl);

    cout << endl;

    cout << "Enter a value to delete: " ;
    cin >> node;
    DeleteNodeAVL(avl, node);
    cout << "height of AVL tree is: " << avl->height() << endl;
    printAVL(avl);

    cout << endl;

    cout << "Deleting AVL tree" << endl;
    DeleteAVLTree(avl);
    printAVL(avl);

    cout << "\n****** Second AVL tree test ******" << endl;
    int n;
    string filename = "AVL_input1.txt";

    n = getInput(); // either generates a random non-negative integer or reads it from input
    genInputFile(n, filename); // generates an input file as explained in part B

    AVLTree<int>* avl_test;
    avl_test = BuildAVLTree(filename);
    cout << "height of AVL tree is: " << avl_test->height() << endl;
    printAVL(avl_test);

    cout << endl;

    cout << "Enter a value to insert: ";
    cin >> node;
    InsertNodeAVL(avl_test, node);
    cout << "height of AVL tree is: " << avl_test->height() << endl;
    printAVL(avl_test);

    cout << endl;

    cout << "Enter a value to delete: " ;
    cin >> node;
    DeleteNodeAVL(avl_test, node);
    cout << "height of AVL tree is: " << avl_test->height() << endl;
    printAVL(avl_test);

    cout << endl;

    cout << "Deleting AVL tree" << endl;
    DeleteAVLTree(avl_test);
    printAVL(avl_test);

    return 0;
}


