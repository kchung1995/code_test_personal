#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 300001

int n, m, k, x;
vector<int> roads[MAX_N];
vector<int> dist(MAX_N, -1);

void bfs() {
    queue<int> q;
    q.push(x);
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < roads[now].size(); i++) {
            int next_town = roads[now][i];
            if (dist[next_town] == -1) {
                dist[next_town] = dist[now] + 1;
                q.push(next_town);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        roads[a].push_back(b);
    }
    
    dist[x] = 0;
    bfs();
    
    bool town_exists = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            cout << i << '\n';
            town_exists = true;
        }
    }
    if (!town_exists) cout << -1;
    
    return 0;
}

