#include <bits/stdc++.h>

using namespace std;

int main () {
	int N, D;
	while (scanf("%d %d",&N,&D) != EOF) {
		bool flag = true;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int d;
			scanf("%d",&d);
			if (d > D && flag)
				ans++;
			else
				flag = false;
		}
		if (ans == N)
			printf("It had never snowed this early!\n");
		else
			printf("It hadn't snowed this early in %d years!\n",ans);
	}
	return 0;
}
