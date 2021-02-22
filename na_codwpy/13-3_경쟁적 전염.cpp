#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 200

int n, k;
int tube[MAX_N][MAX_N];
vector <pair <pair <int, int>, pair <int, int> > > virus; //바이러스 번호, order, x좌표, y좌표
queue <pair <pair <int, int>, pair <int, int> > > q;
int target_s, target_x, target_y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool in_boundary(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n)
        return true;
    return false;
}

void bfs() {
    while (!q.empty()) {
        int virus_now = q.front().first.first;
        int x_now = q.front().second.first;
        int y_now = q.front().second.second;
        int order_now = q.front().first.second;
        q.pop();
        
        if (order_now == target_s) break;
        
        for (int i = 0; i < 4; i++) {
            int nx = x_now + dx[i];
            int ny = y_now + dy[i];
            
            if (in_boundary(nx, ny)) {
                if (tube[nx][ny] == 0) {
                    tube[nx][ny] = virus_now;
                    q.push((make_pair(make_pair(virus_now, order_now + 1), make_pair(nx, ny))));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            tube[i][j] = temp;
            if (tube[i][j] != 0) virus.push_back(make_pair(make_pair(temp, 0), make_pair(i, j)));
        }
    }
    
    cin >> target_s >> target_x >> target_y;
    
    sort(virus.begin(), virus.end());
    for (int i = 0; i < virus.size(); i++) {
        int virus_no = virus[i].first.first;
        int x = virus[i].second.first;
        int y = virus[i].second.second;
        q.push(make_pair(make_pair(virus_no, 0), make_pair(x, y)));
    }
    
    bfs();
    cout << tube[target_x-1][target_y-1];
    
    return 0;
    
}
