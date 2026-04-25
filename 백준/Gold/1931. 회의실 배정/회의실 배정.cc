#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct{
   int s,e;
}se;

int cmp(const void* a, const void* b){
    if ((*(se*)a).e != (*(se*)b).e) {
        if ((*(se*)a).e > (*(se*)b).e)return 1;
        if ((*(se*)a).e < (*(se*)b).e)return -1;
    }
    if ((*(se*)a).s > (*(se*)b).s)return 1;
    if ((*(se*)a).s < (*(se*)b).s)return -1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    se arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].s >> arr[i].e; 
    }
    int ans = 0;
    int l = -1;
    qsort(arr,n,sizeof(se),cmp);
    for(int i = 0; i < n; i++){
        if(l <= arr[i].s){
            ans++;
            l = arr[i].e;
        }
    }
    cout << ans;
}