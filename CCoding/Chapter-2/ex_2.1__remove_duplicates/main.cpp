/*
 * Chapter 2: Linked Lists
 *	Write code to remove duplicates from an unsorted linked list
 * FOLLOW UP:
 *  How would you solve this problem if a temporary buffer is not allowed
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

// Question function
// Solution: O(n)
void removeDuplicates (SinglyLinkedList *l) {
	SLLNode *tmp = l->getHead();
	unordered_map<int,int> hash_table;
	while (tmp != nullptr) {
		int data = tmp->getData();
		if (hash_table.find(data) == hash_table.end()) {
			hash_table[data] = 1;
		}
		else {
			tmp = l->removeNode(tmp);
		}
		tmp = tmp->getNext();
	}
}

int main () {
	SinglyLinkedList *l1 = new SinglyLinkedList();
	
	l1->insertNode(3);
	l1->insertNode(2);
	l1->insertNode(1);
	l1->insertNode(5);
	l1->insertNode(3);
	l1->insertNode(6);
	l1->insertNode(1);
	l1->insertNode(1);
	l1->printList();
	
	removeDuplicates(l1);
	
	l1->printList();
	
	delete l1;
	
	return 0;
}
