#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int n, m, ans;
int visited[MAX];
int ls[MAX];
queue<int> q;

void bfs(int n) {
    q.push(n);
    visited[n] = 1;
    while (!q.empty()) {
        int ps = q.front();
        q.pop();
        if (ps == 100) {
            cout << visited[ps] - 1;
            return;
        }
        for (int i = 1; i <= 6; i++) {
            int nps = i + ps;
            if (nps <= 100) {
                if (ls[nps] != 0) {
                    nps = ls[nps];
                }
                if (!visited[nps]) {
                    visited[nps] = visited[ps] + 1;
                    q.push(nps);
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int temp1, temp2;
    int loop = n + m;
    for (int i = 0; i < loop; i++) {
        cin >> temp1 >> temp2;
        ls[temp1] = temp2;
    }
    bfs(1);
}