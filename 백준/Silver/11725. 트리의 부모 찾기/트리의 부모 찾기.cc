#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int n;
int ans[MAX];
int visited[MAX];
vector<int>nodes[MAX];

void dfs(int n){
    visited[n] = 1;
    for(int i = 0; i < nodes[n].size(); i++){
        int node = nodes[n][i];
        if(!visited[node]){
            ans[node] = n;
            dfs(node);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int temp1, temp2;
    for(int i = 0; i < n - 1; i++){
        cin >> temp1 >> temp2;
        nodes[temp1].push_back(temp2);
        nodes[temp2].push_back(temp1);
    }
    dfs(1);
    for(int i = 2; i <= n; i++){
        cout << ans[i] << "\n";
    }
}