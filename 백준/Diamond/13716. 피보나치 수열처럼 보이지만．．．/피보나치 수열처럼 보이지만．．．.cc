#include <stdio.h>
#define MOD 1000000007LL
#define MAX_SIZE 85

long long N;
int K;
int s;
long long C[45][45];

typedef struct {
    long long m[MAX_SIZE][MAX_SIZE];
}M;

M Mm(M A, M B) {
    M R = {0};
    for (int i = 0; i < s; i++) {
        for (int k = 0; k < s; k++) {
            if (A.m[i][k] == 0) continue;
            for (int j = 0; j < s; j++) {
                R.m[i][j] = (R.m[i][j] + A.m[i][k] * B.m[k][j])% MOD;
            }
         }
    }
    return R;
}

M Mp(M A, long long e) {
    M R = {0};
    for (int i = 0; i < s; i++) R.m[i][i] = 1;
    M base = A;
    while (e > 0)  {
        if (e % 2 == 1) {
            R = Mm(R, base);
        }
        base = Mm(base, base);
        e /= 2;
    }
    return R;
}

int main() {
    if (scanf("%lld %d", &N, &K) != 2) return 0;
    if (N == 1) {
        printf("1");
        return 0;
    }
    for (int i = 0; i <= K; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
         }
    }
    s = 2 * K + 3;
    M TM = {0};

    TM.m[0][0] = 1;
    for (int j = 0; j <= K; j++) {
        long long v = C[K][j];
        TM.m[0][1 + j] = (TM.m[0][1 + j] + v) % MOD;
        TM.m[0][K + 2 + j] = (TM.m[0][K + 2 + j] + v) % MOD;
    }
    for (int p = 0; p <= K; p++) {
        int r = 1 + p;
        for (int j = 0; j <= p; j++) {
            long long v = C[p][j];
            TM.m[r][1 + j] = (TM.m[r][1 + j] + v) % MOD;
            TM.m[r][K + 2 + j] = (TM.m[r][K + 2 + j] + v) % MOD;
        }
    }
    for (int p = 0; p <= K; p++) {
        int r = K + 2 + p;
        for (int j = 0; j <= p; j++) {
            long long v = C[p][j];
            TM.m[r][1 + j] = (TM.m[r][1 + j] + v) % MOD;
         }
     }
    M R = Mp(TM, N - 1);
    long long ans = 0;
    for (int i = 0; i < s; i++) {
        ans = (ans + R.m[0][i]) % MOD;
    }
    printf("%lld", ans);
}