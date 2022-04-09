#include <bits/stdc++.h>

using namespace std;

int main () {
	int N, M;
    while (scanf("%d %d",&N,&M) != EOF) {
        int D = M-N;
        if (abs(D) == 1) {
            if (D > 0)
                printf("Dr. Chaz will have %d piece of chicken left over!\n",abs(D));
            else
                printf("Dr. Chaz needs %d more piece of chicken!\n",abs(D));
        }
        else {
            if (D > 0)
                printf("Dr. Chaz will have %d pieces of chicken left over!\n",abs(D));
            else
                printf("Dr. Chaz needs %d more pieces of chicken!\n",abs(D));
        }
        
    }
    return 0;
}
