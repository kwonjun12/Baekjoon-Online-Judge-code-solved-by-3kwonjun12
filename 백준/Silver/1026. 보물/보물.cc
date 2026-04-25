#include <stdio.h>
#include <stdlib.h>

int cmpu(const void* a, const void* b){
    return *(int*)a - *(int*)b; 
}

int cmpd(const void* a, const void* b){
    return *(int*)b - *(int*)a; 
}

int main(void){
   int n;
   scanf("%d", &n);
   int a[n];
   int b[n];
   for(int i = 0; i < n; i++){
       scanf("%d", &a[i]);
   } 
   for(int i = 0; i < n; i++){
       scanf("%d", &b[i]);
   } 
   qsort(a,n,sizeof(int),cmpu);
   qsort(b,n,sizeof(int),cmpd);
   int s = 0;
   for(int i = 0; i < n; i++){
       s += a[i]*b[i]; 
   } 
   printf("%d", s); 
}