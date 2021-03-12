#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9
#define MAX_N 501

int n, m;
int graph[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < MAX_N; i++) {
        fill(graph[i], graph[i] + MAX_N, INF);
    }
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) graph[a][b] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }
    
    int result = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] != INF || graph[j][i] != INF)
                cnt++;
        }
        if (cnt == n)
            result++;
    }
    cout << result;
    return 0;
}
