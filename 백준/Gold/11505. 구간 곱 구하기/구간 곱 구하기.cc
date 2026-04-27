#include <iostream>
#define MOD 1000000007
using namespace std;

int n,m,k;
long long tree[4000001];
long long arr[1000001];

void mt(int node, int st, int en){
    if(st==en){
        tree[node] = arr[st];
        return;
    }
    int md = (st+en)/2;
    mt(node*2,st,md);
    mt(node*2+1,md+1,en);
    tree[node] = (tree[node*2]*tree[node*2+1])%MOD;
}

long long ud(int node, int st, int en, int i, long long c){
    if(i < st || i > en){
        return tree[node];
    }
    if (st == en){
        return tree[node]=c;
    }   
    int md = (st+en)/2;
    return tree[node] = (ud(node*2,st,md,i,c)*ud(node*2+1,md+1,en,i,c))%MOD;
}

long long q(int node, int st, int en, int left, int right){
    if(left > en || right < st){
        return 1;
    }
    if(left <= st && right >= en){
        return tree[node];
    }
    int md = (st+en)/2;
    return (q(node*2,st,md,left,right)*q(node*2+1,md+1,en,left,right))%MOD; 
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    mt(1,1,n);
    int l = m+k;
    int a,b;
    long long c;
    for(int i = 1; i <= l; i++){
       cin >> a >> b >> c;
       if(a == 1){
           arr[b] = c;
           ud(1,1,n,b,c);
       }else{
           cout << q(1,1,n,b,(int)c) << "\n";
       }
    }
}