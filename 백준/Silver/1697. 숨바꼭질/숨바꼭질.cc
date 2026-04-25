#include <stdio.h>
#include <queue>
#define MAX 1000001

using namespace std;

typedef struct {
    int x, t;
} XandTime;

int n, k;
int visited[MAX];
queue<XandTime> que;

void BFS() {
    que.push({n, 0});
    visited[n] = 1;

    while (!que.empty()) {
        int x = que.front().x;
        int t = que.front().t;
        que.pop();
        if (x == k) {
            printf("%d", t);
            return;
        }
        if (x + 1 < MAX && !visited[x + 1]) {
            visited[x + 1] = 1;
            que.push({x + 1, t + 1});
        }
        if (x - 1 >= 0 && !visited[x - 1]) {
            visited[x - 1] = 1;
            que.push({x - 1, t + 1});
        }
        if (x * 2 < MAX && !visited[x * 2]) {
            visited[x * 2] = 1;
            que.push({x * 2, t + 1});
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &k);
    BFS();
}
