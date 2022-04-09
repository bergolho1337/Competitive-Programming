#include <bits/stdc++.h>

using namespace std;

int main () {
	int A, B, C, N;
    while (scanf("%d %d %d %d",&A,&B,&C,&N) != EOF) {
        if ((A+B+C >= N) && (A > 0) && (B > 0) && (C > 0) && (N >= 3))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
