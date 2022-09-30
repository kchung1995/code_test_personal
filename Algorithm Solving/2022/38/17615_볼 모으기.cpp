// 문제 링크: https://www.acmicpc.net/problem/17615
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string input;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> input;
}

int simulateLeft(char toLeft) {
    
    int cnt = 0;
    bool changed = false;
    
    // left
    for (int i = 0; i < n; i++) {
        if (input[i] != toLeft) {
            changed = true;
        }
        else if (changed && input[i] == toLeft) {
            cnt++;
        }
    }
    return cnt;
}

int simulateRight(char toRight) {
    
    int cnt = 0;
    bool changed = false;
    
    // left
    for (int i = n - 1; i >= 0; i--) {
        if (input[i] != toRight) {
            changed = true;
        }
        else if (changed && input[i] == toRight) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    init();
    int answer = 1e9;
    answer = min(answer, simulateLeft('B'));
    answer = min(answer, simulateLeft('R'));
    answer = min(answer, simulateRight('B'));
    answer = min(answer, simulateRight('R'));
    cout << answer;
    return 0;
}
