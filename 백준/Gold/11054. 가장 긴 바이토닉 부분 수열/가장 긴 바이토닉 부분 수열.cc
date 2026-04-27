#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int dp1[n];
    int dp2[n];
    for(int i = 0; i < n; i++){
        dp1[i] = 1;
        dp2[i] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(a[i] > a[j]){
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = ans < (dp1[i] + dp2[i] - 1) ? (dp1[i] + dp2[i] - 1) : ans;
    }
    printf("%d", ans);
}