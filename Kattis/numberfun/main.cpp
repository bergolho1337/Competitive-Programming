#include <bits/stdc++.h>

using namespace std;

bool test_operations (int a, int b, int c) {
    if (a+b == c) {
        //printf("Add %d+%d=%d\n",a,b,c);
        return true;
    }       
    else if (a-b == c) {
        //printf("Subtract %d-%d=%d\n",a,b,c);
        return true;
    }
    else if (a*b == c) {
        //printf("Multiply %d*%d=%d\n",a,b,c);
        return true;
    }
    else if (a/b == c && a % b == 0) {
        //printf("Division %d/%d=%d\n",a,b,c);
        return true;
    }
    else {
        return false;
    }
}

int main () {
	int N;
    int A, B, C;
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d",&A,&B,&C);
        bool order_1 = test_operations(A,B,C);
        bool order_2 = test_operations(B,A,C);
        //printf("\t%d %d\n",order_1,order_2);
        if (order_1 || order_2)
            printf("Possible\n");
        else
            printf("Impossible\n");
        //printf("\n");
    }
    return 0;
}
