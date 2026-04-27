#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 2000000001
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int bs = sqrt(n);
    int nums[n];
    vector<int>bls(n/bs+1, MAX);
    for(int i = 0; i < n; i++){
       cin >> nums[i];
       if(nums[i] < bls[i/bs]){
           bls[i/bs] = nums[i];
       }
    }
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        int left = a-1;
        int right = b-1;
        int ans = MAX;
        while(left <= right && left%bs != 0){
            if(nums[left] < ans){
                ans = nums[left];
            }    
            left++;
        }
        while(left+bs-1 <= right){
            if(bls[left/bs] < ans){
                ans = bls[left/bs];
            }
            left+=bs;
        }
        while(left <= right){
            if(nums[left] < ans){
                ans = nums[left];
            }
            left++;
        }
        cout << ans << "\n";
    }
}