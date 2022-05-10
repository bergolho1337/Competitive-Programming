#ifndef MYBST_H
#define MYBST_H

// Implementation of a Binary Search Tree data structure using templates

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

template<class T>
class BSTNode {

public:
    uint32_t id;
    T value;
    BSTNode *left;
    BSTNode *right;
public:
    BSTNode (const uint32_t id, const T &value, BSTNode *left = nullptr, BSTNode *right = nullptr) {
        this->id = id;
        this->value = value;
        this->left = left;
        this->right = right;
    }
    ~BSTNode () {
        this->left = nullptr;
        this->right = nullptr;
    }
    void print () {
        if (typeid(T) == typeid(double))
            printf("|| %u [%g] ||\n", this->id, this->value);
        else if (typeid(T) == typeid(int))
            printf("|| %u [%d] ||\n", this->id, this->value);
    }
};

template<class T>
class BST {

public:
    uint32_t num_nodes;
    BSTNode<T> *root;
public:
    BST ();
    ~BST ();
    void insert (const T &value);
    BSTNode<T>* search (const T &value);
    void remove (const T &value);
    void printInOrder ();
    void printPreOrder ();
    void printPosOrder ();
    bool isEmpty (BSTNode<T> *root);
private:
    BSTNode<T>* freeBST (BSTNode<T> *root);
    void printInOrderAux (BSTNode<T> *root);
    void printPreOrderAux (BSTNode<T> *root);
    void printPosOrderAux (BSTNode<T> *root);
    BSTNode<T>* removeAux (BSTNode<T> *root, const T &value);
    BSTNode<T>* searchAux (BSTNode<T> *root, const T &value);
    BSTNode<T>* insertAux (BSTNode<T> *root, BSTNode<T> *newNode);

};

template<class T>
BST<T>::BST () {
    this->num_nodes = 0;
    this->root = nullptr;
}

template<class T>
BST<T>::~BST () {
    this->root = freeBST(this->root);
}

template<class T>
BSTNode<T>* BST<T>::freeBST (BSTNode<T> *root) {
    if (!this->isEmpty(root)) {
        root->left = freeBST(root->left);
        root->right = freeBST(root->right);
        delete root;
        root = nullptr;
    }
    return nullptr;
}

template<class T>
void BST<T>::insert (const T &value) {
    uint32_t num_nodes = this->num_nodes;
    BSTNode<T> *n = new BSTNode<T>(num_nodes,value);
    this->root = insertAux(this->root,n);
    this->num_nodes++;
}

template<class T>
BSTNode<T>* BST<T>::insertAux (BSTNode<T> *root, BSTNode<T> *newNode) {
    if (root == nullptr) {
        return newNode;
    }
    else {
        if (newNode->value < root->value) {
            root->left = insertAux(root->left,newNode);
        }
        else if (newNode->value > root->value) {
            root->right = insertAux(root->right,newNode);
        }
        else {
            fprintf(stderr,"[-] Value is already in the tree!\n");
        }
    }
    return root;
}

template<class T>
BSTNode<T>* BST<T>::search (const T &value) {
    return searchAux(this->root,value);
}

template<class T>
BSTNode<T>* BST<T>::searchAux (BSTNode<T> *root, const T &value) {
    if (root == nullptr) {
        fprintf(stderr,"[-] Could not find element!\n");
        return nullptr;
    }
    else {
        if (value < root->value) {
            return searchAux(root->left,value);
        }
        else if (value > root->value) {
            return searchAux(root->right,value);
        }
        else {
            return root;
        }
    }
}

template<class T>
void BST<T>::remove (const T &value) {
    removeAux(this->root,value);
}

template<class T>
BSTNode<T>* BST<T>::removeAux (BSTNode<T> *root, const T &value) {
    if (root == nullptr) {
        fprintf(stderr,"[-] Could not find element!\n");
        return nullptr;
    }
    else if (value < root->value) {
        root->left = removeAux(root->left,value);
    }
    else if (value > root->value) {
        root->right = removeAux(root->right,value);
    }
    else {
        // Leaf
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        }
        // One offspring in the left subtree
        else if (root->left && !root->right) {
            BSTNode<T> *tmp = root;
            root = root->left;
            delete tmp;
            tmp = nullptr;
        }
        // One offspring in the right subtree
        else if (!root->left && root->right) {
            BSTNode<T> *tmp = root;
            root = root->right;
            delete tmp;
            tmp = nullptr;
        }
        // Two offsprings
        else {
            BSTNode<T> *parent = root;
            BSTNode<T> *tmp = root->right;
            // Find the first node greater than 'value' in the right subtree
            while (tmp->left != nullptr) {
                parent = tmp;
                tmp = tmp->left;
            }
            // Exchange data between the nodes 'root' and 'tmp'
            root->value = tmp->value;
            tmp->value = value;
            // Remove 'value' node which has now only one offspring
            root->right = removeAux(root->right,value);
        }
    }
    return root;
}

template<class T>
void BST<T>::printInOrder () {
    printInOrderAux(this->root);
}

template<class T>
void BST<T>::printPreOrder () {
    printPreOrderAux(this->root);
}

template<class T>
void BST<T>::printPosOrder () {
    printPosOrderAux(this->root);
}

template<class T>
void BST<T>::printInOrderAux (BSTNode<T> *root) {
    if (root) {
        printInOrderAux(root->left);
        root->print();
        printInOrderAux(root->right);
    }
}

template<class T>
void BST<T>::printPreOrderAux (BSTNode<T> *root) {
    if (root) {
        root->print();
        printPreOrderAux(root->left);
        printPreOrderAux(root->right);
    }
}

template<class T>
void BST<T>::printPosOrderAux (BSTNode<T> *root) {
    if (root) {
        printPosOrderAux(root->left);
        printPosOrderAux(root->right);
        root->print();
    }
}

template<class T>
bool BST<T>::isEmpty (BSTNode<T> *root) {
    return (root) ? false : true;
}

#endif