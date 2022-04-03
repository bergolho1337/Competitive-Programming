#include <iostream>

void print_ascii_art (const int R, const int C) {
    int n = R*2 + 1;
    int m = C*2 + 1;
    char *grid = new char[n*m]();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    grid[i*m+j] = '+';
                    //printf("+");
                }    
                else {
                    grid[i*m+j] = '-';
                    //printf("-");
                }
            }
            else {
                if (j % 2 == 0) {
                    grid[i*m+j] = '|';
                    //printf("|");
                }    
                else {
                    grid[i*m+j] = '.';
                    //printf(".");
                }
            }
        }
    }
    
    grid[0] = '.';
    grid[1] = '.';
    grid[m] = '.';
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c",grid[i*m+j]);
        }
        printf("\n");
    }
    
    delete [] grid;
}

int main () {
    
    int T, R, C;
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
        scanf("%d %d",&R,&C);
        printf("Case #%d:\n",k+1);
        print_ascii_art(R,C);
    }
    return 0;
}
