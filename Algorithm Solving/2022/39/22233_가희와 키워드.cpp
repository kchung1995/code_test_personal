// 문제 링크: https://www.acmicpc.net/problem/22233
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

int n, m;
string temp;
unordered_set<string> dict;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
}

void simulate() {

	while (n--) {
		cin >> temp;
		dict.insert(temp);
	}

	while (m--) {
		cin >> temp;
		istringstream ss(temp);
		string buffer;


		while (getline(ss, buffer, ',')) {
			if (dict.find(buffer) != dict.end()) {
				dict.erase(buffer);
			}
		}

		cout << dict.size() << '\n';
	}
}

int main() {
	init();
	simulate();
	return 0;
}
