#include <iostream>
using namespace std;
#define MAX_N 50

int area[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = {0, };
int n, m;
int x, y, dir;
int cnt = 1;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int turnLeft(int x) {
    x--;
    if (x == -1) return 3; else return x;
}

bool in_boundary(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> x >> y >> dir;
    visited[x][y] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> area[i][j];
        }
    }
    
    int turnCount = 0;
    while(1) {
        dir = turnLeft(dir);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (area[nx][ny] == 0 && visited[nx][ny] == 0) {
            visited[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt++;
            turnCount = 0;
            continue;
        } else turnCount++;
        
        if (turnCount == 4) {
            nx = x - dx[dir];
            ny = y - dy[dir];
            
            if (area[nx][ny] == 0) {
                x = nx;
                y = ny;
            } else break;
            turnCount = 0;
        }
    }
    
    cout << cnt;
    return 0;
}
