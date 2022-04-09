#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
    while (scanf("%d",&N) != EOF) {
        double ans = 0.0;
        double q, y;
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf",&q,&y);
            ans += (q*y);
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
