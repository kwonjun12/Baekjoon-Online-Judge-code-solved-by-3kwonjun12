#include <iostream>
using namespace std;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n,m;
   cin >> n >> m;
   int arr[n+1] = {0,};
   cin >> arr[1];
   int t;
   for(int i = 2; i <= n; i++){
       cin >> t;
       arr[i] = arr[i-1] + t;
   }
   int f,l;
   for(int i = 0; i < m; i++){
       cin >> f >> l;
       cout << arr[l] - arr[f-1] << "\n";
   } 
}