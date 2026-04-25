#include <bits/stdc++.h>
using namespace std;

int change(int v){
    return (v==0?1:0); 
}

int dx[9]={0,0,0,1,1,1,2,2,2};
int dy[9]={0,1,2,0,1,2,0,1,2};

int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[51][51];
    int b[51][51];
    for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
          scanf("%1d", &a[i][j]);     
       }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           scanf("%1d", &b[i][j]);     
        }
    }
    int cnt = 0;
    for(int i = 0; i <= n-3; i++){
       for(int j = 0; j <= m-3; j++){
           if(a[i][j] != b[i][j]){
               for(int k = 0; k < 9; k++){
                  a[i+dx[k]][j+dy[k]] = change(a[i+dx[k]][j+dy[k]]);
               }
               cnt++;
           }    
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != b[i][j]){
                cout << "-1";
                return 0;
            }
        }
    }
    cout << cnt;
}