#include <bits/stdc++.h>

using namespace std;

int check_score (int n0, int n1) {
    if (n0 > n1)
        swap(n0,n1);
    
    int score;
    if (n0 == 1 && n1 == 2)
        score = 999999;
    else if (n0 == n1)
        score = n1*100;
    else
        score = n1*10 + n0; 
    return score;
}

int main () {
	int s0, s1, r0, r1;
    while (scanf("%d %d %d %d",&s0,&s1,&r0,&r1) != EOF) {
        if (s0 == 0 && s1 == 0 && r0 == 0 && r1 == 0) break;

        int player_1, player_2;
        player_1 = check_score(s0,s1);
        player_2 = check_score(r0,r1);
        if (player_1 == player_2)
            printf("Tie.\n");
        else if (player_1 > player_2)
            printf("Player 1 wins.\n");
        else 
            printf("Player 2 wins.\n");
    }
    return 0;
}
