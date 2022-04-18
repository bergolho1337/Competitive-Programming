/*
 * Chapter 2: Linked Lists
 *	Implement an algorithm to find the kth to last element of a singly
 * linked list.
*/

#include <bits/stdc++.h>

using namespace std;

class SLLNode {
private:
	int data;
	SLLNode *next;
public:
	SLLNode () {}
	SLLNode (const int data, SLLNode *next) {
		this->data = data;
		this->next = next;
	}
	~SLLNode () {
		this->next = nullptr;
	}
	int getData () { return this->data; }
	void setData (const int value) { this->data = value; }
	SLLNode* getNext () { return this->next; }
	void setNext (SLLNode *ptr) { this->next = ptr; }
	void print () {
		printf("|| %d ||",this->data);
	}
};

class SinglyLinkedList {
private:
	int num_nodes;
	SLLNode *head;
public:
	SinglyLinkedList () { 
		this->num_nodes = 0;
		this->head = nullptr;
	}
	~SinglyLinkedList () {
		SLLNode *tmp = this->head;
		while (tmp != nullptr) {
			this->removeNode(tmp->getData());
			tmp = this->head;
		}
	}
	int getNumNodes () { return this->num_nodes; }
	SLLNode* getHead () { return this->head; }
	
	void insertNode (const int value) {
		if (this->head == nullptr) {
			this->head = new SLLNode(value,nullptr);
		}
		else {
			SLLNode *tmp = this->head;
			while (tmp->getNext() != nullptr) {
				tmp = tmp->getNext();
			}
			tmp->setNext(new SLLNode(value,nullptr));
		}
		this->num_nodes++;
	}
	SLLNode* removeNode (const int value) {
		SLLNode *prev = nullptr;
		SLLNode *curr = this->head;
		if (this->head->getData() == value) {
			this->head = this->head->getNext();
		}
		else {
			while (curr != nullptr && curr->getData() != value) {
				prev = curr;
				curr = curr->getNext();
			}
			prev->setNext(curr->getNext());
		}
		if (curr != nullptr) {
			delete curr;
			this->num_nodes--;
			return prev;
		}
		else {
			printf("Node %d was not found!\n",value);
			return nullptr;
		}	
	}
	SLLNode* removeNode (SLLNode *ptr) {
		SLLNode *prev = nullptr;
		SLLNode *curr = this->head;
		if (this->head == ptr) {
			this->head = this->head->getNext();
		}
		else {
			while (curr != nullptr && curr != ptr) {
				prev = curr;
				curr = curr->getNext();
			}
			prev->setNext(curr->getNext());
		}
		if (curr != nullptr) {
			delete curr;
			this->num_nodes--;
			return prev;
		}
		else {
			printf("Node %d was not found!\n",ptr->getData());
			return nullptr;
		}	
	}
	void printList () {
		SLLNode *tmp = this->head;
		printf("Number of nodes: %d\n",this->num_nodes);
		while (tmp != nullptr) {
			tmp->print();
			printf(" --> ");
			tmp = tmp->getNext();
		}
		printf("\n");
	}
};

SLLNode* kthToTheLastHelper (SLLNode *head, const int k, int &call_number) {
	// Base case
	if (head == nullptr) return 0;
	
	SLLNode *tmp = kthToTheLastHelper(head->getNext(),k,call_number);
	call_number++;
	
	if (call_number == k) return head;
	return tmp;
}

// Question function
// Solution: O(n) --> Recursive
// Space complexity --> O(n) *number of stack calls
SLLNode* kthToTheLast (SinglyLinkedList *l, const int k) {
	int call_number = 0;
	SLLNode *head = l->getHead();
	return kthToTheLastHelper(head,k,call_number);
}

// Question function
// Solution: O(n) --> Iterative
// Space complexity --> O(1)
SLLNode* kthToTheLastIterative (SinglyLinkedList *l, const int k) {
	SLLNode *curr = l->getHead();
	SLLNode *runner = l->getHead();
	
	// Move the runner 'k' positions
	for (int i = 0; i < k; i++) {
		if (runner == nullptr) return nullptr;	// 'k' is greater than the list size
		runner = runner->getNext();
	}
		
	// Move the two pointer one step at time until the 'runner' reaches
	// end of the list
	while (runner != nullptr) {
		curr = curr->getNext();
		runner = runner->getNext();
	}
	
	// The position of 'curr' at this point is exacly the kth to the last
	// since we move (size-k) positions.
	return curr;
}

int main () {
	SinglyLinkedList *l1 = new SinglyLinkedList();
	
	l1->insertNode(1);
	l1->insertNode(2);
	l1->insertNode(3);
	l1->insertNode(4);
	l1->insertNode(5);
	l1->insertNode(6);
	l1->insertNode(7);
	l1->insertNode(8);
	l1->printList();
	
	const int k = 3;
	//SLLNode *kth_node = kthToTheLast(l1,k);
	SLLNode *kth_node = kthToTheLastIterative(l1,k);
	kth_node->print();
	printf("\n");
	
	delete l1;
	
	return 0;
}
