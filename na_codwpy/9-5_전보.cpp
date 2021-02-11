#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9
#define MAX_N 30001
#define MAX_M 200001

int n, m;
vector <pair <int, int> > graph[MAX_M];
int d[MAX_N];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    d[start] = 0;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (d[now] < dist) continue;
        
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int c;
    cin >> n >> m >> c;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    
    for (int i = 0; i <= MAX_N; i++)
        d[i] = INF;
    
    dijkstra(c);
    
    int c_count = 0, max_time = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF) {
            c_count++;
            max_time = max(max_time, d[i]);
        }
    }
    cout << c_count-1 << " " << max_time;
    return 0;
}
