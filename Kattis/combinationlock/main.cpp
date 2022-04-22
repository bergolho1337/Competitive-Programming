#include <bits/stdc++.h>

using namespace std;

int clockwise (int n1, int n2) {
    n1 += 40;
    n1 -= n2;
    n1 %= 40;
    return n1;
}

int counterclock (int n1, int n2) {
    n2 += 40;
    n2 -= n1;
    n2 %= 40;
    return n2;
}

int main () {
	int I, A, B, C;
    while (scanf("%d %d %d %d",&I,&A,&B,&C) != EOF) {
        if (I == 0 && A == 0 && B == 0 && C == 0) break;

        int ans = 80;               // 2 full turns clockwise
        ans += clockwise(I,A);      // Stop at the first number
        ans += 40;                  // 1 full turn counter-clockwise
        ans += counterclock(A,B);   // Continue turning counter-clockwise until the second number
        ans += clockwise(B,C);      // Turn clockwise again until third number
        printf("%d\n",ans*9);
    }
    return 0;
}
