#include <stdio.h>
int dp[1000001]; 

int dfs(int x) {
    if (x == 1) return 0;          
    if (dp[x] != 0) return dp[x];  
    int r = dfs(x - 1) + 1;      
    if (x % 2 == 0) {
        int t = dfs(x / 2) + 1;
        if (t < r) r= t;
    }
    if (x % 3 == 0) {
        int t = dfs(x / 3)+1;
        if (t <r) r = t;
    }
    return dp[x] = r;
}

int main(void) {
    int x;
    scanf("%d", &x);
    printf("%d", dfs(x));
}
