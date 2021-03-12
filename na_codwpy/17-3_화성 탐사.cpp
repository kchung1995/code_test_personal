#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_N 125
#define INF 1e9

int t, n;
int graph[MAX_N][MAX_N];
int d[MAX_N][MAX_N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    
    for (int round = 0; round < t; round++) {
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            fill (d[i], d[i] + MAX_N, INF);
        }
        
        int x = 0, y = 0;               //시작위치 x = 0, y = 0;
        priority_queue<pair <int, pair <int, int> > > pq;
        pq.push(make_pair(-graph[x][y], make_pair(x, y)));
        d[x][y] = graph[x][y];
        
        while (!pq.empty()) {
            int distance = -pq.top().first;
            int x_now = pq.top().second.first;
            int y_now = pq.top().second.second;
            pq.pop();
            
            if (distance > d[x_now][y_now]) continue;
            
            for (int dir = 0; dir < 4; dir++) {
                int x_new = x_now + dx[dir];
                int y_new = y_now + dy[dir];
                if (x_new < 0 || y_new < 0 || x_new >= n || y_new >= n) continue;
                int cost = distance + graph[x_new][y_new];
                if (d[x_new][y_new] > cost) {
                    d[x_new][y_new] = cost;
                    pq.push(make_pair(-cost, make_pair(x_new, y_new)));
                }
            }
        }
        cout << d[n-1][n-1] << '\n';
    }
    return 0;
}

/*
 
3
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
 
 */
