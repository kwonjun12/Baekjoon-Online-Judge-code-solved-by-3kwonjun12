#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(void){
   int n;
   scanf("%d", &n);
   int a[n];
   int b[n]; 
   int p[n]; 
   int u[n];
   for(int i = 0; i < n; i++){
       scanf("%d", &a[i]);
       b[i] = a[i];
       u[i] = 0;
   } 
   qsort(b, n, sizeof(int), cmp);
   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           if(a[i] == b[j] && u[j] == 0){
               p[i] = j;
               u[j] = 1;
               break;
           }
       }
   }
   for(int i = 0; i < n; i++){
       printf("%d ", p[i]);
   }
}
