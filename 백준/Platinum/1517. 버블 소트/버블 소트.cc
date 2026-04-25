#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

ll merge_count(int *A, int *tmp, int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    ll cnt = merge_count(A, tmp, l, m) + merge_count(A, tmp, m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (A[i] <= A[j]) {
            tmp[k++] = A[i++];
         } else {
            tmp[k++] = A[j++];
            cnt += (ll)(m - i + 1); 
        }
    }
    while (i <= m) tmp[k++] = A[i++];
    while (j <= r) tmp[k++] = A[j++];
    for (int t = l; t <= r; ++t) A[t] = tmp[t];
    return cnt;
}

int main(void){
    int N;
    scanf("%d", &N);
    int A[N];
    int tmp[N];
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    ll ans = merge_count(A, tmp, 0, N - 1);
    printf("%lld", ans);
}
