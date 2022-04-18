/*
 * Chapter 1: Arrays and Strings
 *	There are three types of edits that can be performed on strings:
 * insert a character, remove a character or replace a character. Given
 * two strings, write a function to check if they are one edit (or zero edits) away.
 * 
*/

#include <bits/stdc++.h>

using namespace std;

bool check_one_away (string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	if (abs(n1-n2) > 1) return false;
	
	// Count the number of characters in each string
	int mask1[128], mask2[128];
	memset(mask1,0,sizeof(int)*128);
	memset(mask2,0,sizeof(int)*128);
	for (int i = 0; i < n1; i++)
		mask1[s1[i]]++;
	for (int i = 0; i < n2; i++)
		mask2[s2[i]]++;
	
	int count_one_away = 0;
	for (int i = 0; i < 128; i++) {
		int diff = abs(mask1[i]-mask2[i]);
		if (diff > 1) return false;
		else if (diff == 1) count_one_away++;
	}
	
	return (count_one_away > 2) ? false : true;
}

int main () {
	string s1 = "pale";
	string s2 = "ple";
	string s3 = "pales";
	string s4 = "bale";
	string s5 = "bake";
	string s6 = "pakke";
	string s7 = "pe";
	string s8 = "pakkke";
	
	// YES
	bool c1 = check_one_away(s1,s2);
	if (c1)
		printf("'%s' , '%s' -> true\n",s1.c_str(),s2.c_str());
	else
		printf("'%s' , '%s' -> false\n",s1.c_str(),s2.c_str());
		
	// YES
	bool c2 = check_one_away(s3,s1);
	if (c2)
		printf("'%s' , '%s' -> true\n",s3.c_str(),s1.c_str());
	else
		printf("'%s' , '%s' -> false\n",s3.c_str(),s1.c_str());
		
	// YES
	bool c3 = check_one_away(s1,s4);
	if (c3)
		printf("'%s' , '%s' -> true\n",s1.c_str(),s4.c_str());
	else
		printf("'%s' , '%s' -> false\n",s1.c_str(),s4.c_str());
	
	// NO
	bool c4 = check_one_away(s1,s5);
	if (c4)
		printf("'%s' , '%s' -> true\n",s1.c_str(),s5.c_str());
	else
		printf("'%s' , '%s' -> false\n",s1.c_str(),s5.c_str());
		
	// NO
	bool c5 = check_one_away(s1,s6);
	if (c5)
		printf("'%s' , '%s' -> true\n",s1.c_str(),s6.c_str());
	else
		printf("'%s' , '%s' -> false\n",s1.c_str(),s6.c_str());
		
	// NO
	bool c6 = check_one_away(s1,s7);
	if (c6)
		printf("'%s' , '%s' -> true\n",s1.c_str(),s7.c_str());
	else
		printf("'%s' , '%s' -> false\n",s1.c_str(),s7.c_str());
		
	// YES
	bool c7 = check_one_away(s6,s8);
	if (c7)
		printf("'%s' , '%s' -> true\n",s6.c_str(),s8.c_str());
	else
		printf("'%s' , '%s' -> false\n",s6.c_str(),s8.c_str());
		
	return 0;
}
