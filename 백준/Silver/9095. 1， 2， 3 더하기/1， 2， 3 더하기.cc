#include <stdio.h>

int dp[12] = {0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 404};

int main(void){
   int t;
   scanf("%d", &t);
   int n[t];
   for(int i = 0; i < t; i++){
       scanf("%d", &n[i]);
       printf("%d\n", dp[n[i]]);
   } 
}