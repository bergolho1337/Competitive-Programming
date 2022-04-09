#include <bits/stdc++.h>

using namespace std;

int main () {
    int X, Y;
    while (scanf("%d %d",&X,&Y) != EOF) {
        if (X == 0 && Y == 0) break;

        if (X+Y == 13) {
            printf("Never speak again.\n");
        }
        else if (X > Y) {
            printf("To the convention.\n");
        }
        else if (X < Y) {
            printf("Left beehind.\n");
        }
        else {
            printf("Undecided.\n");
        }
    }
    return 0;
}
