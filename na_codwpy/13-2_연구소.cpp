#include <iostream>
#include <algorithm>
using namespace std;

int area[8][8];
int temp_area[8][8];
int safe_area = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

int get_area() {
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        if (temp_area[i][j] == 0)
            area++;
    }
    return area;
}

bool boundary_check(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}

void virus (int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (temp_area[nx][ny] == 0 && boundary_check(nx, ny)) {
            temp_area[nx][ny] = 2;
            virus(nx, ny);
        }
    }
}

void dfs(int count) {
    if (count == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            temp_area[i][j] = area[i][j];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp_area[i][j] == 2)
                    virus(i, j);
            }
        }
        safe_area = max(safe_area, get_area());
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        if (area[i][j] == 0) {
            area[i][j] = 1;
            count++;
            dfs(count);
            area[i][j] = 0;
            count--;
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        cin >> area[i][j];
    }
    
    dfs(0);
    cout << safe_area;
    return 0;
}
