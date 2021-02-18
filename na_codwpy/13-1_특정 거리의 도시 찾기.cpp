#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
vector <int> road[300001];
vector <int> dist (300001, -1);
int cities;

void bfs() {
    queue<int> q;
    q.push(x);
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < road[now].size(); i++) {
            int next_city = road[now][i];
            if (dist[next_city] == -1) {
                dist[next_city] = dist[now] + 1;
                q.push(next_city);
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
        road[a].push_back(b);
    }
    
    dist[x] = 0;
    
    bfs();
    bool city_exists = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            cout << i << endl;
            city_exists = true;
        }
    }
    
    if (!city_exists) cout << -1;
    return 0;
}

