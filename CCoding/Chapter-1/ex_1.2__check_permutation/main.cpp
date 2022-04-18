/*
 * Chapter 1: Arrays and Strings
 *	Given two strings write a method to decide if one is a permutation
 * of the other.
 * 
*/

#include <bits/stdc++.h>

using namespace std;

bool check_permutation (string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	if (n1 != n2) return false;
	
	int mask[128]; // ASCII table size
	memset(mask,0,sizeof(int)*128);
	
	for (int i = 0; i < n1; i++) {
		mask[s1[i]]++;
	}
	
	for (int i = 0; i < n2; i++) {
		if (mask[s2[i]] > 0)
			mask[s2[i]]--;
		else
			return false;
	}
	
	return true;
}

int main () {
	string s1 = "banana";
	string s2 = "anbnaa";
	string s3 = "ananaa";
	string s4 = "abcdefghi";
	string s5 = "ihgfedcba";
	string s6 = "abcd";
	string s7 = "abc";
	
	// This should be YES
	bool c1 = check_permutation(s1,s2);
	if (c1)
		printf("'%s' is a permutation of '%s'!\n",s1.c_str(),s2.c_str());
	else
		printf("'%s' is NOT a permutation of '%s'!\n",s1.c_str(),s2.c_str());
		
	// This should be NO
	bool c2 = check_permutation(s1,s3);
	if (c2)
		printf("'%s' is a permutation of '%s'!\n",s1.c_str(),s3.c_str());
	else
		printf("'%s' is NOT a permutation of '%s'!\n",s1.c_str(),s3.c_str());
	
	// This should be YES
	bool c3 = check_permutation(s4,s5);
	if (c3)
		printf("'%s' is a permutation of '%s'!\n",s4.c_str(),s5.c_str());
	else
		printf("'%s' is NOT a permutation of '%s'!\n",s4.c_str(),s5.c_str());
		
	// This should be NO
	bool c4 = check_permutation(s6,s7);
	if (c4)
		printf("'%s' is a permutation of '%s'!\n",s6.c_str(),s7.c_str());
	else
		printf("'%s' is NOT a permutation of '%s'!\n",s6.c_str(),s7.c_str());
		
	return 0;
}
