// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/1829

#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int bfs (int m, int n, int x, int y, vector<vector<bool> > &visited, vector<vector<int> > &picture) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int currentColor = picture[x][y];
    
    int answer = 1;
    queue<pair<int, int> > q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (picture[nx][ny] != currentColor) continue;
            if (visited[nx][ny] == true) continue;
            visited[nx][ny] = true;
            answer++;
            q.push({nx, ny});
        }
    }
    return answer;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer;
    vector<vector<bool> > visited;
    
    // 방문 배열 초기화
    vector<bool> visited_entry;
    for (int j = 0; j < n; j++) {
        visited_entry.push_back(false);
    }
    for (int i = 0; i < m; i++) {
        visited.push_back(visited_entry);
    }
    
    // 방문하지 않은 칸을 찾아다님
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 방문하지 않은 경우
            if (!visited[i][j]) {
                int area_size = bfs(m, n, i, j, visited, picture);
                if (picture[i][j] != 0) {
                    number_of_area++;
                    max_size_of_one_area = max(max_size_of_one_area, area_size);
                }
            }
        }
    }
    
    // 반환할 답 정리
    answer.push_back(number_of_area);
    answer.push_back(max_size_of_one_area);
    return answer;
}