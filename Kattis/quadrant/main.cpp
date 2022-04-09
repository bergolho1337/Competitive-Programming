#include <bits/stdc++.h>

using namespace std;

int main () {
	int X, Y;
    while (scanf("%d %d",&X,&Y) != EOF) {
        if (X > 0 && Y > 0)
            printf("1\n");
        else if (X < 0 && Y > 0)
            printf("2\n");
        else if (X < 0 && Y < 0)
            printf("3\n");
        else if (X > 0 && Y < 0)
            printf("4\n");
    }
    return 0;
}
