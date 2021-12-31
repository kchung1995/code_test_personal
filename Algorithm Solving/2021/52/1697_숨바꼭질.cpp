#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100001
#define INF 1e9

int n, k;
int visited[MAX_N];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        visited[i] = INF;
    }
    visited[n] = 0;
}

bool in_boundary (int input) {
    if (input < 0 || input >= MAX_N) return false;
    else return true;
}

int move (int input, int mode) {
    if (mode == 0) return input - 1;
    else if (mode == 1) return input + 1;
    else if (mode == 2) return input * 2;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    init();
    
    queue<int> q;
    q.push(n);
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < 3; i++) {
            int next = move(now, i);
            if (!in_boundary(next)) continue;
            
            if (visited[now] + 1 < visited[next]) {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }
    
    cout << visited[k];
    return 0;
}

