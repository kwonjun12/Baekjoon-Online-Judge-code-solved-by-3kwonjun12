#include <stdio.h>

int main(void){
    long long n, o;
    scanf("%lld %lld", &n, &o);
    long long a[n];
    for(int i=0; i<n; i++) 
       scanf("%lld", &a[i]);
    int s = 0, b = n - 1, aa = n % 2;
    while(s <= b){
        if(aa == 1) 
            o = 2 * a[b--] - o;
        else 
            o = 2 * a[s++] - o;
        if(aa == 0) 
            aa = 1;
        else 
            aa = 0;
    }
    printf("%lld", o);
}