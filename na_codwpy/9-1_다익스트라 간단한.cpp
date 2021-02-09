#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9
#define MAX_V 100001

int n, m, start;
vector<pair< int, int> > graph[MAX_V];              //각 노드 간의 거리 정보를 담음
bool visited[MAX_V];                                //각 노드의 방문 여부를 기록함
int d[MAX_V];                                       //출발점으로부터의 각 노드의 거리를 기록함

int getSmallestNode();
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
    d[start] = 0;
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++)
        d[graph[start][i].first] = graph[start][i].second;
    
    for (int i = 0; i < n-1; i++) {
        int now = getSmallestNode();
        visited[now] = true;
        
        for (int j = 0; j < graph[now].size(); j++) {
            int cost = d[now] + graph[now][j].second;
            if (cost < d[graph[now][j].first])
                d[graph[now][j].first] = cost;
        }
    }
}

int getSmallestNode() {
    int min_value = INF;
    int index = 0;          //가장 최단 거리가 짧은 노드; 거리는 0보다 같거나 작을 수 없다.
    for (int i = 1; i <= n; i++) {
        if (d[i] < min_value && !visited[i]) {
            min_value = d[i];
            index = i;
        }
    }
    return index;
}