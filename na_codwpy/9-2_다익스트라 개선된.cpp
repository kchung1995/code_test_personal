#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9
#define MAX_V 100001

int n, m, start;
vector<pair< int, int> > graph[MAX_V];              //각 노드 간의 거리 정보를 담음
int d[MAX_V];                                       //출발점으로부터의 각 노드의 거리를 기록함

void dijkstra(int);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> start;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));         //노드 a에서 노드 b까지의 비용이 c
    }
    
    fill_n(d, MAX_V, INF);
    dijkstra(start);
    
    for (int i = 1; i <= n; i++) {
        //도달할 수 없는 경우 INFINITY를 출력
        if (d[i] == INF)
            cout << "INFINITY" << '\n';
        else
            cout << d[i] << '\n';
    }
    
    return 0;
}

void dijkstra(int start) {
    priority_queue<pair <int, int> > pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    while (!pq.empty()) {
        int distance = -pq.top().first;      //현재 노드까지의 비용
        // -를 붙이는 이유는 오름차순 정렬을 하기 위함이다. C++의 기본 priority queue는 큰 숫자를 최상단에 둔다. 즉 내림차순.
        int now = pq.top().second;          //현재 노드
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