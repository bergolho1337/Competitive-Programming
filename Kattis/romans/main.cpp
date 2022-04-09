#include <bits/stdc++.h>

using namespace std;

int main () {
	double X;
    while (scanf("%lf",&X) != EOF) {
        double ans = (1000.0*5280/4854)*X;
        printf("%1.0lf\n",ans);
    }
    return 0;
}
