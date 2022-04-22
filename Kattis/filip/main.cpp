#include <bits/stdc++.h>

using namespace std;

int main () {
	string s1, s2;
    while (cin >> s1 >> s2) {
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int num1 = stoi(s1);
        int num2 = stoi(s2);
        if (num1 > num2)
            printf("%d\n",num1);
        else
            printf("%d\n",num2);
    }
    return 0;
}
