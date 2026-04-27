#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

stack<int>s;
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
            s.push(in); 
        }
        else if(strcmp(c, "pop") == 0){
            scanf("%d", &in);
            if(s.size() == 0){
                printf("-1\n");
            }else{
                printf("%d\n", s.top());
                s.pop();
            }
        }
        else if(strcmp(c, "empty") == 0){
            if(s.size() == 0){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
        else if(strcmp(c, "size") == 0){
            printf("%d\n", s.size());
        }
        else if(strcmp(c, "top") == 0){
            if(s.size() == 0){
                printf("-1\n");
            }else{
                printf("%d\n", s.top());
            }
        }
    } 
}