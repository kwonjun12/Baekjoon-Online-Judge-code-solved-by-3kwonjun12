#include <stdio.h>

int min2(int a, int b){
    return a < b ? a : b;
}

int min3(int a, int b, int c){
    return min2(min2(a, b), c);
}

int main(void){
    int n;
    scanf("%d", &n);
    int dp[n+1][3];
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &dp[i][0], &dp[i][1], &dp[i][2]);
    }
    for(int i = 2; i <= n; i++){
        dp[i][0] += min2(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min2(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min2(dp[i-1][0], dp[i-1][1]);
    }
    printf("%d", min3(dp[n][0], dp[n][1], dp[n][2]));
}
