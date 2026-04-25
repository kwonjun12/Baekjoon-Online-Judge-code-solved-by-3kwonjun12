#include <stdio.h>

int a, b, x;
int arr[1001][1001] = {};
int visit[1001] = {}, visit2[1001] = {};

int dfs(int n) {
    if (visit[n]) return 0;
    visit[n] = 1;
    if (n != x) printf(" %d", n);

    for (int i = 1; i <= a; i++) {
        if (arr[n][i] == 1 && !visit[i]) {
            dfs(i);
        }
    }
    return 0;
}

int bfs(int start) {
    int q[1001], front = 0, rear = 0;
    q[rear++] = start;
    visit2[start] = 1;

    while (front < rear) {
        int cur = q[front++];
        if (cur != x) printf(" %d", cur);

        for (int i = 1; i <= a; i++) {
            if (arr[cur][i] == 1 && !visit2[i]) {
                visit2[i] = 1;
                q[rear++] = i;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d %d", &a, &b, &x);
    for (int i = 0; i < b; i++) {
        int t, s;
        scanf("%d %d", &t, &s);
        arr[t][s] = 1;
        arr[s][t] = 1;
    }
    printf("%d", x);
    dfs(x);
    
    printf("\n%d", x);
    bfs(x);
}
