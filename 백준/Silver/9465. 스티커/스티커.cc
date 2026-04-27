#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int dp[2][n];
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &dp[i][j]);
            }
        }
        if (n > 1) {
            dp[0][1] += dp[1][0];
            dp[1][1] += dp[0][0];
        }
        for(int i = 2; i < n; i++){
            dp[0][i] += max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] += max(dp[0][i-1], dp[0][i-2]);
        }
        printf("%d\n", max(dp[0][n-1], dp[1][n-1]));
    }
}