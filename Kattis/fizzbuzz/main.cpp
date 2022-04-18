#include <bits/stdc++.h>

using namespace std;

int main () {
	int X, Y, N;
    while (scanf("%d %d %d",&X,&Y,&N) != EOF) {
        for (int i = 1; i <= N; i++) {
            int flag = 0;
            if (i % X == 0)
                flag++;
            if (i % Y == 0)
                flag += 2;
            
            switch (flag) {
                case 0:
                    printf("%d\n",i);
                    break;
                case 1:
                    printf("Fizz\n");
                    break;
                case 2:
                    printf("Buzz\n");
                    break;
                case 3:
                    printf("FizzBuzz\n");
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
