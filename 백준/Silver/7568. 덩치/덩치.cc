#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int k, h, r;
} khr;

int main(void){
    int N;
    scanf("%d", &N);
    khr xy[N];
    
    for(int i = 0; i < N; i++){
        scanf("%d %d", &xy[i].k, &xy[i].h);
        xy[i].r = 1; 
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(xy[i].k < xy[j].k && xy[i].h < xy[j].h){
                xy[i].r++;   
            }
        }
    }
    for(int i = 0; i < N; i++){
        printf("%d ", xy[i].r);
    }
}
