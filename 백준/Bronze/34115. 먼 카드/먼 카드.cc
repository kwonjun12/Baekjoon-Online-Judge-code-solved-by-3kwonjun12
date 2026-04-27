#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int x[2*n];
    int ans[n];
    int visited[n]; 
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        visited[i] = 0;
    }
    for (int i = 0; i < 2 * n; i++) {
        int num = x[i];
        if (!visited[num - 1]) {
            visited[num - 1] = 1;
            int j = i + 1;
            while (j < 2 * n && x[j] != num) {
                ans[num - 1]++;
                j++;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] > max) {
            max = ans[i];
        }
    }
    printf("%d", max);
}