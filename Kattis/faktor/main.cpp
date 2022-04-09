#include <bits/stdc++.h>

using namespace std;

int main (){
	int A, I;
    while (scanf("%d %d", &A, &I) != EOF) {
        int ans = ((--I)*A)+1;
        printf("%d\n",ans);
    }
    return 0;
}
