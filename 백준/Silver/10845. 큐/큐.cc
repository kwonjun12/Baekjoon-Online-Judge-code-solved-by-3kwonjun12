#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

queue<int>q;
int n;
char c[6];
int in;
int ans;
    
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", c);
        if(strcmp(c, "push") == 0){
            scanf("%d", &in);
            q.push(in); 
        }
        else if(strcmp(c, "pop") == 0){
            scanf("%d", &in);
            if(q.size() == 0){
                printf("-1\n");
            }else{
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if(strcmp(c, "empty") == 0){
            if(q.size() == 0){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
        else if(strcmp(c, "size") == 0){
            printf("%d\n", q.size());
        }
        else if(strcmp(c, "front") == 0){
            if(q.size() == 0){
                printf("-1\n");
            }else{
                printf("%d\n", q.front());
            }
        }
        else{
            if(q.size() == 0){
                printf("-1\n");
            }else{
                printf("%d\n", q.back());
            }
        }
    } 
}