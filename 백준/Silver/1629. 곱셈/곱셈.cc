#include <iostream>
using namespace std;

long long a,b,c;

long long f(long long b){
    if(b == 1) return a%c;
    long long ta = f(b/2)%c;
    if(b%2==0)return ta*ta%c;
    return (((ta*ta)%c)*a)%c;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << f(b);
}