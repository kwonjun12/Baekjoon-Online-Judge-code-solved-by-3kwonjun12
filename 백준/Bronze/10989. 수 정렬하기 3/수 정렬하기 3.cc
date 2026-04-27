#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    scanf("%d", &N);
    static int cnt[10001] = {0};   
    for (int i = 0; i < N; i++) {
        int x; 
        scanf("%d", &x);
        cnt[x]++;
    }
    setvbuf(stdout, NULL, _IOFBF, 1<<20);
    for (int v = 1; v <= 10000; v++) {
        while (cnt[v]--) {
            printf("%d\n", v);
        }
    }
}
