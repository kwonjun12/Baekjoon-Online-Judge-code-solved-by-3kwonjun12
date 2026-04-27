#include <stdio.h>
#include <limits.h>
#define MAX_N 1001 
#define INF 10000001 

int p[MAX_N];
int dp[MAX_N];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j] + p[j]);
        }
    }
    printf("%d", dp[n]);
}