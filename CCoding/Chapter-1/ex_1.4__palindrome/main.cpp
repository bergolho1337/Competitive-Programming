/*
 * Chapter 1: Arrays and Strings
 *	Given a string, write a function to check if it is a permutation of a
 * palindrome. A palindrome is a word or phrase that is the same forwards
 * and backwards. A permutation is a rearrangement of letters.
 * 
*/

#include <bits/stdc++.h>

using namespace std;

bool check_palindrome (string s) {
	int n = s.size();
	int mask[128];
	memset(mask,0,sizeof(int)*128);
	// Count the number of each character
	for (int i = 0; i < n; i++) {
		// Consider only alphanumerical characters
		if (isalnum(s[i]))
			mask[s[i]]++;
	}
		
	
	// Each letter in a palindrome word must be pairwise, except for the
	// middle one in case the word has a odd size.
	int count_even = 0;
	int count_odd = 0;
	for (int i = 0; i < 128; i++) {
		if (mask[i] % 2 == 0) count_even++;
		else 				  count_odd++;
	}
	//printf("count_even = %d\n",count_even);
	//printf("count_odd = %d\n",count_odd);
	return (count_odd > 1) ? false : true;
}

int main () {
	// YES
	string s1 = "tact coa";
	bool c1 = check_palindrome(s1);
	if (c1)
		printf("'%s' is a palindrome permutation!\n",s1.c_str());
	else
		printf("'%s' is NOT a palindrome permutation!\n",s1.c_str());
		
	// YES
	string s2 = "abccb a";
	bool c2 = check_palindrome(s2);
	if (c2)
		printf("'%s' is a palindrome permutation!\n",s2.c_str());
	else
		printf("'%s' is NOT a palindrome permutation!\n",s2.c_str());

	// YES
	string s3 = "tact cjja";
	bool c3 = check_palindrome(s3);
	if (c3)
		printf("'%s' is a palindrome permutation!\n",s3.c_str());
	else
		printf("'%s' is NOT a palindrome permutation!\n",s3.c_str());
		
	// NO
	string s4 = "tact cjza";
	bool c4 = check_palindrome(s4);
	if (c4)
		printf("'%s' is a palindrome permutation!\n",s4.c_str());
	else
		printf("'%s' is NOT a palindrome permutation!\n",s4.c_str());
}
