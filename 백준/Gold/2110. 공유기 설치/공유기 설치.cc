#include <iostream>
#include <algorithm>
using namespace std;

int n,c;
int x[200001];

int is(int d){
    int cnt = 1;
    int li = x[0];
    for(int i = 1; i < n; i++){
        if(x[i] - li >= d){
            cnt++;
            li = x[i];
        }
    }
    return cnt >= c;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x, x+n);
    int left = 0, right = x[n-1] - x[0], ans = 0, mid = 0;
    while(left <= right){
        mid = (left + right)/2;
        if(is(mid)){
            ans = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout << ans;
}