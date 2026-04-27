#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int s[n+1];
    int dp[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d", &s[i]);
    }
    dp[1] = s[1];
    dp[2] = dp[1] + s[2];
    dp[3] = max(s[1]+s[3], s[2]+s[3]);
    for(int i = 4; i <= n; i++){
        dp[i] = max(dp[i-2]+s[i],dp[i-3]+s[i-1]+s[i]);
    }
    printf("%d", dp[n]);
}