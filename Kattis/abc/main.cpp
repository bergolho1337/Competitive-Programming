#include <bits/stdc++.h>

using namespace std;

int main () {
	unordered_map<char,int> table;
    table['A'] = 0;
    table['B'] = 1;
    table['C'] = 2;
    int arr[3];
    string str;
    while (scanf("%d %d %d",&arr[0],&arr[1],&arr[2]) != EOF) {
        cin >> str;
        sort(arr,arr+3);
        printf("%d %d %d\n",arr[table[str[0]]],arr[table[str[1]]],arr[table[str[2]]]);
    }
    return 0;
}
