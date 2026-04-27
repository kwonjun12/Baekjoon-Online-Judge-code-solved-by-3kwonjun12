#include <stdio.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int coins[n];  
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (k >= coins[i]) {
            cnt += k / coins[i];
            k %= coins[i];
        }
    }
    printf("%d", cnt);
}
