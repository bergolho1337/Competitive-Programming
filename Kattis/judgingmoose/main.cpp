#include <bits/stdc++.h>

using namespace std;

int main () {
	int L, R;
    while (scanf("%d %d",&L,&R) != EOF) {
        if (L == 0 && R == 0)
            printf("Not a moose\n");
        else if (L > R)
            printf("Odd %d\n",L*2);
        else if (L < R)
            printf("Odd %d\n",R*2);
        else
            printf("Even %d\n",L*2);
    }
    return 0;
}
