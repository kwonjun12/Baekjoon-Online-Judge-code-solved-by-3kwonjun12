#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define MAXN 101
using namespace std;

typedef struct {
    int x, y;
} xy;

typedef struct {
    int x, y;
    char c;
} paint;

int n;
int ans;
int visited[MAXN][MAXN];
xy dxy[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
char p[MAXN][MAXN];
queue<paint> q;

void bfs(int x, int y, char c) {
    q.push({x, y, c});
    visited[x][y] = 1;
    while (!q.empty()) {
        paint l = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = l.x + dxy[i].x;
            int ny = l.y + dxy[i].y;
            if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && p[nx][ny] == l.c) {
                visited[nx][ny] = 1;
                q.push({nx, ny, l.c});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j, p[i][j]);
                ans++;
            }
        }
    }
    cout << ans << " ";
    ans = 0;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(p[i][j] == 'R'){
                p[i][j] = 'G';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j, p[i][j]);
                ans++;
            }
        }
    }
    cout << ans;
}