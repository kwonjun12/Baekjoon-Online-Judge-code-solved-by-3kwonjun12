#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(void){
    int n;
    scanf("%d", &n);
    if (n == 0) { 
        printf("0");
        return 0; 
    }
    int cp = (int)round(n * 0.15);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    long long sum = 0;
    for(int i = cp; i < n - cp; i++){
       sum += arr[i];
    }
    int d = n - 2* cp;
    printf("%d", (int)round((double)sum / d));
}
