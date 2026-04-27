#include <stdio.h>
int a, b;

int f(long long n, int s){
    if(n == b){
        return s;
    }
    if(n > b){
        return -1;
    }
    int r = f(n*2, s+1);
    if(r != -1) return r;
    return f(n*10+1, s+1);
}

int main(void){
    scanf("%d%d", &a, &b);
    printf("%d", f(a,1));
}