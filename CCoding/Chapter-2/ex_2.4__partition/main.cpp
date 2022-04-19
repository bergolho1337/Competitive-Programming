/*
 * Chapter 2: Linked Lists
 *	Write code to partition a linked list around a value x, such that all
 * nodes less than x come before all nodes greater than or equal to x. 
 * If x is contained within the list, the values of x only need to be after
 * the elements less than x. The partition element can appear anywhere
 * in the "right partition"; it does not need to appear between the left and
 * right partitions.
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
// Solution: O(n)
void partitionList (SinglyLinkedList *l1, const int k) {
	// These pointer will control the start and end of two lists.
	// One that contain elements less than k and another with elements
	// greater or equal than k
	SLLNode *bStart = nullptr;
	SLLNode *bEnd = nullptr;
	SLLNode *aStart = nullptr;
	SLLNode *aEnd = nullptr;
	
	SLLNode *tmp = l1->getHead();
	while (tmp != nullptr) {
		SLLNode *tmp_next = tmp->getNext();
		tmp->setNext(nullptr);
		
		if (tmp->getData() < k) {
			if (bStart == nullptr) {
				bStart = tmp;
				bEnd = bStart;
			}
			else {
				bEnd->setNext(tmp);
				bEnd = bEnd->getNext();
			}
		}
		else {
			if (aStart == nullptr) {
				aStart = tmp;
				aEnd = aStart;
			}
			else {
				aEnd->setNext(tmp);
				aEnd = aEnd->getNext();
			}
		}
		
		tmp = tmp_next;
	}
	
	// Merge the two lists
	bEnd->setNext(aStart);
	
}

int main () {
	SinglyLinkedList *l1 = new SinglyLinkedList();
	l1->insertNode(3);
	l1->insertNode(5);
	l1->insertNode(8);
	l1->insertNode(5);
	l1->insertNode(10);
	l1->insertNode(2);
	l1->insertNode(1);
	l1->printList();
	
	const int k = 5;
	partitionList(l1,k);
	l1->printList();
	
	delete l1;
	
	return 0;
}
