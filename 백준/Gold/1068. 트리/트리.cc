#include <iostream>
#include <vector>
using namespace std;

int n;
int d;
int ans;
int root;
vector<int> t[51];

void dfs(int o){
    if(o == d) return;
    int cnt = 0;
    for(int i = 0; i < t[o].size(); i++){
        if(t[o][i] == d) continue;
        dfs(t[o][i]);
        cnt++;
    }
    if(cnt == 0) ans++;
}

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == -1) root = i;
        else t[temp].push_back(i);
    }
    cin >> d;
    dfs(root);
    cout << ans;
}
