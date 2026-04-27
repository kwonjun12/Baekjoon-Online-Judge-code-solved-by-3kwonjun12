#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p, p+n);
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += p[i];
        ans += sum;
    }
    cout << ans;
}