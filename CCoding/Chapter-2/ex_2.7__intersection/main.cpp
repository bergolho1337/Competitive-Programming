/*
 * Chapter 2: Linked Lists
 *	Given two singly linked lists, determine if the two lists intersect.
 * Return the intersecting node. Note that the intersection is defined
 * based on reference, not value. That is, if the kth node of the first
 * linked list is the exact same node (by reference) as the jth node of
 * the second linked list, them they are intersecting.
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
SLLNode* check_intersection (SinglyLinkedList *l1, SinglyLinkedList *l2) {
	// Hash table which stores references to nodes ...
	unordered_map<SLLNode*,int> hash_table;
	
	// Insert all the nodes of 'l1' in the hash table
	SLLNode *tmp = l1->getHead();
	while (tmp != nullptr) {
		//printf("%p\n",&(*tmp));
		hash_table[tmp] = 1;
		tmp = tmp->getNext();
	}
	
	// Pass through the 'l2' nodes and check if there one element in the hash table
	tmp = l2->getHead();
	while (tmp != nullptr) {
		
		// Found a common node between the two lists!
		if (hash_table.find(tmp) != hash_table.end()) {
			return tmp;
		}
		tmp = tmp->getNext();
	}
	return nullptr;
}

int main () {
	printf("TEST CASE 1\n");
	
	SinglyLinkedList *l1 = new SinglyLinkedList();
	l1->insertNode(5);
	l1->insertNode(4);
	l1->insertNode(3);
	l1->insertNode(100);
	l1->insertNode(200);
	
	SinglyLinkedList *l2 = new SinglyLinkedList();
	l2->insertNode(1);
	l2->insertNode(2);
	
	// Set the intersection
	SLLNode *node_l1 = l1->searchNode(3);
	SLLNode *node_l2 = l2->searchNode(2);
	node_l2->setNext(node_l1);
	
	l1->printList();
	l2->printList();
	
	SLLNode *intersect_node = check_intersection(l1,l2);
	if (intersect_node) {
		printf("The list have a intersection at '%d'!\n",intersect_node->getData());
	}
	else {
		printf("The list have NO intersection!\n");
	}
	
	// Unset the intersection
	node_l2->setNext(nullptr);
	
	delete l1;
	delete l2;
	
	printf("TEST CASE 2\n");
	
	SinglyLinkedList *l3 = new SinglyLinkedList();
	l3->insertNode(1);
	l3->insertNode(2);
	l3->insertNode(3);
	l3->insertNode(4);
	l3->insertNode(5);
	
	SinglyLinkedList *l4 = new SinglyLinkedList();
	l4->insertNode(10);
	l4->insertNode(20);
	l4->insertNode(30);
	l4->insertNode(40);
	l4->insertNode(50);
	
	l3->printList();
	l4->printList();
	
	intersect_node = check_intersection(l3,l4);
	if (intersect_node) {
		printf("The list have a intersection at '%d'!\n",intersect_node->getData());
	}
	else {
		printf("The list have NO intersection!\n");
	}
	
	delete l3;
	delete l4;
	
	return 0;
}
