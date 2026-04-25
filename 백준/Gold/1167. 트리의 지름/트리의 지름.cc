#include <iostream>
#include <cstring>
#include <vector>
#define MAX 100001 
using namespace std;

typedef struct {
    int l, w;
}tree;

int v, fn, ans;
int visited[MAX];
vector<tree>nw[MAX];

void dfs(int n, int m) {
    visited[n] = 1; 
    if (m > ans) {
        ans = m;
        fn = n;
    }
    for (int i = 0; i < nw[n].size(); i++) {
        tree nn = nw[n][i];
        if (!visited[nn.l]) {
            dfs(nn.l, m+nn.w);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> v;
    int temp1, temp2, temp3;
    for (int i = 0; i < v; i++) {
        cin >> temp1;
        while (cin >> temp2 && temp2 != -1) { 
            cin >> temp3;
            nw[temp1].push_back({temp2, temp3});
        }
    }
    dfs(1, 0);
    ans = 0;
    memset(visited, 0, sizeof(visited));
    dfs(fn, 0);
    cout << ans;
}