#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
}xy;

int cmp(const void* a, const void* b) {
    xy* pa = (xy*)a;
    xy* pb = (xy*)b;
    if (pa->x == pb->x) return pa->y - pb->y;
    else return pa->x - pb->x;
}

int main(void) {
    int N;
    scanf("%d", &N);
    xy arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, N, sizeof(xy), cmp);
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
}
