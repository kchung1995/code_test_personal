#include <iostream>
#include <vector>
using namespace std;

//노드의 개수 V, 간선 (union 연산)의 갯수 E
//V의 최댓값은 100,000 이라고 가정하겠습니다.
#define MAX_V 100001

int v, e;
int parent[MAX_V];
vector <pair <int, pair<int, int> > > edges;
int result = 0;

int findParent(int x) {
    if (x != parent[x])
        parent[x] = findParent(parent[x]);
    return parent[x];
}

void unionParent(int x, int y) {
    x = findParent(x);
    y = findParent(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    cin >> v >> e;
    
    //부모 테이블의 초기화: 각 노드의 부모는 자기 자신으로 초기화한다.
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back(make_pair(cost, make_pair(a, b)));
    }
    
    sort(edges.begin(), edges.end());
    
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int node_a = edges[i].second.first;
        int node_b = edges[i].second.second;
        
        if (findParent(node_a) != findParent(node_b)) {
            unionParent(node_a, node_b);
            result += cost;
        }
    }
    
    cout << result;
    return 0;
}
