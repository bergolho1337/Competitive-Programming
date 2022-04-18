/*
 * Chapter 1: Arrays and Strings
 *	Assume you have a method isSubString which checks if one word is a 
 * substring of another. Given two strings s1 and s2, write code to
 * check if s2 is a rotation of s1 using only one call to isSubString
*/

#include <bits/stdc++.h>

using namespace std;

// Solution: O(N^2)
bool check_string_rotation (string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	if (n1 != n2) return false;
	
	int mid = 1;
	while (mid < n1-1) {
		string aux1 = s1.substr(0,mid);
		string aux2 = s1.substr(mid+1,n1);
		
		// The find() function is equivalent to the isSubString()
		if (s2.find(aux2) != string::npos)
			return true;
			
		//printf("%s -- %s\n",aux1.c_str(),aux2.c_str());
		mid++;
	}
	return false;
}

int main () {
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	
	// YES
	bool c1 = check_string_rotation(s1,s2);
	if (c1)
		printf("'%s' is a rotation of '%s'!\n",s1.c_str(),s2.c_str());
	else
		printf("'%s' is NOT a rotation of '%s'!\n",s1.c_str(),s2.c_str());
		
	return 0;
}
