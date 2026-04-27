#include <iostream>
#include <set>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    set<int>set;
    int t;
    while(n--){
        cin >> t;
        set.insert(t);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> t;
        if(set.find(t) != set.end()){
            cout << "1" << " ";
        }else{
            cout << "0" << " ";
        }
    }
}