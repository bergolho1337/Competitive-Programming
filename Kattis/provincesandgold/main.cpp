#include <bits/stdc++.h>

using namespace std;

int main () {
	int G, S, C;
    while (scanf("%d %d %d",&G,&S,&C) != EOF) {
        int money = G*3 + S*2 + C;
        if (money >= 8)
            printf("Province or Gold\n");
        else if (money < 8 && money >= 6)
            printf("Duchy or Gold\n");
        else if (money < 6 && money >= 5)
            printf("Duchy or Silver\n");
        else if (money < 5 && money >= 3)
            printf("Estate or Silver\n");
        else if (money < 3 && money >= 2)
            printf("Estate or Copper\n");
        else if (money < 2 && money >= 0)
            printf("Copper\n");
    }
    return 0;
}
