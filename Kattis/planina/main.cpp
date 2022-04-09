#include <bits/stdc++.h>

using namespace std;

int main (){
    int table[15];
    table[0] = 2.0;
    for (int i = 1; i <= 15; i++) {
        table[i] = table[i-1] + pow(2,i-1);
    }
    int N;
    while (scanf("%d",&N) != EOF) {
        printf("%u\n",table[N]*table[N]);
    }
	return 0;
}
