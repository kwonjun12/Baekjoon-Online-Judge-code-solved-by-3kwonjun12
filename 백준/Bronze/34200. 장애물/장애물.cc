#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++){
       cin >> x[i];
    }
    int l = x[n-1]+2;
    int p[l] = {0,};
    for(int i = 0; i < n; i++){
        p[x[i]] = 1;
    }
    int ans = 0;
    for(int i = 0; i < l-2;){
        if(p[i+1] == 1 && p[i+2] == 1){
            cout << "-1";
            return 0;
        }
        if(p[i+2] == 1){
            i++;
            ans++;
        }else{
            i+=2;
            ans++;
        }
    }
    cout << ans;
}