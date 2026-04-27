#include <iostream>
#include <string>
using namespace std;
string tree[27][3];

void f1(string n){
    if(n == "."){
        return;
    }
    cout << n;
    f1(tree[n[0] - 'A'][1]);
    f1(tree[n[0] - 'A'][2]);
}
    
void f2(string n){
    if(n == "."){
        return;
    }
    f2(tree[n[0] - 'A'][1]);
    cout << n;
    f2(tree[n[0] - 'A'][2]);
}

void f3(string n){
    if(n == "."){
        return;
    }
    f3(tree[n[0] - 'A'][1]);
    f3(tree[n[0] - 'A'][2]);
    cout << n;
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a, b, c;
        cin >> a >> b >> c;
        int s = a[0] - 'A';
        tree[s][0] = a;
        tree[s][1] = b;
        tree[s][2] = c;
    }
    f1(tree[0][0]);
    cout << '\n';
    f2(tree[0][0]);
    cout << '\n';
    f3(tree[0][0]);
    cout << '\n';
}