#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int ans = 0;
    while(n >= 0){
       if (n % 5 == 0) {
            ans += n / 5;
            printf("%d", ans);
            return 0;
        }
        n-=3;
        ans++;
    }
    printf("-1");
}