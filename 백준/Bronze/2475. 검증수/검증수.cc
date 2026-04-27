#include <stdio.h>

int main(void){
    int n;
    int s = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d", &n);
        s += n*n;
    }
    printf("%d", s%10);
}