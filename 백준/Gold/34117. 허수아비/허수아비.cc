#include <iostream>
#include <queue>
using namespace std;

int main(void){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n,p;
   cin >> n >> p;
   int a;
   long long cs = 0;
   priority_queue<int,vector<int>,greater<int>>pq;
   for(int i = 0; i < n; i++){
       cin >> a;
       cs += a;
       pq.push(a);
       while(!pq.empty() && cs - pq.top() >= p){
           cs -= pq.top();
           pq.pop();
       }
       if(cs < p){
           cout << "-1 ";
       }else{
          cout << pq.size() << " ";   
       }
   }
}