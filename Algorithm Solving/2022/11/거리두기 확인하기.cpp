// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/81302
#include <string>
#include <vector>
#include <queue>
#define SIZE 5
#define DIRS 12
#define INF 1e9

using namespace std;
int dx[DIRS] = {-1, 0, 1, 0, 1, 1, -1, -1, -2, 0, 2, 0};
int dy[DIRS] = {0, 1, 0, -1, 1, -1, 1, -1, 0, 2, 0, -2};


bool inBoundary (int x, int y) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) return true;
    else return false;
}

int shortestDist (int fromX, int fromY, int toX, int toY, vector<string> &places) {
    queue<pair<int, int> > q;
    q.push({fromX, fromY});
    
    int visited[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            visited[i][j] = INF;
        }
    }
    visited[fromX][fromY] = 0;
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if (!inBoundary(nx, ny)) continue;
            if (places[nx][ny] == 'X') continue;
            if (visited[nx][ny] > visited[cx][cy] + 1) {
                visited[nx][ny] = visited[cx][cy] + 1;
                q.push({nx, ny});
            }
        
        }
    }
    
    return visited[toX][toY];
}

bool otherInDist (int x, int y, vector<string> &places) {
    
    for (int dist = 0; dist < DIRS; dist++) {
        int nx = x + dx[dist];
        int ny = y + dy[dist];
        
        if (!inBoundary(nx, ny)) continue;
        
        if (places[nx][ny] == 'P') {
            int dist = shortestDist(x, y, nx, ny, places);
            if (dist <= 2) return true;
        }
    }
    
    return false;
}

vector<int> solution (vector<vector<string> > places) {
    
    vector<int> answer;
    
    for (int a = 0; a < places.size(); a++) {
        
        // 대기실 내 인원을 스캔
        bool currentResult = false;
        for (int i = 0; i < SIZE; i++) {
            if (currentResult) break;
            for (int j = 0; j < SIZE; j++) {
                
                if (places[a][i][j] == 'P') {
                    currentResult = otherInDist(i, j, places[a]);
                }
                if (currentResult == true) {
                    answer.push_back(0);
                    break;
                }
                
            }
        }
        if (!currentResult) answer.push_back(1);
    }
    
    return answer;
}
