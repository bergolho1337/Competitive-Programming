#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        int X;
        scanf("%d",&X);
        if (X & 1)
            printf("%d is odd\n",X);
        else
            printf("%d is even\n",X);
    }
    return 0;
}
