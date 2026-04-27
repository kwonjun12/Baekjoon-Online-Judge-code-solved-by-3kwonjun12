#include <bits/stdc++.h>
using namespace std;

int stu(int v){
    return (v==0?1:0);
}

int main(void){
    int n;
    cin >> n;
    int a1[100001];
    int a2[100001];
    int c[100001];
    for(int i = 0; i < n; i++){ 
        scanf("%1d", &a1[i]);
        a2[i] = a1[i];
    }    
    for(int i = 0; i < n; i++) scanf("%1d", &c[i]);
    a1[0]=stu(a1[0]);
    a1[1]=stu(a1[1]);
    int cnt1 = 1;
    int cnt2 = 0;
    for(int i = 1; i < n; i++){
        if(a1[i-1] != c[i-1] && i != n-1){
            cnt1++;
            a1[i-1] = stu(a1[i-1]);
            a1[i] = stu(a1[i]);
            a1[i+1] = stu(a1[i+1]);
        }else if(a1[i-1] != c[i-1] && i == n-1){
            cnt1++;
            a1[i-1] = stu(a1[i-1]);
            a1[i] = stu(a1[i]);
        }    
    }
    if(a1[n-1] != c[n-1]){
        cnt1 = INT_MAX;
    }    
    
    for(int i = 1; i < n; i++){
        if(a2[i-1] != c[i-1] && i != n-1){
            cnt2++;
            a2[i-1] = stu(a2[i-1]);
            a2[i] = stu(a2[i]);
            a2[i+1] = stu(a2[i+1]);
        }else if(a2[i-1] != c[i-1] && i == n-1){
            cnt2++;
            a2[i-1] = stu(a2[i-1]);
            a2[i] = stu(a2[i]);
        }    
    }
    if(a2[n-1] != c[n-1]){
        cnt2 = INT_MAX;
    }
    if(cnt1 == INT_MAX && cnt2 == INT_MAX){
       cout << "-1";
       return 0;
    }
    cout << min(cnt1, cnt2);
}