#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    return *(int*)b - *(int*)a;   
}

int main(void){
    int N;
    scanf("%d", &N);
    int n = N;
    int len = 0;
    while(n > 0){
        len++;
        n /= 10;
    }
    int arr[len];
    for(int i = 0; i < len; i++){
        arr[i] = N % 10;  
        N /= 10;
    }
    qsort(arr, len, sizeof(int), cmp);
    for(int i = 0; i < len; i++){
        printf("%d", arr[i]);
    }
}
