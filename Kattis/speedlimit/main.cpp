#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
	while (scanf("%d",&N) != EOF) {
		if (N == -1) break;
		
		int ans = 0;
		int prev_t = 0;
		int v, t;
		for (int i = 0; i < N; i++) {
			scanf("%d %d",&v,&t);
			ans += v*(t-prev_t);
			prev_t = t;
		}
		printf("%d miles\n",ans);
	}
	return 0;
}
