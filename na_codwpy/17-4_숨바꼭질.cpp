#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 20001
#define INF 1e9

vector<pair <int, int> > graph[MAX_N];
int d[MAX_N];
int n, m;

void dijkstra(int start) {
    priority_queue<pair <int, int> > pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    
    while(!pq.empty()) {
        int distance = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (distance > d[now]) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = distance + graph[now][i].second;
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        fill (d, d + MAX_N, INF);
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(make_pair(b, 1));
        graph[b].push_back(make_pair(a, 1));
    }
    
    int start = 1;
    dijkstra(start);
    
    int max_node = 0, max_distance = 0;
    vector<int> result;
    
    for (int i = 1; i <= n; i++) {
        if (d[i] > max_distance) {
            max_distance = d[i];
            max_node = i;
            result.clear();
            result.push_back(max_node);
        }
        else if (d[i] == max_distance)
            result.push_back(i);
    }
    cout << max_node << " " << max_distance << " " << result.size();
    return 0;
}
