#include <stdio.h>
#include <deque>
using namespace std;

#define MAX 100000

int n, k;
int dist[100001];
deque<int> dq;

void BFS() {
    dq.push_back(n);
    dist[n] = 0;
    while (!dq.empty()) {
        int x = dq.front();
        dq.pop_front();
        if (x == k) return;
        if (x * 2 <= MAX && dist[x * 2] == -1) {
            dist[x * 2] = dist[x];
            dq.push_front(x * 2);
        }
        if (x - 1 >= 0 && dist[x - 1] == -1) {
            dist[x - 1] = dist[x] + 1;
            dq.push_back(x - 1);
        }
        if (x + 1 <= MAX && dist[x + 1] == -1) {
            dist[x + 1] = dist[x] + 1;
            dq.push_back(x + 1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= MAX; i++) dist[i] = -1;
    BFS();
    printf("%d", dist[k]);
}
