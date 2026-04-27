#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int l = 2*n;
    int u = 0;
    int c = 1;
    int s = (n-1)*2+1;
    for(int i = 0; i < l; i++){
        int cnt = 0;
        for(int j = 0; j < l-1-i; j++){
            cout << " ";
            cnt++;
        }
        cout << "*";
        cnt++;
        if(i < n){
            for(int j = 0; j < n; j++){
                cout << " ";
                cnt++;
            }
        }else if(i==n){
            int fl = n+1;
            for(int j = 0; j < fl; j++){
                cout << " ";     
                cnt++;
            }
        }else{
            int fl = n+(c+=2);
            for(int j = 0; j < fl; j++){
                cout << " ";     
                cnt++;
            }
        }
        cout << "*" << " ";
        if(i < n){
            for(int j = 0; j < u; j++){
                cout << " ";
                cnt++;
            }
            u+=2;
        }else if(i==n){
            u-=2;
            for(int j = 0; j < u; j++){
                cout << " ";
                cnt++;
            }
        }else{
            u-=2;
            for(int j = 0; j < u; j++){
                cout << " ";
                cnt++;
            }
        }
        cout << "*";
        cnt++;
        int f = n*2+1+s;
        for(int j = 0; j < f-cnt; j++){
            cout << " ";
        }
        cout << "\n";
    }
}