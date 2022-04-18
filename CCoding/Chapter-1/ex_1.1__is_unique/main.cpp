/*
 * Chapter 1: Arrays and Strings
 *	Implement an algorithm to determine if a string has all unique characters 
 *  What if you cannot use additional data structures.
 * 
*/
#include <bits/stdc++.h>

using namespace std;

// Solution 1 - Using a additional boolean array
// O(n)
bool check_unique (string s) {
	int n = s.size();
	bool mask[128];
	memset(mask,false,sizeof(bool)*128);
	for (int i = 0; i < n; i++) {
		if (mask[s[i]])
			return false;
		mask[s[i]] = true;
	}
	printf("\n");
	return true;
}

int main () {
	string str1 = "abcdefghi";		// should return true
	string str2 = "abcddefghi";		// should return false
	
	bool c1 = check_unique(str1);
	if (c1)
		printf("String '%s' has all unique characters!\n",str1.c_str());
	else
		printf("String '%s' is NOT unique!\n",str1.c_str());
		
	bool c2 = check_unique(str2);
	if (c2)
		printf("String '%s' has all unique characters!\n",str2.c_str());
	else
		printf("String '%s' is NOT unique!\n",str2.c_str());
	
	return 0;
}
