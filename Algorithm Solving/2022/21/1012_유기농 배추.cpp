// 문제 링크: https://www.acmicpc.net/problem/1012
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 50

int t;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool inBoundary(int x, int y, int m, int n) {
	if (0 <= x && x < m && 0 <= y && y < n) return true;
	return false;
}

int getArea(int m, int n, vector<vector<int> > &grid) {
	int answer = 0;
	// 방문 여부를 기록하기 위한 배열
	vector<vector<bool> > visited(m, vector<bool>(n, false));
	
	// 영역 탐색
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 만약 방문하지 않았고 배추가 있는 곳을 찾았다면
			if (grid[i][j] == 1 && !visited[i][j]) {
				queue<pair<int, int> > q;
				visited[i][j] = true;
				q.push({ i, j });
				answer++;

				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cx + dx[dir];
						int ny = cy + dy[dir];
						// 방문할 수 없으면 스킵
						if (!inBoundary(nx, ny, m, n)) continue;
						// 배추가 아니면 스킵
						if (grid[nx][ny] != 1) continue;
						// 방문했다면 스킵
						if (visited[nx][ny]) continue;

						// 해당 배추를 방문했다고 기록하고
						visited[nx][ny] = true;
						// queue에 넣는다.
						q.push({ nx, ny });
					}
				}
			}
		}
	}

	return answer;
}

void getGrid() {
	int m, n, k;
	cin >> m >> n >> k;

	// 크기에 맞는 2차원 배열을 생성
	vector<vector<int> > grid(m, vector<int>(n, 0));
	// k번 입력을 받음
	while (k--) {
		int x, y;
		cin >> x >> y;
		grid[x][y] = 1;
	}

	// bfs를 이용한 영역 구하기
	cout << getArea(m, n, grid) << '\n';
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
}

int main() {
	// 기본 입력
	init();
	// 테스트 케이스 t만큼 코드를 수행
	while (t--) {
		getGrid();
	}
}

