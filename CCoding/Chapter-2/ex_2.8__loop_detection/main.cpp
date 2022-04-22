/*
 * Chapter 2: Linked Lists
 *	Given a circular linked list, implement an algorithm that returns 
 * the node at the beginning of the loop.
 * */

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
	SLLNode* searchNode (const int value) {
		SLLNode *tmp = this->head;
		while (tmp != nullptr) {
			if (tmp->getData() == value) {
				return tmp;
			}
			tmp = tmp->getNext();
		}
		printf("Node '%d' not found in the list!\n",value);
		return nullptr;
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

// Question function
// Solution: O(n)
SLLNode* loop_detection (SinglyLinkedList *l) {
	SLLNode *tmp = l->getHead();
	SLLNode *runner = l->getHead();
	while (tmp != nullptr && runner != nullptr) {	
		// Move the pointers
		tmp = tmp->getNext();
		runner = runner->getNext(); 
		if (runner)
			runner = runner->getNext();
		
		// Check collision
		if (tmp == runner) 
			break;
	}
	
	// We detect a cycle!
	if (tmp == runner) {
		// Get the loop start reference
		tmp = l->getHead();
		while (tmp != runner) {
			tmp = tmp->getNext();
			runner = runner->getNext();
		}
		return tmp;
	}
	
	// No cycle
	return nullptr;
}

int main () {
	
	printf("TEST CASE 1\n");
	SinglyLinkedList *l1 = new SinglyLinkedList();
	for (int i = 0; i < 9; i++)
		l1->insertNode(i+1);
	//l1->printList();
	
	// Set the cycle
	SLLNode *tail = l1->searchNode(9);
	SLLNode *chead = l1->searchNode(3);
	tail->setNext(chead);
	
	// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 
	//           ^							   ^
	//			 |							   |
	//			 -------------------------------
	
	SLLNode *loop_node = loop_detection(l1);
	if (loop_node) 
		printf("Loop detected! Cycle starts at node '%d'!\n",loop_node->getData());
	else
		printf("No loop detect on list!\n");
	
	// Unset the cycle
	tail->setNext(nullptr);
	
	delete l1;
	
	printf("TEST CASE 2\n");
	SinglyLinkedList *l2 = new SinglyLinkedList();
	for (int i = 0; i < 9; i++)
		l2->insertNode(i+1);
	//l2->printList();
	
	// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
	
	loop_node = loop_detection(l2);
	if (loop_node) 
		printf("Loop detected! Cycle starts at node '%d'!\n",loop_node->getData());
	else
		printf("No loop detect on list!\n");
	
	delete l2;
	
	return 0;
}
