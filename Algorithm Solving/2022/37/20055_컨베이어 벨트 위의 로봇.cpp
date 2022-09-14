// 문제 링크: https://www.acmicpc.net/problem/20055
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, k;
deque<int> dura;	// 내구도
deque<bool> belt;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++) {
		int temp; cin >> temp;
		dura.push_back(temp);
		belt.push_back(false);
	}
}

int getDuraZero() {
	int answer = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (dura[i] == 0) answer++;
	}

	return answer;
}

void rotate() {
	belt.push_front(belt.back());
	belt.pop_back();

	dura.push_front(dura.back());
	dura.pop_back();
	belt[n - 1] = false;
}

void moveRobots() {
	for (int i = n - 2; i >= 0; i--) {
		if (dura[i + 1] > 0 && belt[i] && !belt[i + 1]) {
			belt[i] = false;
			belt[i + 1] = true;
			dura[i + 1]--;
		}
	}
	belt[n - 1] = false;
}

void addRobot() {
	if (dura[0] > 0 && !belt[0]) {
		dura[0]--;
		belt[0] = true;
	}
}

int simulate() {
	int turnCount = 1;

	while (1) {

		// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다. 만약 내리는 위치에 로봇이 있다면 즉시 로봇을 내린다.
		rotate();

		// 2. 벨트 위에 있는 로봇이 움직일 수 있다면 한 칸씩 움직인다. 
		moveRobots();

		// 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
		addRobot();

		// 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.
		if (getDuraZero() >= k) break;

		turnCount++;
	}

	return turnCount;
}

int main() {
	init();
	cout << simulate();
	return 0;
}
