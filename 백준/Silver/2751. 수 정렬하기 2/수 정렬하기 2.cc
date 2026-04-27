#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
} 

int main(void){
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), cmp);
    for(int i = 0; i < N; i++) printf("%d\n", arr[i]);
}    