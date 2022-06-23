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
    T elm;
    BSTNode<T> *left, *right;
};

// Class BSTNode
template <typename T>
class BST{
public:
    BST(){ root = nullptr; }

    BSTNode<T>*& getRoot(){ return root;}
    int height();
    int height(BSTNode<int> *p);
    void insert (const T& data);
    bool empty();
protected:
    BSTNode<T> *root;
};

template <typename T>
int BST<T>::height(){
    return height(root);
}
template <typename T>
int BST<T>::height(BSTNode<int> *p){
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
template <typename T>
void BST<T>::insert(const T& data){
    BSTNode<T> *p = root, *prev=0;
    while(p != nullptr){
        prev = p;
        if (data <= p->elm)
            p = p->left;
        else
            p = p->right;
    }
    if(root == nullptr){
        root = new BSTNode<T>(data);
    }

    else if (data < prev->elm)
        prev->left = new BSTNode<T>(data);
    else
        prev->right = new BSTNode<T>(data);
}
template <typename T>
bool BST<T>::empty(){
    return root == nullptr;
}

#endif // BST_H_INCLUDED
