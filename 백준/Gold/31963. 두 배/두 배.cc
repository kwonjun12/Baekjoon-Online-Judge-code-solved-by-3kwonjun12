#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[1000001];
    int cnt[1000001];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int t;
    long long ans = 0;
    for(int i = 1; i < n; i++){
        double l = log2((double)a[i-1]/a[i]);
        t = ceil(l)+cnt[i-1];
        if(0 < t){
            cnt[i]=t;
        }
        ans += cnt[i];
    }
    cout << ans; 
}