#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int s = 0;
    int m;
    cin >> m;
    string c;
    int n;
    while(m--){
        cin >> c;
        if(c == "add"){
            cin >> n;
            s |= (1 << n);
        } else if(c == "remove"){
            cin >> n;
            s &= ~(1 << n);
        } else if(c == "check"){
            cin >> n;
            cout << ((s & (1 << n)) ? 1 : 0) << '\n';
        } else if(c == "toggle"){
            cin >> n;
            s ^= (1 << n);
        } else if(c == "all"){
            s = (1 << 21) - 1;
        }else{
            s = 0;
        }
    }
}