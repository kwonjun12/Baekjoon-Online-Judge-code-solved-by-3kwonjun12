#include <stdio.h>

int max(int a, int b){
    return a < b? b : a; 
}

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n];
    int dp[n][2];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        dp[i][0] = arr[i];
        dp[i][1] = arr[i];
    }
    int ans = arr[0];
    for(int i = 1; i < n; i++){
       dp[i][0] = max(dp[i][0] + dp[i-1][0], dp[i][0]);
       dp[i][1] = max(dp[i-1][0], arr[i] + dp[i-1][1]); 
       ans = dp[i][0] > ans?dp[i][0] : ans;
    }
    int max1 = -1001;
    for(int i = 0; i < n; i++){
        max1 = max(max1, dp[i][1]);
    }
    ans = max(ans, max1);
    printf("%d", ans);
}