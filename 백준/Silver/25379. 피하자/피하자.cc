#include <stdio.h>

long long min(long long a, long long b){
    return (a < b) ? a : b;
}

int main(void){
    int N;
    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    long long ce = 0;
    long long cL = 0, cR = 0;

    for(int i = 0; i < N; i++){
        if(!(A[i] % 2)){ 
            cL += i;           
            cR += (N - 1 - i); 
            ce++;
        }
    }
    long long tr = ce * (ce - 1) / 2;
    printf("%lld", min(cL - tr, cR - tr));
}
