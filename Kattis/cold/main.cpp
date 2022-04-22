#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
	while (scanf("%d",&N) != EOF) {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d",&temp);
			if (temp < 0)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
