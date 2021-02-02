#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 401

int N, M;
int maze[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = {0, };
queue< pair <int, int> > q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in_boundary(int i, int j) {
    if (i > 0 && j > 0 && i <= N && j <= M)
        return true;
    else return false;
}

void bfs(int x, int y) {
    while(!q.empty() && visited[N][M] == 0) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int mx = tx + dx[i];
            int my = ty + dy[i];
            if (in_boundary(mx, my) && maze[mx][my] == 1 && visited[mx][my] == 0) {
                visited[mx][my] = visited[tx][ty] + 1;
                q.push(make_pair(mx,my));
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
    
    q.push(make_pair(1, 1));
    visited[1][1] = 1;
    bfs(1,1);
    cout << visited[N][M] << endl;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
