#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

template<class T>
class QNode {

private:
    uint32_t id;
    T value;
    QNode *next;
public:
    QNode (const uint32_t id, const T &value, QNode *next = nullptr) {
        this->id = id;
        this->value = value;
        this->next = next;
    }
    ~QNode () {
        this->next = nullptr;
    }
    inline uint32_t getId () { return this->id; }
    inline T getValue () { return this->value; }
    inline QNode* getNext () { return this->next; }
    inline void setId (const uint32_t id) { this->id = id; }
    inline void setValue (const T value) { this->value = value; }
    inline void setNext (QNode *next) { this->next = next; }
    void print () {
        if (typeid(T) == typeid(double))
            printf("|| %u [%g] ||\n", this->id, this->value);
        else if (typeid(T) == typeid(int))
            printf("|| %u [%d] ||\n", this->id, this->value);
    }
};

template<class T>
class Queue {

private:
    uint32_t num_nodes;
    QNode<T> *first, *back;
public:
    Queue ();
    ~Queue ();
    inline uint32_t getNumNodes () { return this->num_nodes; }
    void enqueue (const T &value);
    T dequeue ();
    QNode<T>* peek ();
    bool isEmpty ();
};

template<class T>
Queue<T>::Queue () {
    this->num_nodes = 0;
    this->first = this->back = nullptr;
}

template<class T>
Queue<T>::~Queue () {
    while (!isEmpty())
        dequeue();
}

template<class T>
void Queue<T>::enqueue (const T &value) {

    uint32_t num_nodes = this->num_nodes;
    QNode<T> *n = new QNode<T>(num_nodes,value);

    if (isEmpty()) {
        this->first = this->back = n;
    }
    else {
        this->back->setNext(n);
        this->back = n;
    }
    this->num_nodes++;
}

template<class T>
QNode<T>* Queue<T>::peek ()
{
    return this->first;
}

template<class T>
T Queue<T>::dequeue ()
{
    if (isEmpty()) {
        fprintf(stderr,"[-] ERROR! Queue is EMPTY!\n");
        return 0;
    }
    else {
        QNode<T> *tmp = this->first;
        T value = tmp->getValue();
        this->first = tmp->getNext();
        if (!this->first) this->back = nullptr;
        delete tmp;
        this->num_nodes--;
        return value;
    }
}

template<class T>
bool Queue<T>::isEmpty () {
    return (this->first && this->back) ? false : true;
}

#endif