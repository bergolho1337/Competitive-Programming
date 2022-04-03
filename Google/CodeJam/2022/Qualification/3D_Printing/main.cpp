#include <iostream>
#include <algorithm>

int main () {
    int T;
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
        int printer_1[4], printer_2[4], printer_3[4];
        scanf("%d %d %d %d",&printer_1[0],&printer_1[1],&printer_1[2],&printer_1[3]);
        scanf("%d %d %d %d",&printer_2[0],&printer_2[1],&printer_2[2],&printer_2[3]);
        scanf("%d %d %d %d",&printer_3[0],&printer_3[1],&printer_3[2],&printer_3[3]);
    
        int min_printer[4];
        min_printer[0] = std::min(printer_1[0],std::min(printer_2[0],printer_3[0]));
        min_printer[1] = std::min(printer_1[1],std::min(printer_2[1],printer_3[1]));
        min_printer[2] = std::min(printer_1[2],std::min(printer_2[2],printer_3[2]));
        min_printer[3] = std::min(printer_1[3],std::min(printer_2[3],printer_3[3]));
    
        int sol_printer[4] = {0,0,0,0};
        const int sum_D = 1000000;
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += min_printer[i];
            if (sum >= sum_D) {
                sol_printer[i] = min_printer[i] - (sum - sum_D);
                break;
            }
            else {
                sol_printer[i] = min_printer[i];
            }
        }
        
        sum = sol_printer[0] + sol_printer[1] + sol_printer[2] + sol_printer[3];
        if (sum == sum_D)
            printf("Case #%d: %d %d %d %d\n",k+1,sol_printer[0],sol_printer[1],sol_printer[2],sol_printer[3]);
        else
            printf("Case #%d: IMPOSSIBLE\n",k+1);
        
    }
    return 0;
}
