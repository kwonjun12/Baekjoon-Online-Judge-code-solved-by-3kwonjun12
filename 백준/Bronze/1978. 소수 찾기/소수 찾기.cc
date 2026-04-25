#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        int cnt = 0;
        for(int i = 1; i <= a; i++){
            if(a%i == 0) cnt++;
        }
        if(cnt == 2) ans++;
    }
    printf("%d", ans);
}