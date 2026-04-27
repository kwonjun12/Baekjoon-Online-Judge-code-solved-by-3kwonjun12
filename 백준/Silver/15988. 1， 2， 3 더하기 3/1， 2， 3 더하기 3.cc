#include <stdio.h>

long long dp[1000000] = {0, 1, 2, 4};

int main(void){
   int t;
   scanf("%d", &t);
   int n[t];
   for(int i = 0; i < t; i++){
       scanf("%d", &n[i]);
       for(int j = 4; j <= n[i]; j++){
           dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1000000009; 
       }
       printf("%lld\n", dp[n[i]]);
   } 
}