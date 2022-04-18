/*
 * Chapter 1: Arrays and Strings
 *	Write a method to replace all spaces in a string with '%20'.
 * You may assume the string has sufficient space at the end to hold
 * the additional characters, and that you are given the "true" length
 * of the string.
 * 
*/

#include <bits/stdc++.h>

using namespace std;

// Solution: O(n)
string urlify (string s, const int n) {
	string out = "";
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') {
			out += "%20";
		}
		else {
			out += s[i];
		}
	}
	return out;
}

int main () {
	int s1_size = 13;
	string s1 = "Mr John Smith    ";
	string s1_new = urlify(s1,s1_size);
	printf("s1 = '%s' ---> s1 = '%s'\n",s1.c_str(),s1_new.c_str());
	
	int s2_size = 18;
	string s2 = "Mr   John    Smith                   ";
	string s2_new = urlify(s2,s2_size);
	printf("s2 = '%s' ---> s2 = '%s'\n",s2.c_str(),s2_new.c_str());

	return 0;
}
