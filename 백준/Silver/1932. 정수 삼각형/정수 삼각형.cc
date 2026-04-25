#include <stdio.h>
#define MAX 501

int max(int a, int b){
    return a > b ? a : b;
}

int n;
int trg[MAX][MAX];     
int dp[MAX][MAX];      

int solve(int i, int j){
    if (i >= n || j > i) return 0;
    if (dp[i][j] != 0) return dp[i][j];
    dp[i][j] = trg[i][j] + max(solve(i+1, j), solve(i+1, j+1));
    return dp[i][j];
}

int main(void){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &trg[i][j]);
        }
    }
    printf("%d", solve(0, 0));
}
