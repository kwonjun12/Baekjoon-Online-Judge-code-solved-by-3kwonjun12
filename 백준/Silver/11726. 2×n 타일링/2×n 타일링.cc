#include <stdio.h>

int main(void){
    int dp[1001] = {0};
    dp[1] = 1; dp[2] = 2;
    int n;
    scanf("%d", &n);
    for (int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    printf("%d", dp[n]);
}