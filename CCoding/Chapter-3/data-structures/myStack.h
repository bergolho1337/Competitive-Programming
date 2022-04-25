#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

template<class T>
class SNode {

private:
    uint32_t id;
    T value;
    SNode *next;
public:
    SNode (const uint32_t id, const T &value, SNode *next = nullptr) {
        this->id = id;
        this->value = value;
        this->next = next;
    }
    ~SNode () {
        this->next = nullptr;
    }
    inline uint32_t getId () { return this->id; }
    inline T getValue () { return this->value; }
    inline SNode* getNext () { return this->next; }
    inline void setId (const uint32_t id) { this->id = id; }
    inline void setValue (const T value) { this->value = value; }
    inline void setNext (SNode *next) { this->next = next; }
    void print () {
        if (typeid(T) == typeid(double))
            printf("|| %u [%g] ||\n", this->id, this->value);
        else if (typeid(T) == typeid(int))
            printf("|| %u [%d] ||\n", this->id, this->value);
    }
};

template<class T>
class Stack {

private:
    uint32_t num_nodes;
    SNode<T> *top;
public:
    Stack ();
    ~Stack ();
    inline uint32_t getNumNodes () { return this->num_nodes; }
    void push (const T &value);
    SNode<T>* peek ();
    T pop ();
    bool isEmpty ();
};

template<class T>
Stack<T>::Stack () {
    this->num_nodes = 0;
    this->top = nullptr;
}

template<class T>
Stack<T>::~Stack () {
    while (!isEmpty())
        pop();
}

template<class T>
void Stack<T>::push (const T &value) {
    uint32_t num_nodes = this->num_nodes;
    SNode<T> *n = new SNode<T>(num_nodes,value);

    if (isEmpty()) {
        this->top = n;
    }
    else {
        n->setNext(this->top);
        this->top = n;
    }
    this->num_nodes++;
}

template<class T>
SNode<T>* Stack<T>::peek () {
    return this->top;
}

template<class T>
T Stack<T>::pop () {
    if (isEmpty()) {
        fprintf(stderr,"[-] ERROR! Stack is EMPTY!\n");
        return 0;
    }
    else {
        SNode<T> *tmp = this->top;
        T value = tmp->getValue();
        this->top = tmp->getNext();
        delete tmp;
        this->num_nodes--;
        return value;
    }
}

template<class T>
bool Stack<T>::isEmpty () {
    return (this->top) ? false : true;
}

#endif