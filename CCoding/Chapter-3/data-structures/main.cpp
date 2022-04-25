#include <bits/stdc++.h>
#include "myStack.h"
#include "myQueue.h"

using namespace std;

int main () {

// Testing "myStack.h"
    printf("======== STACK ================\n");
    Stack<int> *s1 = new Stack<int>();
    s1->push(1);
    s1->push(2);
    s1->push(3);
    s1->push(4);

    while (!s1->isEmpty()) {
        SNode<int> *top = s1->peek();
        top->print();
        s1->pop();
    }

    delete s1;

// Testing "myQueue.h"
    printf("======== QUEUE ================\n");
    Queue<int> *q1 = new Queue<int>();
    q1->enqueue(1);
    q1->enqueue(2);
    q1->enqueue(3);
    q1->enqueue(4);

    while (!q1->isEmpty()) {
        QNode<int> *front = q1->peek();
        front->print();
        q1->dequeue();
    }

    delete q1;

    return 0;
}