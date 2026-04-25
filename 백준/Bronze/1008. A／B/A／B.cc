#include <stdio.h>

int main(void){
    int A,B;
    scanf("%d %d", &A, &B);
    double ans = (double)A/(double)B;
    printf("%.9f", ans);
}