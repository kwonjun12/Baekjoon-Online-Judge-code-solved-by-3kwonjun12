#include <stdio.h>

int visited[101];
int arr[101][101];  
int n, cn, cnt = 0;

void DFS(int x) {
    visited[x] = 1;
    cnt++;
    for(int i = 1; i <= n; i++) {
        if(arr[x][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main(void) {
    scanf("%d", &n);
    scanf("%d", &cn);
    for(int i = 0; i < cn; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;   
    }
    DFS(1);
    printf("%d", cnt - 1); 
}
