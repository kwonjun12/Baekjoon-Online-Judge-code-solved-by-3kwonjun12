#include <stdio.h>
#define MAX 1000000

int min(int a, int b){
    return a < b ? a : b;
}

int main(void){
    int n;
    scanf("%d", &n);
    int dp[n+1][3];
    int c[n+1][3];
    int ans = MAX;
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &c[i][0], &c[i][1], &c[i][2]);
    }
    for(int i = 0; i < 3; i++){
       for(int j = 0; j < 3; j++){
           if(i == j){
               dp[1][j] = c[1][j];
           }   
           else{
               dp[1][j] = MAX;
           }    
       }   
       for(int j = 2; j <= n; j++){
           dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + c[j][0];
           dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + c[j][1];
           dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + c[j][2];
       }
       for(int j = 0; j < 3; j++){
           if(i != j){
               ans = min(ans, dp[n][j]);
           }    
       }  
    }
    printf("%d", ans);
}