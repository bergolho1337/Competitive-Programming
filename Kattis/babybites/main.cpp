#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
    while (scanf("%d",&N) != EOF) {
        string str;
        bool flag = true;
        for (int i = 0; i < N; i++) {
            cin >> str;
            if (str != "mumble" && stoi(str) != i+1) {
                flag = false;
            }
        }
        if (flag)
            printf("makes sense\n");
        else
            printf("something is fishy\n");
    }
    return 0;
}
