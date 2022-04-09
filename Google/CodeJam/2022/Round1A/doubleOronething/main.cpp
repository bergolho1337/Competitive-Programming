#include <bits/stdc++.h>

using namespace std;

// CODEJAMDAY
//     |
string solve_problem (string s) {
    string out = "";
    for (uint32_t i = 0; i < s.size(); i++) {
        bool duplicate = false;
        for (uint32_t j = i+1; j < s.size(); j++) {
            // Duplicate the letter 'i' will not alter the lexicographic order
            if (s[j] > s[i]) {
                duplicate = true;
                break;
            }
            else if (s[j] < s[i]) {
                break;
            }
            // Otherwise, just keep going ...
        }
        out += s[i];
        if (duplicate)
            out += s[i];
    }
    return out;
}

int main () {
    int T;
    string str;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cin >> str;
        string ans = solve_problem(str);
        cout << "Case #" << k << ": " << ans << endl;
    }

    return 0;
}
