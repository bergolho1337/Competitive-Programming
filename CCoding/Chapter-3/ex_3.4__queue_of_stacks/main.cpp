/*
 * Chapter 3: Stacks and Queues
 *	Implement a MyQueue class which implements a queue using two stacks.
*/

#include <bits/stdc++.h>

using namespace std;

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
    SNode<T> getTop () { return this->top; }
    void push (const T &value);
    SNode<T>* peek ();
    SNode<T>* min ();
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

// Question data structure
template<class T>
class myQueue {
private:
    Stack<T> *old_stack;
    Stack<T> *new_stack;    
public:
    myQueue () {
        this->old_stack = new Stack<T>();
        this->new_stack = new Stack<T>(); 
    }
    ~myQueue () {
        delete this->old_stack;
        delete this->new_stack;
    }
    bool isEmpty () {
        return (this->new_stack->isEmpty() && this->old_stack->isEmpty());
    }
    void moveNewElements () {
        // Move the elements from the 'new_stack' to 'old_stack'
        // This will ensure the FIFO property of the queue
        while (!this->new_stack->isEmpty()) {
            SNode<T> *top = this->new_stack->peek();
            this->old_stack->push(top->getValue());
            this->new_stack->pop();
        }
    }
    void push (const T &value) {
        // Add to the 'new_values' stack
        this->new_stack->push(value);
    }
    SNode<T>* peek () {
        moveNewElements();
        return this->old_stack->peek();
    }
    T pop () {
        if (isEmpty()) {
            fprintf(stderr,"[-] ERROR! Queue is EMPTY!\n");
            return 0;
        }
        else {
            moveNewElements();
            SNode<T> *tmp = this->old_stack->peek();
            this->old_stack->pop();
            return tmp->getValue();
        }
    }    
};

int main () {
    myQueue<int> *q1 = new myQueue<int>();
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);

    while (!q1->isEmpty()) {
        int value = q1->peek()->getValue();
        q1->pop();
        printf("%d\n",value);
    }
    delete q1;

}
