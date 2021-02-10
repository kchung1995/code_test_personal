#include <iostream>
using namespace std;
#define INF 1e9
#define MAX_N 501

int n, m;
int graph[MAX_N][MAX_N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < 501; i++)
        fill (graph[i], graph[i]+501, INF);
    
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++)
            if (a == b) graph[a][b] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        // A에서 B로 가는 비용은 C라고 설정
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++)
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
        }
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
            if (graph[a][b] == INF)
                cout << "INFINITY" << ' ';
            else
                cout << graph[a][b] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
