// 문제 링크: https://www.acmicpc.net/problem/14658
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l, k;
vector<pair<int, int> > grid;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> l >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		grid.push_back({ a, b });
	}
}

int simulate() {
	int answer = 0;

	// 이중 for문을 사용하여 트램펄린의 위치를 정한다.
	// tx부터 tx + l까지, ty부터 ty + l까지
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			int cnt = 0;
			int tx = grid[i].first;
			int ty = grid[j].second;
			// 이 때 떨어지는 별똥별의 x, y좌표
			for (int s = 0; s < k; s++) {
				int x = grid[s].first;
				int y = grid[s].second;

				// 트램펄린 내에 떨어지는 별똥별의 갯수를 센다.
				if ((tx <= x && x <= tx + l) && (ty <= y && y <= ty + l)) cnt++;
			}
			answer = max(answer, cnt);
		}
	}

	return answer;
}

int main() {
	init();
	cout << k - simulate();
	return 0;
}
