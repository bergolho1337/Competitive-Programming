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
    SNode<T> *minNode;
public:
    Stack ();
    ~Stack ();
    inline uint32_t getNumNodes () { return this->num_nodes; }
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
    this->minNode = nullptr;
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
        this->minNode = n;
    }
    else {
        n->setNext(this->top);
        this->top = n;
        if (value < this->minNode->getValue()) {
            this->minNode = n;
        }
    }
    this->num_nodes++;
}

template<class T>
SNode<T>* Stack<T>::peek () {
    return this->top;
}

template<class T>
SNode<T>* Stack<T>::min () {
    return this->minNode;
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

        this->minNode = this->top;
        tmp = this->top;
        while (tmp != nullptr) {
            if (tmp->getValue() < this->minNode->getValue()) {
                this->minNode = tmp;
            }
            tmp = tmp->getNext();
        }
        return value;
    }
}

template<class T>
bool Stack<T>::isEmpty () {
    return (this->top) ? false : true;
}

int main () {
    Stack<int> *s1 = new Stack<int>();
    s1->push(19);
    s1->push(12);
    s1->push(13);
    s1->push(11);
    s1->push(20);
    s1->push(14);

    printf("Top value in stack: %d\n",s1->peek()->getValue());
    printf("Minimum value in stack: %d\n",s1->min()->getValue());

    s1->pop();
    s1->pop();
    s1->pop();

    printf("Top value in stack: %d\n",s1->peek()->getValue());
    printf("Minimum value in stack: %d\n",s1->min()->getValue());

    delete s1;
    return 0;
}
