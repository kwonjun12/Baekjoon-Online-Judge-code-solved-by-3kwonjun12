#include <stdio.h>
#define AS 101
int ans[AS][AS];

int main(void){
    int a1[AS][AS], a2[AS][AS];
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a1[i][j]);
    
    scanf("%d %d", &m, &t);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < t; j++)
            scanf("%d", &a2[i][j]);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < t; j++){
            ans[i][j] = 0;  
            for (int k = 0; k < m; k++){
                ans[i][j] += a1[i][k] * a2[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < t; j++){
            if (j){
               printf(" ");
            }    
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}
