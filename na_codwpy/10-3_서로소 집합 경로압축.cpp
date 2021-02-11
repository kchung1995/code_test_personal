#include <iostream>
using namespace std;

//노드의 개수 V, 간선 (union 연산)의 갯수 E
//V의 최댓값은 100,000 이라고 가정하겠습니다.
#define MAX_V 100001

int v, e;
int parent[MAX_V];

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
        unionParent(a, b);
    }
    
    cout << "각 원소가 속한 집합: \n";
    for (int i = 1; i <= v; i++)
        cout << i << " " << findParent(parent[i], i) << '\n';
    
    cout << "부모 테이블: \n";
    for (int i = 1; i <= v; i++)
        cout << parent[i] << " ";
    
    return 0;
}
