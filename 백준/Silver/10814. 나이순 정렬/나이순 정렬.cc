#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[101]; 
    int old;
} no;

int cmp(const void* a, const void* b) {
    no* x = (no*)a;
    no* y = (no*)b;
    return x->old - y->old;
}

int main(void) {
    int N;
    scanf("%d", &N);
    no arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &arr[i].old, arr[i].name);
    }
    qsort(arr, N, sizeof(no), cmp);
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", arr[i].old, arr[i].name);
    }
}
