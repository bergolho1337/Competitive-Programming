#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
    scanf("%d",&N);
    for (int k = 0; k < N; k++) {
        int G;
        scanf("%d",&G);
        int gnomes[G];
        for (int i = 0; i < G; i++) {
            scanf("%d",&gnomes[i]);
        }
        int ans = 0;
        for (int i = 0; i < G-1; i++) {
            if (gnomes[i+1]-gnomes[i] != 1) {
                ans = i+2;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
