/**
** Program Name: BST
** File Name: Customer.h
** Purpose: Declares the header for the BST class
** Author: Chiemi Mita
*/

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <stdexcept>

using namespace std;

// class prototype
template <typename T>
class BSTNode;

template <typename T>
class BST;


// Class BSTNode
template <typename T>
class BSTNode{
public:
    BSTNode(){
        left = right = nullptr;
    }
    BSTNode(const T& e, BSTNode<T> *l=nullptr, BSTNode<T> *r=nullptr){
        elm = e;
        left = l;
        right = r;
    }
    void getList(vector<int> &v){
        if (left)
            left->getList(v);
        v.push_back(elm);
        if(right)
            right->getList(v);
    }

    T elm;
    BSTNode<T> *left, *right;
};

// Class BSTNodeif(root->left != nullptr)
template <typename T>
class BST{
public:
    BST(){ root = nullptr; }

    BSTNode<T>* getRoot(){ return root;}
    void deleteAll(BSTNode<T> *root);
    void insert (const T& data);
    vector<int>* getList();
    bool empty();
    void getList (vector<int> &v);

private:
    BSTNode<T> *root;
};


template <typename T>
void BST<T>::insert(const T& data){
    BSTNode<T> *p = root, *prev=0;
    while(p != nullptr){
        prev = p;
        if (data < p->elm)
            p = p->left;
        else
            p = p->right;
    }
    if(root == nullptr)
        root = new BSTNode<T>(data);
    else if (data < prev->elm)
        prev->left = new BSTNode<T>(data);
    else
        prev->right = new BSTNode<T>(data);
}
template <typename T>
bool BST<T>::empty(){
    return root == nullptr;
}
template <typename T>
void BST<T>::getList (vector<int> &v){
    root->getList(v);
}

#endif // BST_H_INCLUDED
