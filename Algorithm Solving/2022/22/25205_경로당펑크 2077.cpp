// 문제 링크: https://www.acmicpc.net/problem/25205
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int len;
	string input;
	cin >> len >> input;
	if (input[len - 1] == 'a' || input[len - 1] == 's' || input[len - 1] == 'd' || input[len - 1] == 'f' ||
		input[len - 1] == 'q' || input[len - 1] == 'w' || input[len - 1] == 'e' || input[len - 1] == 'r' ||
		input[len - 1] == 'z' || input[len - 1] == 'x' || input[len - 1] == 'c' || input[len - 1] == 'v' ||
		input[len - 1] == 't' || input[len - 1] == 'g') cout << 1;
	else cout << 0;
	return 0;
}
