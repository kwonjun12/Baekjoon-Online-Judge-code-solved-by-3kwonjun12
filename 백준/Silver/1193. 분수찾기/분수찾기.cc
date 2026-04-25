#include <iostream>
using namespace std;

int main(void){
    int x;
    cin >> x;
    int i = 1;
    while(x - i > 0) x -= i++;
    if(i%2) cout << i+1-x << "/" << x;
    else cout << x << "/" << i+1-x;
}