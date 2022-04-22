#include <bits/stdc++.h>

using namespace std;

bool check_flag (const int i, const int j, const int n) {
	int k = 0;
	int count = 0;
	while (count < n) {
		if (k % 2 == 0)
			count += i;
		else
			count += j;
		k++;
	}
	return (count == n) ? true : false; 
}

int main () {
	int N;
	while (scanf("%d",&N) != EOF) {
		printf("%d:\n",N);
		for (int i = 2; i <= (N/2)+1; i++) {
			for (int j = i-1; j < i+1; j++) {
				bool is_good = check_flag(i,j,N);
				if (is_good)
					printf("%d,%d\n",i,j);
			}
		}
	}
	return 0;
}
