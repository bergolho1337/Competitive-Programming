#include <bits/stdc++.h>

using namespace std;

int main () {
	int X, Y;
    while (scanf("%d %d",&X,&Y) != EOF) {
        if (X == 0 && Y == 1)
            printf("ALL GOOD\n");
        else if (Y == 1)
            printf("IMPOSSIBLE\n");
        else
            printf("%.6lf\n",-X/(Y-1.0));
    }
    return 0;
}
