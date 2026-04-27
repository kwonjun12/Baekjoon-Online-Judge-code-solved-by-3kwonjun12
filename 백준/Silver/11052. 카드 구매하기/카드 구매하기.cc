#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int p[n + 1];
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + p[j]);
        }
    }
    
    printf("%d", dp[n]);
}