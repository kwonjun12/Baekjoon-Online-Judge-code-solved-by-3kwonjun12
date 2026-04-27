#include <iostream>
#include <cstdlib>
using namespace std;

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k,c;
    cin >> n >> k >> c;
    int a[5001];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    qsort(a,n,sizeof(int),cmp);
    long long psum[5001];
    psum[0] = a[0];
    for(int i = 1; i < n; i++){
        psum[i] = a[i]+psum[i-1];
    }
    int l = n-k;
    for(int i = 1; i <= c; i++){
        int max = -1;
        int left = 0;
        int right = l-1;
        int mid = (left+right)/2;
        while(left<=right){
            mid = (left+right)/2;
            if(psum[mid] <= i){
                max = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        if(max == -1){
            cout << psum[k-1] << "\n";
        }else{
            cout << psum[max+k]-psum[max] << "\n";
        }
    }
}