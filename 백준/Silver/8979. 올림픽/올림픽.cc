#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int c, g, s, b;  
} r;

int cmp(const void* a, const void* b){
    r* A = (r*)a;
    r* B = (r*)b;
    if (A->g != B->g) return B->g - A->g;
    if (A->s != B->s) return B->s - A->s;
    return B->b - A->b;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    r w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &w[i].c, &w[i].g, &w[i].s, &w[i].b);
    }
    qsort(w,n,sizeof(r),cmp);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (w[i].c == k) {
            for (int j = 0; j < i; j++) {
                if (w[j].g > w[i].g || 
                   (w[j].g == w[i].g && w[j].s > w[i].s) || 
                   (w[j].g == w[i].g && w[j].s == w[i].s && w[j].b > w[i].b)) {
                    ans++;
                }
            }
            printf("%d", ans);
            break; 
        }
    }
}