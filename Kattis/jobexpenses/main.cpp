#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
	while (scanf("%d",&N) != EOF) {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int value;
			scanf("%d",&value);
			if (value < 0)
				ans -= value;
		}
		printf("%d\n",ans);
	}
	return 0;
}
