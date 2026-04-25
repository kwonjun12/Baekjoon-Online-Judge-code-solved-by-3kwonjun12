#include <stdio.h>
#include <algorithm>
#define MAX 1000001

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int dp[MAX];
    for(int i = 1; i <= n; i++){
        dp[i] = i;
        for(int j = 1; j* j <= i; j++){
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
    }
    printf("%d", dp[n]);
}