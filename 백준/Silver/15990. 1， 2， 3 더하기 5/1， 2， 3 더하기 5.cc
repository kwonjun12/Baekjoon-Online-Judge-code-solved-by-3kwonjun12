#include <stdio.h>
#define D 1000000009
int dp[100001][3];

int main(void){
    int t, n;
    dp[1][0] = dp[2][1] = dp[3][0] = dp[3][1] = dp[3][2] = 1;
    for(int i = 4; i < 100001; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % D;
        dp[i][1] = (dp[i-2][0] + dp[i-2][2]) % D;
        dp[i][2] = (dp[i-3][0] + dp[i-3][1]) % D;
    }
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        int ans = ((dp[n][0] + dp[n][1]) % D + dp[n][2]) % D;
        printf("%d\n", ans);
    }
}
