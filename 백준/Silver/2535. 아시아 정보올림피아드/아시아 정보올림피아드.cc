#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int c,s,o;
}st;

int cmp(const void* a, const void* b){
    return ((st*)b)->o - ((st*)a)->o;
} 

int main(void){
    int n;
    scanf("%d", &n);
    st arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &arr[i].c,&arr[i].s,&arr[i].o);
    }
    qsort(arr, n, sizeof(arr[0]), cmp);
    int co[101] = {0,};
    int f = 0;
    for(int i = 0; i < n; i++){
        if(co[arr[i].c] >= 2){
            continue;
        }    
        printf("%d %d\n", arr[i].c, arr[i].s);
        co[arr[i].c]++;
        f++;
        if(f == 3) return 0; 
    }
}