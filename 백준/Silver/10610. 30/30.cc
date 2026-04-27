#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string n;
    cin >> n;
    int h0 = 0, sum = 0;
    for(char c : n){
        int t = c - '0';
        sum+=t;
        if(t == 0) h0=1;
    }
    if(h0 == 0 || sum % 3 != 0){
        cout << "-1";
        return 0;
    }
    sort(n.begin(), n.end(), greater<char>());
    cout << n;
}