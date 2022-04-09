#include <bits/stdc++.h>

using namespace std;

int main () {
	int N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        char name[50];
        int ss_year, ss_month, ss_day;
        int birth_year, birth_month, birth_day;
        int courses_taken;
        scanf("%s %d/%d/%d %d/%d/%d %d",name,\
              &ss_year,&ss_month,&ss_day,\
              &birth_year,&birth_month,&birth_day,\
              &courses_taken);
        if (ss_year >= 2010)
            printf("%s eligible\n",name);
        else if (birth_year >= 1991)
            printf("%s eligible\n",name);
        else {
            if (courses_taken >= 41) {
                printf("%s ineligible\n",name);
            }
            else {
                printf("%s coach petitions\n",name);
            }
        }
    }
    return 0;
}
