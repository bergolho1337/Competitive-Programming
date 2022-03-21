#include <iostream>
#include <string>
#include <cctype>

bool isVowel (const char c) {
    return (c == 'a' || c == 'e' \
            || c == 'i' || c == 'o' || c == 'u');
}

int main () {
    int T;
    std::string kingdom_name;
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
        std::cin >> kingdom_name;
        char last_letter = tolower(kingdom_name.back());
        if (isVowel(last_letter)) {
            printf("Case #%d: %s is ruled by Alice.\n",\
                        k+1,kingdom_name.c_str());
        }
        else {
            if (last_letter == 'y')
                printf("Case #%d: %s is ruled by nobody.\n",\
                        k+1,kingdom_name.c_str());
            else
                printf("Case #%d: %s is ruled by Bob.\n",\
                        k+1,kingdom_name.c_str());
        }
    }
    return 0;
}
