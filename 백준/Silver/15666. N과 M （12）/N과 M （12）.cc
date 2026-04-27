#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
int ans[10];

void dfs(int tn, int l){
    if(l == m){
       for(int i = 0; i < m; i++){
           cout << ans[i] << " ";
       }
       cout << "\n";
        return;
    }
    int la = 0;
    for(int i = tn; i < n; i++){
        if(arr[i] == la) continue;
        ans[l] = la = arr[i];
        dfs(i, l+1);
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
        dfs(0,0);
        return 0;
    }
}