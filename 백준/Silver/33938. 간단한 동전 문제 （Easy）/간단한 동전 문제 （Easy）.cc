#include <iostream>
#include <queue>
#define O 2000
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    if(n == 0 && m != 0){
        cout << "-1";
        return 0;
    }
    if(m == 0){
        cout << "0";
        return 0;
    }
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    int visited[4001] = {0,};
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == m){
            cout << visited[v+O] << "\n";
            return 0;
        }
        for(int i = 0; i < n; i++){
            if(v+p[i]+O >= 0 && v+p[i]+O <= 4000){
                if(!visited[v+p[i]+O]){
                     q.push(v+p[i]);
                     visited[v+p[i]+O] = visited[v+O]+1;
                } 
            }    
        }
    }    
    cout << "-1";
}