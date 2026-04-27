#include <cstdio>
#include <cstdlib>
#include <queue>
#define MAX 101
using namespace std;

struct pos{
  int x,y;  
};

pos dxy[4] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    int ma[MAX][MAX];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &ma[j][i]);
        }
    }
    int visited[MAX][MAX] = {0,};
    queue<pos>q;
    q.push({0,0});
    visited[0][0] = 1;
    while(!q.empty()){
        pos xy = q.front();
        q.pop();
        int x = xy.x;
        int y = xy.y;
        if(x == m-1 && y == n-1){
            printf("%d",visited[x][y]);
        }
        for(int i = 0; i < 4; i++){
           int nx = x+dxy[i].x;
           int ny = y+dxy[i].y;
           if(0 <= nx && nx < m && 0 <= ny && ny < n && ma[nx][ny] == 1 &&!visited[nx][ny]){
               q.push({nx,ny});
               visited[nx][ny] = visited[x][y]+1;
           }
        }
    }
}