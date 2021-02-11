#include <iostream>
using namespace std;

//노드의 개수 V, 간선 (union 연산)의 갯수 E
//V의 최댓값은 100,000 이라고 가정하겠습니다.
#define MAX_V 100001

int v, e;
int parent[MAX_V];
bool cycle = false;

int findParent(int x_parent, int x) {
    if (x != parent[x])
        parent[x] = findParent(x_parent, parent[x]);
    return parent[x];
}

void unionParent(int x, int y) {
    x = findParent(parent[x], x);
    y = findParent(parent[y], y);
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
        int a, b;
        cin >> a >> b;
        if (findParent(parent[a], a) == findParent(parent[b], b)) {
            cycle = true;
            break;
        }
        else
            unionParent(a, b);
    }
    
    if (cycle)
        cout << "사이클이 발생하였습니다.";
    else
        cout << "사이클이 발생하지 않았습니다.";
    
    return 0;
}
