#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9
#define MAX_N 101

int N, M, X, K;
int d[MAX_N][MAX_N];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            d[i][j] = INF;
            if (i == j) d[i][j] = 0;
        }

    }
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                d[a][b] = min(d[a][b], d[a][i] + d[i][b]);
            }
        }
    }
    cin >> X >> K;
    
    int distance = d[1][K] + d[K][X];
    if (distance >= INF)
        cout << -1;
    else cout << distance;
    
    return 0;
}
