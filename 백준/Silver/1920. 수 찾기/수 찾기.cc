#include <stdio.h>
#include <stdlib.h>

int qcmp(const void* a, const void* b){
    int ia = *(int*)a;
    int ib = *(int*)b;
    if (ia < ib) return -1;
    else if (ia > ib) return 1;
    else return 0;
}

int bcmp(const void* a, const void* b){
    int ia = *(int*)a;
    int ib = *(int*)b;
    if (ia < ib) return -1;
    else if (ia > ib) return 1;
    else return 0;
}

int main(void){
    int N, M;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    int C[M];
    for (int i = 0; i < M; i++) {   
        scanf("%d", &C[i]);
    }
    qsort(A, N, sizeof(int), qcmp);
    for (int i = 0; i < M; i++) {
        int *found = (int *)bsearch(&C[i], A, N, sizeof(int), bcmp);
        if (found != NULL)
            printf("1\n");
        else
            printf("0\n");
    }
}