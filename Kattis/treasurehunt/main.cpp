#include <bits/stdc++.h>

using namespace std;

bool in_bounds (const int i, const int j, const int R, const int C) {
    return ((i >= 0 && i < R) && (j >= 0 && j < C));
}

int main () {
	int R, C;
    while (scanf("%d %d",&R,&C) != EOF) {
        char grid[R][C];
        bool visit[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf(" %c ",&grid[i][j]);
                visit[i][j] = false;
            }
        }
        int curr_i = 0, curr_j = 0;
        int next_i, next_j;
        int num_steps = 0;
        while (!visit[curr_i][curr_j]) {
            
            if (grid[curr_i][curr_j] == 'T') {
                printf("%d\n",num_steps);
                break;
            }
            
            visit[curr_i][curr_j] = true;
            int letter = grid[curr_i][curr_j];
            switch (letter) {
                case 'N': {
                    next_i = curr_i - 1;
                    next_j = curr_j;
                    break;
                }
                case 'S': {
                    next_i = curr_i + 1;
                    next_j = curr_j;
                    break;
                }
                case 'E': {
                    next_i = curr_i;
                    next_j = curr_j + 1;
                    break;
                }
                case 'W': {
                    next_i = curr_i;
                    next_j = curr_j - 1;
                    break;
                }
                case 'T': {
                    next_i = curr_i;
                    next_j = curr_j;
                    break;
                }
            }

            if (!in_bounds(next_i,next_j,R,C)) {
                printf("Out\n");
                break;
            }
            
            curr_i = next_i;
            curr_j = next_j;
            num_steps++;
        }

        if (visit[curr_i][curr_j] && in_bounds(next_i,next_j,R,C)) {
            printf("Lost\n");
        }
    }
    return 0;
}
