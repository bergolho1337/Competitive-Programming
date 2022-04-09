#include <cstdio>
#include <cstdint>
#include <cmath>

int main () {
	double A, B;
    while (scanf("%lf %lf",&A,&B) != EOF) {
        double ans = fabs(A-B);
        printf("%.0lf\n",ans);
    }
    return 0;
}
