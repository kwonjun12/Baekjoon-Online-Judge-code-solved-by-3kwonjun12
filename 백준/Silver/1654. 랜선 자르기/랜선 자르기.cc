#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k,n;
    cin >> k >> n;
    int lc[k];
    long long m = 0;
    for(int i = 0; i < k; i++){
        cin >> lc[i];
        m = (m < lc[i] ? lc[i] : m);
    }
    sort(lc, lc+k);
    long long left = 1, mid, right = m, ans = 0;
    while(left <= right){
        mid = (left + right) / 2;
        long long cnt = 0;
        for(int i = 0; i < k; i++){
            cnt += lc[i] / mid;
        }
        if(cnt >= n){
            left = mid+1;
            ans = max(ans, mid);
        }    
        else right = mid-1;
    }
    cout << ans;
}