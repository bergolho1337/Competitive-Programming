#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
    int R, E, C;
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d",&R,&E,&C);
        if (E-C > R)
            printf("advertise\n");
        else if (E-C < R)
            printf("do not advertise\n");
        else
            printf("does not matter\n");
    }
    return 0;
}
