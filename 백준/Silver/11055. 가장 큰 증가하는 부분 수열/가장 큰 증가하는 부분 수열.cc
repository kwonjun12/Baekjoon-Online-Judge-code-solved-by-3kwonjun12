#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n];
    int dp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = arr[i]; 
    }
    int max = dp[0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) { 
            if (arr[i] > arr[j]) { 
                if (dp[i] < dp[j] + arr[i]) {
                    dp[i] = dp[j] + arr[i];
                }
            }
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    printf("%d", max);
}