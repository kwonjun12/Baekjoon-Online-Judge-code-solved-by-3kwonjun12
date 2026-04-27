#include <iostream>
#include <cstdlib>
using namespace std;

int main(void){
    long long n,l;
    cin >> n >> l;
    long long x[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    long long jh[n];
    long long s = 0;
    for(int i = 0; i < n; i++){
        s += x[i];
        jh[i] = s;
    }
    for(int i = 1; i < n; i++){
        long long left = x[i-1]-l;
        long long right = x[i-1]+l;
        double c = (double)(jh[n-1]-jh[i-1])/(n-i);
        if(left >= c|| c >= right){
            cout << "unstable";
            return 0;
        }
    }
    cout << "stable";
}    
