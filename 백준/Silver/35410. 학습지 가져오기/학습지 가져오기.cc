#include <iostream>
#include <cstdlib>
using namespace std;

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   int t[n];
   for(int i = 0; i < n; i++){
       cin >> t[i];
   } 
   int p[1000] = {0,}; 
   for(int i = 0; i < n; i++){
       for(int j = 0; j < 1000; j++){
           if(t[i] == j+1){
               p[j]++;
           }
       }
   }
   qsort(t,n,sizeof(int),cmp);
   int ans = 0;
   for(int i = 0; i < n; i++){
       if(ans < t[i]){
           ans = t[i];
       }
       ans++;
   }
   cout << ans; 
}