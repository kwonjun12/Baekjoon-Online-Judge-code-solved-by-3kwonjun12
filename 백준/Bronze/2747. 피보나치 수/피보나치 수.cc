#include <stdio.h>
int dp[46] = {0, 1, 1, 2}; 

int main(void){
   int n;
   scanf("%d", &n);
   for(int i = 4; i <= n; i++){
       dp[i] = dp[i - 1] + dp[i - 2];
   } 
   printf("%d", dp[n]); 
}