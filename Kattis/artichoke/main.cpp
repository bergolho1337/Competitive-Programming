#include <bits/stdc++.h>

using namespace std;

double calc_formula (const double p, const double a, const double b, const double c, const double d, const int k) {
    return p * ( sin(a*k+b) + cos(c*k+d) + 2.0 );
}

vector<double> calculate_prices (const double p, const double a, const double b, const double c, const double d, const int n) {
    vector<double> out;
    for (int i = 1; i <= n; i++) {
        double price = calc_formula(p,a,b,c,d,i);
        out.push_back(price);
    }
    return out;
}

int main () {
    int n;
    double a, b, c, d, p;
    while (scanf("%lf %lf %lf %lf %lf %d",&p,&a,&b,&c,&d,&n) != EOF) {
        vector<double> prices = calculate_prices(p,a,b,c,d,n);
        int curr = 0;
        double ans = 0;
        for (uint32_t i = 0; i < prices.size(); i++) {
            double diff = prices[curr]-prices[i];
            if (diff > ans)
                ans = diff;
            if (prices[i] > prices[curr])
                curr = i;
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
