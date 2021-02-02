#include <iostream>
using namespace std;
#define MAX_N 1000

int N, M;
int matrix[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int counter = 0;

bool in_boundary(int i, int j) {
    if (i >= 0 && j >= 0 && i < N && j < M)
        return true;
    else
        return false;
}

void dfs (int i, int j) {
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (in_boundary(ni,nj) && matrix[ni][nj] == 0 && visited[ni][nj] == 0)
            dfs(ni,nj);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0 && matrix[i][j] == 0) {
                counter++;
                dfs(i, j);
            }
        }
    }
    cout << counter;
    return 0;
    
}
