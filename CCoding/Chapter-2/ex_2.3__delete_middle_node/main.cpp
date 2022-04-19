/*
 * Chapter 2: Linked Lists
 *	Implement an algorithm to delete a node in the middle of a singly
 * linked list, given only acess to that node.
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

SLLNode* getMiddleNode (SinglyLinkedList *l1) {
	int num_nodes = l1->getNumNodes();
	int half_nodes = num_nodes/2;
	SLLNode *tmp = l1->getHead();
	int k = 1;
	while (tmp != nullptr && k != half_nodes) {
		k++;
		tmp = tmp->getNext();
	}
	return tmp;
}

// Question function
// Solution: O(1)
void deleteMiddleNode (SinglyLinkedList *l1, SLLNode *m_node) {
	if (m_node->getNext() == nullptr) {
		printf("Cannot delete middle node! Next pointer is null!\n");
		return;
	}
	
	SLLNode *next_ptr = m_node->getNext();
	m_node->setData(next_ptr->getData());
	m_node->setNext(next_ptr->getNext());
	
	delete next_ptr;
}

int main () {
	SinglyLinkedList *l1 = new SinglyLinkedList();
	l1->insertNode(1);
	l1->insertNode(2);
	l1->insertNode(3);
	l1->insertNode(4);
	l1->insertNode(5);
	l1->insertNode(6);
	l1->printList();
	
	// Get middle node reference from the list
	SLLNode *middle_node = getMiddleNode(l1);
	//middle_node->print();
	
	deleteMiddleNode(l1,middle_node);
	l1->printList();
	
	delete l1;
	
	return 0;
}
