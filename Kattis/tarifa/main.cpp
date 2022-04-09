#include <bits/stdc++.h>

using namespace std;

int main () {
	int X;
    while (scanf("%d",&X) != EOF) {
        int N;
        int ans = X;
        scanf("%d",&N);
        for (int i = 0; i < N; i++) {
            int P;
            scanf("%d",&P);
            int extra = (ans-P);
            ans -= P;
            ans += X;
        }
        printf("%d\n",ans);
    }
    return 0;
}
