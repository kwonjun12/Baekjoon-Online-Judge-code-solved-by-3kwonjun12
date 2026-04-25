#include <stdio.h>

int main(void) {
    int t, n;
    scanf("%d", &t);
    int dp0[41], dp1[41];
    dp0[0] = 1; dp1[0] = 0; 
    dp0[1] = 0; dp1[1] = 1; 
    for (int i = 2; i <= 40; i++) {
        dp0[i] = dp0[i - 1] + dp0[i - 2];
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    }
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d %d\n", dp0[n], dp1[n]);
    }
    return 0;
}
