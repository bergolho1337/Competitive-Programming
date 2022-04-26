/*
 * Chapter 3: Stacks and Queues
 *	Imagine a stack of plates, if the stack gets too high, it might topple.
 * Therefore, in real life, we would likely start a new stack when the previous
 * stack exceeds some threashold. Implement a data structure SetOfStacks that
 * mimics this. SetOfStacks should be composed of several stacks and should create
 * a new stack once the previous one exceeds capacity. SetOfStacks.push() and 
 * SetOfStacks.pop() should behave identically to a single stack.
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
// Solution: O(n)
template<class T>
class SetOfStacks {
private:
    const int stack_capacity = 5;
    const int number_of_stacks = 5;
    int cur_stack;
    Stack<T>* stack_arr;
public:
    SetOfStacks ();
    ~SetOfStacks ();
    inline int getCurrentStack () { return this->cur_stack; }
    void push (const T &value);
    SNode<T>* peek ();
    T pop ();
    bool isEmpty ();
};

template<class T>
SetOfStacks<T>::SetOfStacks () {
    this->cur_stack = 0;
    this->stack_arr = new Stack<T>[this->number_of_stacks]();
}

template<class T>
SetOfStacks<T>::~SetOfStacks () {
    while (!isEmpty())
        pop();
    delete [] this->stack_arr;
}

template<class T>
void SetOfStacks<T>::push (const T &value) {
    int num_nodes_cur_stack = this->stack_arr[this->cur_stack].getNumNodes();
    // We need to pass the value to the next stack
    if (num_nodes_cur_stack+1 > this->stack_capacity) {
        this->cur_stack++;
        printf("[!] Moving to next stack! Current stack index: %d\n",this->cur_stack);
        if (this->cur_stack > this->number_of_stacks) {
            fprintf(stderr,"[-] ERROR! Maximum number of stacks reached!\n");
            return;
        }
    }
    this->stack_arr[this->cur_stack].push(value);
}

template<class T>
SNode<T>* SetOfStacks<T>::peek () {
    return this->stack_arr[this->cur_stack]->peek();
}

template<class T>
T SetOfStacks<T>::pop () {
    if (isEmpty()) {
        fprintf(stderr,"[-] ERROR! Stack is EMPTY!\n");
        return 0;
    }
    else {
        int num_nodes_cur_stack = this->stack_arr[this->cur_stack].getNumNodes();
        // We need to get the value from the previous stack
        if (num_nodes_cur_stack-1 < 0) {
            this->cur_stack--;
            printf("[!] Moving to previous stack! Current stack index: %d\n",this->cur_stack);
            if (this->cur_stack < 0) {
                fprintf(stderr,"[-] ERROR! Invalid stack reached!\n");
                return 0;
            }
        }
        return this->stack_arr[this->cur_stack].pop();
    }
}

template<class T>
bool SetOfStacks<T>::isEmpty () {
    return (this->cur_stack == 0 && this->stack_arr[this->cur_stack].isEmpty());
}

int main () {
    SetOfStacks<int> *set_stacks = new SetOfStacks<int>();
    set_stacks->push(1);
    set_stacks->push(2);
    set_stacks->push(3);
    set_stacks->push(4);
    set_stacks->push(5);
    set_stacks->push(6);
    set_stacks->push(7);
    set_stacks->push(8);
    set_stacks->push(9);
    set_stacks->push(10);
    set_stacks->push(11);
    set_stacks->push(12);
    while (!set_stacks->isEmpty()) {
        int value = set_stacks->pop();
        printf("%d\n",value);
    }
    delete set_stacks;

    return 0;
}
