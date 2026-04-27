#include <stdio.h>
#define MOD 1000000000

int main(void){
    int n;
    scanf("%d", &n);
    long long dp[101][10] = {0,};
    for (int j = 1; j <= 9; j++) {
       dp[1][j] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
           if(j == 0){
              dp[i][j] = dp[i-1][1]%MOD;
           }else if(j == 9){
               dp[i][j] = dp[i-1][8]%MOD;
           }else{
               dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%MOD;
           } 
        }
    }
    long long ans = 0;
    for(int i = 0; i <= 9; i++){
        ans+=dp[n][i];
    }
    printf("%lld", ans%MOD);
}