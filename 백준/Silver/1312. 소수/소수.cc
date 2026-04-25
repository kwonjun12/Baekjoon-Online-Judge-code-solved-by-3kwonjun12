#include<iostream>
using namespace std;

int main(void){
    int a,b,n;
    cin >> a >> b >> n;
    int ans;
    for(int i = 0; i < n; i++){
        a%=b;
        a*=10;
        ans = a/b;
    }
    cout << ans;
}