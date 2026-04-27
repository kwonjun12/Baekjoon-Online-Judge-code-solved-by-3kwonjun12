#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int n,k;
    scanf("%d%d", &n, &k);
    int w[101];
    int v[101];
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &w[i], &v[i]);
    }
    int dp[101][100001];
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= k; i++) dp[0][i] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j < w[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d", dp[n][k]);
}
