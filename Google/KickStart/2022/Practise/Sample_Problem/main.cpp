#include <iostream>

int main () {
    int T;
    int N, M;
    int C;
    
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
        scanf("%d %d",&N,&M);
        int total_candies = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d",&C);
            total_candies += C;
        }
        int ans = total_candies % M;
        printf("Case #%d: %d\n",k+1,ans);
    }
    return 0;
}
