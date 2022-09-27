// 문제 링크: https://www.acmicpc.net/problem/1446
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_D 10001

int n, d;
vector<pair<int, int> > v[MAX_D];

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int start, end, dist;
		cin >> start >> end >> dist;
		v[end].push_back({start, dist});
	}
}

int simulate() {

	vector<int> dist(d + 1, 1e9);
	dist[0] = 0;

	for (int i = 1; i <= d; i++) {
		if (v[i].empty()) {
			dist[i] = dist[i - 1] + 1;
		}
		else {
			for (pair<int, int> next : v[i]) {
				dist[i] = min(dist[i], min(dist[i - 1] + 1, dist[next.first] + next.second));
			}
		}
	}

	return dist[d];
}

int main() {
	init();
	cout << simulate();
	return 0;
}
