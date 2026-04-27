#include <iostream>
using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;
    if(a%2 == 0 && b%2 != 0){
        cout << (b-a)/2+2;
    }else{
        cout << (b-a)/2+1;   
    }
}