#include <iostream>

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int compute_straight (int s[], const int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] >= (count+1)) {
            count++;
        }
    }
    return count;
}

int main () {
    int T;
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
        int N;
        scanf("%d",&N);
        int s[N];
        for (int i = 0; i < N; i++) {
            scanf("%d",&s[i]);
        }
        
        qsort(s,N,sizeof(int),compare);
        
        int ans = compute_straight(s,N);
        
        printf("Case #%d: %d\n",k+1,ans);
    }
    return 0;
}
