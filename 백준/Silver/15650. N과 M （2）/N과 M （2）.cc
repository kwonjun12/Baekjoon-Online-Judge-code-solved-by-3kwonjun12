#include <iostream>
using namespace std;

int n,m;
int ans[10];

void dfs(int tn, int l){
    if(l == m){
       for(int i = 0; i < m; i++){
           cout << ans[i] << " ";
       }
       cout << "\n";
        return;
    }
    for(int i = tn+1; i <= n; i++){
        ans[l] = i;
        dfs(i, l+1);
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        ans[0] = i;
        dfs(i,1);
    }
}