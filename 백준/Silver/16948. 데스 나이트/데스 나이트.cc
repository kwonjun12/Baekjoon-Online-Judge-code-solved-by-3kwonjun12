#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

typedef struct{
    int r,c;
}chess;

int n;
int ansl[201][201];
int visited[201][201];
chess a,b;
chess dxy[6] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};
queue<chess>q;

void BFS(int sr,int sc){
    q.push({sr, sc});
    visited[sr][sc] = 1;
    while(!q.empty()){
        int x = q.front().r;
        int y = q.front().c;
        q.pop();
        if(x == b.r && y == b.c){
            cout << ansl[x][y];
            return;
        }
        for(int i = 0; i < 6; i++){
            int nx = x+dxy[i].r;
            int ny = y+dxy[i].c;
            if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]){
                visited[nx][ny] = 1;
                ansl[nx][ny] = ansl[x][y]+1;
                q.push({nx, ny});
            }  
        }
    }
    cout << -1;
}

int main(void){
    cin >> n;
    cin >> a.r >> a.c;
    cin >> b.r >> b.c;
    BFS(a.r, a.c);
}