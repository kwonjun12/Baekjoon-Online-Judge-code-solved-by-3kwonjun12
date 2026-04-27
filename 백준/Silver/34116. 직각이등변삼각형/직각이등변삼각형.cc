#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { 
    return a < b ? a : b; 
}
int max(int a, int b) { 
    return a > b ? a : b;
}

int n;
int x[100000], y[100000];

int calc(int ref) {
    int l = x[0] - abs(y[0] - ref);
    int r = x[0] + abs(y[0] - ref);
    for (int i = 1; i < n; i++) {
        int d = abs(y[i] - ref);
        l = min(l, x[i] - d);
        r = max(r, x[i] + d);
    }
    return r - l;
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);

    int mn = y[0], mx = y[0];
    for (int i = 1; i < n; i++) {
        if (y[i] < mn) mn = y[i];
        if (y[i] > mx) mx = y[i];
    }
    int an = min(calc(mn), calc(mx));
    printf("%d", an);
}
