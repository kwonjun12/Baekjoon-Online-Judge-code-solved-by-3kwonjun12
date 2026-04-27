#include <iostream>
#include <algorithm>
#include <vector>
#define INT_MAX 2147483647
using namespace std;

int n,m;
long long a[100001];
vector<pair<int,int>>tree(400001);

void mt(int node, int st, int en){
    if(st==en){
        tree[node].first =a[st];
        tree[node].second = st;
        return;
    }
    int md = (st+en)/2;
    mt(node*2,st,md);
    mt(node*2+1,md+1,en);
    tree[node] = min(tree[node*2],tree[node*2+1]);
}

void ud(int node, int st, int en, int i, int c){
    if(i < st || i > en){
        return;
    }
    if(st==en){
        tree[node].first = c;
        return;
    }    
    int md = (st+en)/2;
    if(st != en){
        ud(node*2,st,md,i,c);
        ud(node*2+1,md+1,en,i,c);
    }
    tree[node]=min(tree[node*2],tree[node*2+1]);
}

pair<int, int> q(int node, int st, int en, int left, int right){
    if(left > en || right < st){
        return {INT_MAX, INT_MAX};
    }
    if(left <= st && right >= en){
        return tree[node];
    }
    int md = (st+en)/2;
    return min(q(node*2,st,md,left,right),q(node*2+1,md+1,en,left,right));
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> m;
    int ia,b,c;
    mt(1,1,n);
    for(int i = 1; i <= m; i++){
        cin >> ia;
        if(ia == 1){
            cin >> b >> c;
            a[b] = c;
            ud(1,1,n,b,c);
        }else{
            cout << q(1,1,1,1,n).second << "\n";
        }
    }
}
