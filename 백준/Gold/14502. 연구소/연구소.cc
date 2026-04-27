#include <iostream>
#include <queue>
#include <cstdlib>
#define MAX 8
using namespace std;

typedef struct{
    int x,y;
}co;

int n,m;
int l[MAX][MAX];
int lc[MAX][MAX];
co dxy[4] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<co>q;

int bfs(void){
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
          if(lc[i][j] == 2){
              q.push({i,j}); 
          }
      }
   }  
   while(!q.empty()){
       int x = q.front().x;
       int y = q.front().y;
       q.pop();
       for(int i = 0; i < 4; i++){
           int dx = x+dxy[i].x;
           int dy = y+dxy[i].y;
           if(dx >= 0 && dx < n && dy >= 0 && dy < m){
               if(lc[dx][dy] == 0){
                   lc[dx][dy] = 2;
                   q.push({dx,dy});
               }
           }
       }
   } 
   int r = 0;
   for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
           if(lc[i][j] == 0){
              r++;  
           }
       }
   }
   return r;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> l[i][j];
            lc[i][j] = l[i][j];
        }
    }
    int max = -1;
    for(int i = 0; i < n*m; i++){
        for(int j = i+1; j < n*m; j++){
            for(int k = j+1; k < n*m; k++){
                int x1 = i / m; int y1 = i % m;
                int x2 = j / m; int y2 = j % m;
                int x3 = k / m; int y3 = k % m;
                if(l[x1][y1] == 0 && l[x2][y2] == 0 && l[x3][y3] == 0){
                    l[x1][y1] = 1; 
                    l[x2][y2] = 1;
                    l[x3][y3] = 1;
                    for(int i = 0; i < n; i++){
                        for(int j = 0; j < m; j++){
                            lc[i][j] = l[i][j];
                        }
                    }
                    int r = bfs();
                    max = (max < r ? r : max);
                    l[x1][y1] = 0; 
                    l[x2][y2] = 0;
                    l[x3][y3] = 0;
                }
            }
        }
    }
    cout << max;
}