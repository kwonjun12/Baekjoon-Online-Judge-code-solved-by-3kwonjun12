#include <stdio.h>
#define D 9901

int main(void){
    int n;
    scanf("%d", &n);
    int dp[n+1][3];
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i = 2; i <= n; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%D;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%D;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%D;
    }
    int ans = (dp[n][0] + dp[n][1] + dp[n][2])%D;
    printf("%d", ans);
}