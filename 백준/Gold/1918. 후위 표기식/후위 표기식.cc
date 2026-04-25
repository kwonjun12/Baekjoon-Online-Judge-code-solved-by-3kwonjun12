#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 105

int pr(char o) {
    switch (o) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

int main(void) {
    char ix[M]; 
    char po[M]; 
    char st[M]; 
    int t = -1; 
    int pi = 0; 
    scanf("%s", ix);
    for (int i = 0; i < strlen(ix); i++) {
        char k = ix[i]; 

        if (k >= 'A' && k <= 'Z') {
            po[pi++] = k;
        }
        else if (k == '(') {
            st[++t] = k;
        }
        else if (k == ')') {
            while (t != -1 && st[t] != '(') {
                po[pi++] = st[t--];
            }
            if (t != -1) {
                t--; 
            }
        }
        else {
            while (t != -1 && pr(st[t]) >= pr(k)) {
                po[pi++] = st[t--];
            }
            st[++t] = k; 
        }
    }
    while (t != -1) {
        po[pi++] = st[t--];
     }
    po[pi] = '\0';
    printf("%s", po);
}