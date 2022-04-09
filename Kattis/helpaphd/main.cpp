#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
    string line;
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        cin >> line;
        stringstream ss(line);
        string tmp;
        vector<string> tokens;
        while (getline(ss,tmp,'+')) {
            tokens.push_back(tmp);
        }
        if (tokens.size() == 1)
            printf("skipped\n");
        else {
            assert(tokens.size() == 2);
            int A = stoi(tokens[0]);
            int B = stoi(tokens[1]);
            printf("%d\n",A+B);
        }
    }
    return 0;
}
