#include <stdio.h>

char map[7000][7000];

void d(int x, int y, int n) {
    if (n == 1) {
        map[x][y] = '*';
        return;
    }
    int div = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;  
            d(x + i * div, y + j * div, div);
        }
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = ' ';
    d(0, 0, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
           printf("%c", map[i][j]);
         }     
        printf("\n");
    }
}
