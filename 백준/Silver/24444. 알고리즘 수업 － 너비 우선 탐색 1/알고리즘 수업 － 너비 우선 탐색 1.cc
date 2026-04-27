#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 100001
using namespace std;

vector<int> graph[MAXN];
int visited[MAXN];
int ans[MAXN];

int main(void) {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    queue<int> q;
    int cnt = 1;
    q.push(r);
    visited[r] = 1;
    ans[r] = cnt++;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = 1;
                ans[next] = cnt++;
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        printf("%d\n", ans[i]);
    }    
}
