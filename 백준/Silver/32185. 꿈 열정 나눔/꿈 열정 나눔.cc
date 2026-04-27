#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct{
    long long a,b;
}ab;

bool cmp(ab x, ab y) {
    return x.a > y.a;
}

int main(void){
    int n,m;
    cin >> n >> m;
    int z1, z2, z3;
    cin >> z1 >> z2 >> z3;
    long long s;
    s = z1+z2+z3;
    int t1, t2, t3;
    cout << 0 << "";
    vector<ab>ci;
    for(int i = 1; i <= n; i++){
        long long t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        long long cs = t1 + t2 + t3;
        if(s >= cs){
             ci.push_back({cs, i});
        }
    }
    sort(ci.begin(), ci.end(), cmp);
    int cnt = min((int)ci.size(), m - 1); 
    for (int i = 0; i < cnt; i++) {
        cout << " " << ci[i].b;
    }
}