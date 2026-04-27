#include <iostream>
#include <algorithm>
#define MAX1 100001
#define MAX2 18
using namespace std;

int lg[MAX1];
int dpa[MAX1][MAX2];
int dpi[MAX1][MAX2];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        dpa[i][0] = num;
        dpi[i][0] = num;
    }
    for(int i = 2; i <= n; i++){
        lg[i] = lg[i/2]+1;
    }
    for(int i = 1; i < MAX2; i++){
        for(int j = 0; j + (1 << i) <= n; j++){
            dpi[j][i] = min(dpi[j][i-1], dpi[j + (1 << (i-1))][i-1]);
            dpa[j][i] = max(dpa[j][i-1], dpa[j + (1 << (i-1))][i-1]);
        }
    }
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        int left = a-1;
        int right = b-1;
        int k = lg[right-left+1];
        int ansi = min(dpi[left][k], dpi[right-(1 << k)+1][k]);
        int ansa = max(dpa[left][k], dpa[right-(1 << k)+1][k]);
        cout << ansi << " " << ansa << "\n";
    }
}