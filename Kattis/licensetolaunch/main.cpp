#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
    while (scanf("%d",&N) != EOF) {
        int ans = 0;
        int min_value = INT_MAX;
        for (int i = 0; i < N; i++) {
            int X;
            scanf("%d",&X);
            if (X < min_value) {
                ans = i;
                min_value = X;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
