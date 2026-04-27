#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,j;
    cin >> n >> m >> j;
    int a[j];
    for(int i = 0; i < j; i++){
        cin >> a[i];
    }
    int ans = 0;
    int left = 0;
    int right = m-1;
    for(int i = 0; i < j; i++){
       int ta = a[i]-1;
       if(left > ta){
           int d = left-ta;
           left -= d;
           right -= d;
           ans+=d;
       }
       if(right < ta){
           int d = ta-right;
           left += d;
           right += d;
           ans+=d;
       }
    }
    cout << ans;
}