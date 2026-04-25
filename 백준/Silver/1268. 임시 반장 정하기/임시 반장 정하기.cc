#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct{
    int num,d;
}gn;

int cmp(const void* a,const void* b){
    gn* g1 = (gn*)a;
    gn* g2 = (gn*)b;
    if(g2 -> d == g1 -> d){
        return g1 -> num - g2 -> num; 
    }
    return g2->d - g1->d;
}

int main(void){
    int n;
    cin >> n;
    int arr[n][5];
    gn arr2[n];
    for(int i = 0; i < n; i++){
       for(int j = 0; j < 5; j++){
           cin >> arr[i][j];
           arr2[i].num = i+1;
       }
    }
    for(int i = 0; i < n; i++){
        arr2[i].d = 0;
    }
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            if(i==k)continue;
            for(int j = 0; j < 5; j++){
                if(arr[i][j] == arr[k][j]){
                    arr2[i].d++;
                    break;
                }
            }
        }        
    }
    qsort(arr2, n, sizeof(arr2[0]), cmp);
    cout << arr2[0].num;
}