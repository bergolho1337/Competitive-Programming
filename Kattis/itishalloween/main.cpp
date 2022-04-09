#include <bits/stdc++.h>

using namespace std;

int main () {
    int day;
	string month;
    while (cin >> month >> day) {
        if ((month == "OCT" && day == 31) ||\
            (month == "DEC" && day == 25))
            printf("yup\n");
        else
            printf("nope\n");
    }
    return 0;
}
