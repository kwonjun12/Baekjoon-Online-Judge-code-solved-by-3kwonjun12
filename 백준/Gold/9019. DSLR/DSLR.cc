#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct{
    int v;
    string s;
}vs;

int visited[10001];

int d(int n){
    n *= 2;
    if(9999 < n) n %= 10000;
    return n;
}

int s(int n){
    if(n == 0) return 9999;
    return n-1;
}

int l(int n){
    n = (n % 1000) * 10 + n / 1000;
    return n;
}

int r(int n){
    n = (n / 10) + (n % 10) * 1000;
    return n;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,a,b;
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(visited, 0, sizeof(visited));
        queue<vs>q;
        cin >> a >> b;
        q.push({a,""});
        visited[a] = 1;
        while(!q.empty()){
            int c = q.front().v;
            string ans = q.front().s;
            q.pop();
            if(c == b){
                cout << ans << "\n";
                break;
            }
            int p;
            p = d(c);
            if(!visited[p]){
                q.push({p,ans+"D"});
                visited[p]=1;
            }
            p = s(c);
            if(!visited[p]){
                q.push({p,ans+"S"});
                visited[p]=1;
            }
            p = l(c);
            if(!visited[p]){
                q.push({p,ans+"L"});
                visited[p]=1;
            }
            p = r(c);
            if(!visited[p]){
                q.push({p,ans+"R"});
                visited[p]=1;
            }
        }
    }
}