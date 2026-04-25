#include <stdio.h>

int max(int a, int b){
    return a < b? b : a; 
}

int main(void){
    int n;
    scanf("%d", &n);
    int dp[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &dp[i]);
    }
    int ans = dp[0]; 
    for(int i = 1; i < n; i++){
       dp[i] = max(dp[i] + dp[i-1], dp[i]);
       ans = dp[i] > ans?dp[i] : ans;
    }
    printf("%d", ans);
}