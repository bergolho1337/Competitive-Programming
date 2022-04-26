/*
 * Chapter 3: Stacks and Queues
 *	Describe how you could use a single array to implement three stacks.
*/

#include <bits/stdc++.h>

using namespace std;

class StacksWithArray {
public:
    const int num_stacks = 3;
    const int num_values_per_stack = 5;
    int *values;
    int *stack_sizes;
public:
    StacksWithArray () {
        this->values = new int[this->num_values_per_stack*this->num_stacks]();
        this->stack_sizes = new int[this->num_stacks]();
    }
    ~StacksWithArray () {
        if (this->values)
            delete [] this->values;
        if (this->stack_sizes)
            delete [] this->stack_sizes;
    }
    bool isStackFull (const int stack_id) {
        return (this->stack_sizes[stack_id] == this->num_values_per_stack) ? true : false;
    }
    bool isStackEmpty (const int stack_id) {
        return (this->stack_sizes[stack_id] == 0) ? true : false;
    }
    int getTopIndex (const int stack_id) {
        int offset = stack_id*this->num_values_per_stack;
        int top = this->stack_sizes[stack_id];
        return offset + top;
    }
    void push (const int stack_id, const int value) {
        if (!isStackFull(stack_id)) {
            this->stack_sizes[stack_id]++;
            this->values[getTopIndex(stack_id)] = value;
        }
        else {
            fprintf(stderr,"[-] ERROR! Stack number '%d' is full!\n",stack_id);
        }
    }
    int pop (const int stack_id) {
        if (!isStackEmpty(stack_id)) {
            int value = this->values[getTopIndex(stack_id)];
            this->values[getTopIndex(stack_id)] = 0;
            this->stack_sizes[stack_id]--;
            return value;
        }
        else {
            fprintf(stderr,"[-] ERROR! Stack number '%d' is empty!\n",stack_id);
            return 0;
        }
    }
    void print () {
        for (int k = 0; k < this->num_stacks; k++) {
            printf("STACK %d -- size = %d/%d\n",k,this->stack_sizes[k],this->num_values_per_stack);
            for (int i = 0; i < this->stack_sizes[k]; i++) {
                printf("%d\n",this->values[getTopIndex(k)-i]);
            }
        }
    }
};

int main () {
	StacksWithArray *s1 = new StacksWithArray();
    s1->push(0,1);
    s1->push(0,2);
    s1->push(0,3);
    s1->push(0,4);
    s1->push(0,5);

    s1->push(1,10);
    s1->push(1,20);
    s1->push(1,30);

    s1->push(2,100);
    s1->push(2,200);

    //s1->print();

    int value;
    value = s1->pop(2);
    value = s1->pop(1);
    value = s1->pop(0);
    printf("%d\n",value);

    s1->print();

    delete s1;
    return 0;
}
