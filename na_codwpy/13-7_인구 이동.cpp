#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAX_N 50

int n, l, r;
int countries[MAX_N][MAX_N];
int unions[MAX_N][MAX_N];
int pop_move = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void unite (int x, int y, int index) {
    vector <pair <int, int> > united;
    united.push_back(make_pair(x, y));
    
    queue <pair <int, int> > q;
    q.push(make_pair(x, y));
    unions[x][y] = index;
    int total_pop = countries[x][y];
    int country_count = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (unions[nx][ny] == -1) {
                    int pop_gap = abs(countries[nx][ny] - countries[x][y]);
                    if (l <= pop_gap && pop_gap <= r) {
                        q.push(make_pair(nx, ny));
                        unions[nx][ny] = index;
                        total_pop += countries[nx][ny];
                        country_count++;
                        united.push_back(make_pair(nx, ny));
                    }
                    
                }
            }
        }
    }
    
    for (int i = 0; i < united.size(); i++) {
        int x = united[i].first;
        int y = united[i].second;
        countries[x][y] = total_pop / country_count;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l >> r;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> countries[i][j];
        }
    }
    
    while(1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                unions[i][j] = -1;
            }
        }
        
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (unions[i][j] == -1) {
                    unite(i, j, index);
                    index++;
                }
            }
        }
        if (index == n*n) break;
        pop_move++;
        
    }
    
    cout << pop_move;
    return 0;
}
