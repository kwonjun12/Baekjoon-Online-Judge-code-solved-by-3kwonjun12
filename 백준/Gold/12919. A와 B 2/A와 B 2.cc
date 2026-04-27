#include <bits/stdc++.h>
using namespace std;

int cl;

int mk(string s, string t,int cnt){
    if(s==t){
        return 1;
    }
    if(cnt > cl){
        return 0;
    }
    string t1 = t;
    string t2 = t;
    int a = 0, b = 0;
    if(t1[0] == 'B'){
        t1.erase(0,1);
        reverse(t1.begin(), t1.end());
        a = mk(s, t1, cnt+1);
    }
    if(t2.back() == 'A'){
        t2.pop_back();
        b = mk(s,t2, cnt+1);
    }
    if(a == 0 && b == 0){
        return 0;
    }else{
        return 1;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    string t;
    cin >> s >> t;
    cl = t.length() - s.length();
    cout << mk(s,t,0);
}