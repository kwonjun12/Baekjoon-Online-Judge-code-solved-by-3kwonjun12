#include <stdio.h>

int max(int a,int b){
    return (a < b) ? b : a;
}

int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    int dp[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        dp[i] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
}