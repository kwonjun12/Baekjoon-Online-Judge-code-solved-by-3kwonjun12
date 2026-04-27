#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    cin >> n >> m;
    int t[1000001];
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    sort(t, t+n);
    int left = 1, mid, right = t[n-1], ans = 0;
    while(left <= right){
        mid = (left + right) / 2;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(t[i] - mid > 0) sum += (t[i] - mid);
        }
        if(sum >= m){
            ans = max(ans, mid);
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout << ans;
}