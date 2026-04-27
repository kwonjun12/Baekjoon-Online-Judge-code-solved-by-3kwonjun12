#include <iostream>
#include <algorithm>
using namespace std;
int tree[10001][3];
int p[10001];
int max3[10001];
int min3[10001];
int x = 0; 

void iorder(int n, int d){
    if(n == -1){
        return;
    }    
    iorder(tree[n][1], d+1);
    ++x;
    if(min3[d] == 0){ 
        min3[d] = x;
    }    
    else{ 
        min3[d] = min(min3[d], x);
    }    
    max3[d] = max(max3[d], x);
    iorder(tree[n][2], d+1);
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
       int a, b, c;
       cin >> a >> b >> c;
       tree[a][0] = a;
       tree[a][1] = b;
       tree[a][2] = c;
       if (b != -1) p[b] = a;
       if (c != -1) p[c] = a;
    }
    int r = 0;
    for (int i = 1; i <= n; i++) {
       if (p[i] == 0) {
           r = i;
           break;
       }
    }    
    iorder(r, 1);
    int l = 0;
    int w = 0;
    for(int i = 1; i <= n; i++){
        if(min3[i] == 0){
            continue;
        }    
        int t = max3[i] - min3[i] + 1;
        if(t > w){
            w = t;
            l = i;
        }
    }
    cout << l <<" " << w;
}