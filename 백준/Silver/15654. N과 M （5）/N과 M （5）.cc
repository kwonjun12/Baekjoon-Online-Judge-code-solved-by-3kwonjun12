#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
int ans[10];
bool v[10];

void dfs(int l){
    if(l == m){
       for(int i = 0; i < m; i++){
           cout << ans[i] << " ";
       }
       cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(v[i]) continue;
        v[i] = 1;
        ans[l] = arr[i];
        dfs(l+1);
        v[i] = 0;
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
       cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        ans[0] = arr[i];
        sort(arr, arr + n);
        dfs(0);
        return 0;
    }
}