#include <stdio.h>
#define D 1000000000

int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    int dp[n+1][k+1];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= k; j++){
        dp[0][j] = 1;
    }  
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % D;
        }
    }
    printf("%d", dp[n][k]);
}
