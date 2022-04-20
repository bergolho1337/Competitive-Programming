/*
 * Chapter 2: Linked Lists
 *	Implement a function to check if a linked list is a palindrome.
*/

#include <bits/stdc++.h>

using namespace std;

class SLLNode {
private:
	char data;
	SLLNode *next;
public:
	SLLNode () {}
	SLLNode (const char data, SLLNode *next) {
		this->data = data;
		this->next = next;
	}
	~SLLNode () {
		this->next = nullptr;
	}
	char getData () { return this->data; }
	void setData (const int value) { this->data = value; }
	SLLNode* getNext () { return this->next; }
	void setNext (SLLNode *ptr) { this->next = ptr; }
	void print () {
		printf("|| %c ||",this->data);
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
	
	void insertNode (const char value) {
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
	SLLNode* removeNode (const char value) {
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
			printf("Node %c was not found!\n",value);
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
			printf("Node %c was not found!\n",ptr->getData());
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

void reverseListHelper (SLLNode *head, SinglyLinkedList *rl) {
	if (head == nullptr) return;
	
	reverseListHelper(head->getNext(),rl);
	
	rl->insertNode(head->getData());
}

SinglyLinkedList* reverseList (SinglyLinkedList *l) {
	SinglyLinkedList *rl = new SinglyLinkedList();
	SLLNode *head = l->getHead();
	reverseListHelper(head,rl);
	return rl;
}

// Question function
// Solution: O(n)
bool check_palindrome (SinglyLinkedList *l) {
	SinglyLinkedList *rl = reverseList(l);
	//rl->printList();
	
	SLLNode *head = l->getHead();
	SLLNode *rhead = rl->getHead();
	while (head != nullptr && rhead != nullptr) {
		if (head->getData() != rhead->getData()) {
			delete rl;
			return false;
		}
		head = head->getNext();
		rhead = rhead->getNext();
	}
	delete rl;
	return true;
}

int main () {
	SinglyLinkedList *l1 = new SinglyLinkedList();
	l1->insertNode('a');
	l1->insertNode('b');
	l1->insertNode('c');
	l1->insertNode('d');
	l1->insertNode('e');
	l1->insertNode('f');
	l1->printList();
	
	SinglyLinkedList *l2 = new SinglyLinkedList();
	l2->insertNode('a');
	l2->insertNode('b');
	l2->insertNode('c');
	l2->insertNode('c');
	l2->insertNode('b');
	l2->insertNode('a');
	l2->printList();
	
	bool c1 = check_palindrome(l1);
	if (c1) {
		printf("The list is a palindrome!\n");
	}
	else {
		printf("The list is NOT a palindrome!\n");
	}
	
	bool c2 = check_palindrome(l2);
	if (c2) {
		printf("The list is a palindrome!\n");
	}
	else {
		printf("The list is NOT a palindrome!\n");
	}
	
	delete l1;
	delete l2;
	
	return 0;
}
