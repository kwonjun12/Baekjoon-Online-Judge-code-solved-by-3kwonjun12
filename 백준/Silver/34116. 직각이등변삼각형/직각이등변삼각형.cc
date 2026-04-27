#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int x,y;
}pos;

pos dots[100001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int maxy = INT_MIN, miny = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> dots[i].x;
        cin >> dots[i].y;
        maxy = max(maxy, dots[i].y);
        miny = min(miny, dots[i].y);
    }
    //a
    int btm1 = INT_MAX;
    int btm2 = INT_MAX;
    for(int i = 0; i < n; i++){
        btm1 = min(btm1, dots[i].y-dots[i].x);
        btm2 = min(btm2, dots[i].y+dots[i].x);
    }
    int dota = btm2-maxy;
    int dotb = maxy-btm1;               
    int ans1 = dotb-dota;  
    //cout << dota << " " << dotb << endl;
    //b
    btm1 = INT_MIN;
    btm2 = INT_MIN;
    for(int i = 0; i < n; i++){
        btm1 = max(btm1, dots[i].y+dots[i].x);
        btm2 = max(btm2, dots[i].y-dots[i].x);
    }
    dota = btm1-miny;
    dotb = miny-btm2;     
    //cout << dota << " " << dotb << endl;
    int ans2 = dota-dotb;
    cout << min(ans1,ans2);               
}