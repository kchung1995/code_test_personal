#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 301

bool cannot_divide = false;
int area[MAX_N][MAX_N];
int candidate[MAX_N][MAX_N];
int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int> > q;

int year_count = 0;

void area_input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> area[i][j];
		}
	}
	return;
}

bool in_boundary(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}

void melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			candidate[i][j] = 0;

			for (int dir = 0; dir < 4; dir++) {
				int ni = i + dx[dir];
				int nj = j + dy[dir];
				if (!in_boundary(ni, nj)) continue;
				if (area[ni][nj] == 0) candidate[i][j] += 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j] < candidate[i][j]) area[i][j] = 0;
			else area[i][j] -= candidate[i][j];
		}
	}
	year_count++;
}

bool has_divided() {
	int iceberg_count = 0;
	//visited 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			candidate[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j] != 0 && candidate[i][j] == 0) {
				candidate[i][j] = 1;
				while (!q.empty()) q.pop();
				q.push({ i, j });
				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cx + dx[dir];
						int ny = cy + dy[dir];
						if (!in_boundary(nx, ny)) continue;
						if (area[nx][ny] == 0) continue;
						if (candidate[nx][ny] == 1) continue;
						candidate[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
				iceberg_count++;
			}
		}
	}

	if (iceberg_count == 1) return false;
	else if (iceberg_count == 0) {
		cannot_divide = true;
		return true;
	}
	else if (iceberg_count >= 2) return true;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m;
	area_input();

	while (1) {
		if (has_divided()) break;
		melt();
	}

	if (cannot_divide) cout << 0;
	else cout << year_count;

	return 0;
}