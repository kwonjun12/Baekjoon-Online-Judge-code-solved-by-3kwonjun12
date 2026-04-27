#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
   return *(int*)b - *(int*)a; 
}

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n];
    int ans = 0;
    for(int i = 0; i < n; i++){
       scanf("%d", &arr[i]); 
    }
    qsort(arr, n, sizeof(int), cmp);
    for(int i = 0; i < n; i++){
        if((i+1) % 3 != 0){
            ans += arr[i];
        }
    }
    printf("%d", ans);
}