#include <bits/stdc++.h>

using namespace std;

int main () {
	int T;
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
        int curr, prev;
        int ans = 0;
        scanf("%d %d",&prev,&curr);
        while (curr > 0) {
            int diff = curr - (2*prev); 
            if (diff > 0) {
                ans += diff; 
            }
            prev = curr;
            scanf("%d",&curr);
        }
        printf("%d\n",ans);
    }
    return 0;
}
