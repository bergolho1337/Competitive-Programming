#include <bits/stdc++.h>

using namespace std;

int get_digits (const int x) {
    int counter = 0;
    int num = x;
    while (num > 0) {
        num /= 10;
        counter++;
    }
    return counter;
}

int solve_problem (string str) {
    int ans = 2;
    int prev_x = str.size();
    //int curr_x = (int)log10(prev_x)+1;    // Faster
    int curr_x = get_digits(prev_x);
    while (prev_x != curr_x) {
        //printf("%d %d\n",prev_x,curr_x);
        prev_x = curr_x;
        //curr_x = (int)log10(prev_x)+1;    // Faster
        curr_x = get_digits(prev_x);
        ans++;
    }
    return ans;
}

int main () {
	string str;
    while (cin >> str) {
        if (str == "END") break;
        if (str == "1") {
            printf("1\n");
            continue;
        }
        
        int ans = solve_problem(str);
        printf("%d\n",ans);
    }
    return 0;
}
