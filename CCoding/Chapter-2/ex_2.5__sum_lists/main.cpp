/*
 * Chapter 2: Linked Lists
 *	You have two numbers represented by a linked a list, where each node
 * contains a single digit. The digits are stored in reverse order, such
 * that the first digit is at teh head of the list. Write a function
 * that adds the two numbers and returns the sum as a linked list
*/

#include <bits/stdc++.h>

using namespace std;

void print_list (list<int> l) {
	for (auto it : l) {
		printf("|| %d || --> ",it);
	}
	printf("\n");
}

list<int> sum_lists (list<int> l1, list<int> l2) {
	list<int> out;
	int carry = 0;
	list<int>::iterator it1 = l1.begin();
	list<int>::iterator it2 = l2.begin();
	while (it1 != l1.end() && it2 != l2.end()) {
		// Calculate the sum and carry values
		int sum = (*it1) + (*it2) + carry;
		int value = sum % 10;
		carry = sum / 10;
		
		// Put the result in the output list
		out.push_back(value);
		
		// Advance the pointers
		it1++;
		it2++;
	}
	
	// Solve the any remaining digits from one of the lists
	if (it1 == l1.end()) {	// List 2 is not over yet ...
		while (it2 != l2.end()) {
			int sum = (*it2) + carry;
			int value = sum % 10;
			carry = sum / 10;
			
			out.push_back(value);
			
			it2++;
		}
	}
	else { // List 1 is not over yet ...
		while (it1 != l1.end()) {
			int sum = (*it1) + carry;
			int value = sum % 10;
			carry = sum / 10;
			
			out.push_back(value);
			
			it1++;
		}
	}
	
	// Check if the carry is greater than zero
	if (carry > 0) {
		out.push_back(carry);
	}
	return out;
}

int main () {
	printf("TEST CASE 1\n");
	
	list<int> l1;
	l1.push_back(7);
	l1.push_back(1);
	l1.push_back(6);
	print_list(l1);
	
	list<int> l2;
	l2.push_back(5);
	l2.push_back(9);
	l2.push_back(2);
	print_list(l2);
	
	list<int> l3 = sum_lists(l1,l2);
	print_list(l3);
	
	printf("TEST CASE 2\n");
	
	list<int> l4;
	l4.push_back(1);
	l4.push_back(0);
	l4.push_back(0);
	l4.push_back(1);
	print_list(l4);
	
	list<int> l5;
	l5.push_back(9);
	l5.push_back(9);
	l5.push_back(9);
	print_list(l5);
	
	list<int> l6 = sum_lists(l4,l5);
	print_list(l6);
	
	printf("TEST CASE 3\n");
	
	list<int> l7;
	l7.push_back(1);
	print_list(l7);
	
	list<int> l8;
	l8.push_back(9);
	l8.push_back(9);
	l8.push_back(9);
	print_list(l8);
	
	list<int> l9 = sum_lists(l7,l8);
	print_list(l9);
	
	return 0;
}
