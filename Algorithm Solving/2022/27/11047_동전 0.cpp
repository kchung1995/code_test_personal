// 문제 링크: https://www.acmicpc.net/problem/11047
#include <iostream>
#include <vector>
using namespace std;

int n, k;
int temp;
vector<int> coins;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		coins.push_back(temp);
	}
}

void solve() {
	int totalVal = 0;
	int coinCnt = 0;

	for (int i = n - 1; i >= 0; i--) {
		while (1) {
			if (totalVal + coins[i] > k) break;
			totalVal += coins[i];
			coinCnt++;
		}
	}

	cout << coinCnt;
}

int main() {
	init();
	solve();
	return 0;
}
