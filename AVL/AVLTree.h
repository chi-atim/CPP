/*
 * Name: Chiemi Mita
 * ID: 100320919
 * Instructor: Bita Shadgar
 * Section: CPSC 2150 - 001
 * AVLTree.h: Models a AVL tree
*/

#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include <iostream>
#include "BST.h"

using namespace std;

template <typename T>
class AVLTree : public BST<T>{
public:
    AVLTree(){}

    int getBF(BSTNode<T> *node);
    bool check_ballance();
    void inOrder(BSTNode<T> *node);
    void preOrder(BSTNode<T> *node);

    BSTNode<T>* singleLeftRotate(BSTNode<T>* node);
    BSTNode<T>* singleRightRotate(BSTNode<T>* node);
    BSTNode<T>* doubleLeftRotate(BSTNode<T>* node);
    BSTNode<T>* doubleRightRotate(BSTNode<T>* node);

};


template <typename T>
int AVLTree<T>::getBF(BSTNode<T> *node){
    if (node == nullptr)
        return 0;
    return BST<T>::height(node->left) - BST<T>::height(node->right);

}
template <typename T>
void AVLTree<T>::inOrder(BSTNode<T> *node){
    if(node != nullptr){
        inOrder(node->left);
        cout << node->elm << " ";
        inOrder(node->right);
    }
}
template <typename T>
void AVLTree<T>::preOrder(BSTNode<T> *node){
    if(node != nullptr){
        cout << node->elm << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
// Single Left rotation
template <typename T>
BSTNode<T>* AVLTree<T>::singleLeftRotate(BSTNode<T>* node){
    BSTNode<T>* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    return tmp;
}
// Single Right rotation
template <typename T>
BSTNode<T>* AVLTree<T>::singleRightRotate(BSTNode<T>* node){
    BSTNode<T>* tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    return tmp;
}
// Double Left rotation
template <typename T>
BSTNode<T>* AVLTree<T>::doubleLeftRotate(BSTNode<T>* node){
    node->right = singleRightRotate(node->right);
    return singleLeftRotate(node);
}
// Double Right rotation
template <typename T>
BSTNode<T>* AVLTree<T>::doubleRightRotate(BSTNode<T>* node){
    node->left = singleLeftRotate(node->left);
    return singleRightRotate(node);
}


#endif // AVL_H_INCLUDED
