#include <bits/stdc++.h>

using namespace std;

int main () {
    int N;
    while (scanf("%d",&N) != EOF) {
        int P, R, F;
        for (int k = 0; k < N; k++) {
            scanf("%d %d %d",&P,&R,&F);

            int ans = 0;
            double p = P;
            while (p <= F) {
                p = floor(p*R);
                ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
