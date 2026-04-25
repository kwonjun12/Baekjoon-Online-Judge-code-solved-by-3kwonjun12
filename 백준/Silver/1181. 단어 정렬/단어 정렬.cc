#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    const char* A = (const char*)a;
    const char* B = (const char*)b;
    int lenA = strlen(A);
    int lenB = strlen(B);
    if (lenA == lenB)
        return strcmp(A, B);
    return lenA - lenB;
}

int main(void) {
    int N;
    scanf("%d", &N);
    char sArr[N][51];
    for (int i = 0; i < N; i++) {
        scanf("%s", sArr[i]);
    }
    qsort(sArr, N, sizeof(sArr[0]), cmp);
    printf("%s\n", sArr[0]);
    for (int i = 1; i < N; i++) {
        if (strcmp(sArr[i], sArr[i - 1]) != 0) {  
            printf("%s\n", sArr[i]);
        }
    }
}
