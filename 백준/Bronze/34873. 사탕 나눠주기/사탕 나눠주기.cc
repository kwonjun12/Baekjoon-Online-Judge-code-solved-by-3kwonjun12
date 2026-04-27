#include <iostream>
#include <set>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int n2 = 2*n;
    int c[n2];
    for(int i = 0; i < n2; i++){
       cin >> c[i];
    }
    set<int>s1;
    set<int>s2;
    int p1;
    int p2;
    for(int i = 0; i < n; i++){
       p1 = c[i];
       p2 = c[n2 - i-1];
       if(s1.count(p1)&&s2.count(p1)){
           cout << "No";
           return 0;
       }
       if(s1.count(p2)&&s2.count(p2)){
           cout << "No";
           return 0;
       }
       if(s1.find(p1) == s1.end()) s1.insert(p1);
       else if (s2.find(p1) == s2.end()) s2.insert(p1);
       else{
           cout << "No";
           return 0;
       }
       if(s1.find(p2) == s1.end()) s1.insert(p2);
       else if (s2.find(p2) == s2.end()) s2.insert(p2);
       else{
           cout << "No";
           return 0;
       } 
    }    
    cout << "Yes";
}