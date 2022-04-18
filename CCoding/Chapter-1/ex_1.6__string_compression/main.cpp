/*
 * Chapter 1: Arrays and Strings
 *	Implement a method to perform basic string compression using counts
 * of repeated characters. For example, the aabcccccaaa would become
 * a2b1c5a3. If the "compressed" string would not become smaller than
 * the original string. You can assume the string has only uppercase 
 * and lowercase letters (a-z).
*/

#include <bits/stdc++.h>

using namespace std;

string compress_string (string s) {
	int n = s.size();
	string out = "";
	int i = 0;
	while (i < n) {
		int j = i;
		int counter = 0;
		// Count the same characters
		while (s[i] == s[j] && j < n) {
			j++;
			counter++;
		}
		string aux = "";
		aux += s[i];
		aux += to_string(counter);
		out += aux;
		i = j;
	}
	return (out.size() < n) ? out : s;
}

int main () {
	
	string s1 = "aabcccccaaa";
	string s1_cpr = compress_string(s1);
	printf("'%s' --> '%s'\n",s1.c_str(),s1_cpr.c_str());
	
	string s2 = "aaaaaaaaaaaaaaaaaa";
	string s2_cpr = compress_string(s2);
	printf("'%s' --> '%s'\n",s2.c_str(),s2_cpr.c_str());
	
	string s3 = "aabbbcccccdde";
	string s3_cpr = compress_string(s3);
	printf("'%s' --> '%s'\n",s3.c_str(),s3_cpr.c_str());
	
	string s4 = "abcde";
	string s4_cpr = compress_string(s4);
	printf("'%s' --> '%s'\n",s4.c_str(),s4_cpr.c_str());
	
	return 0;
}
