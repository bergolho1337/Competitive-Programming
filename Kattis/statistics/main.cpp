#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
    int K = 1;
    while (scanf("%d",&N) != EOF) {
        int min_value = INT_MAX;
        int max_value = INT_MIN;
        for (int i = 0; i < N; i++) {
            int X;
            scanf("%d",&X);
            if (X < min_value) min_value = X;
            if (X > max_value) max_value = X;
        }
        int range_value = max_value - min_value;
        printf("Case %d: %d %d %d\n",K,min_value,max_value,range_value);
        K++;
    }
    return 0;
}
