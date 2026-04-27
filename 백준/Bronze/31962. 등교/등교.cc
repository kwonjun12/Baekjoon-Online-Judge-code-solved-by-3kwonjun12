#include <iostream>
using namespace std;

int main(void){
    int n,x;
    cin >> n >> x;
    int s[n], t[n];
    int c[n] = {0,};
    for(int i = 0; i < n; i++){
        cin >> s[i] >> t[i];
    }
    int pa = 0;
    for(int i = 0; i < n; i++){
        if(x >= s[i] + t[i]){
            c[i] = 1;
            pa++;
        }
    }
    if(pa == 0){
        cout << "-1";
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(c[i] == 1){
            if(ans < s[i]){
                ans = s[i];
            }
        }
    }
    cout << ans;
}