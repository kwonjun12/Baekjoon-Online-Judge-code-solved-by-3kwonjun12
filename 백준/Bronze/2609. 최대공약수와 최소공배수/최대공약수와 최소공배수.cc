#include <stdio.h>

int main(void){
    int a,b;
    scanf("%d%d", &a, &b);
    int a1 = a;
    int b1 = b;
    int t;
    while(b1 > 0){
        t = a1 % b1;
        a1 = b1;
        b1 = t;
    }
    int l = a*b/a1;
    printf("%d\n%d", a1, l);
}