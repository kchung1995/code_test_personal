// 문제 링크: https://www.acmicpc.net/problem/2138
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string initInput;
string initGoal;
int ans = 1e9;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> initInput;
    cin >> initGoal;
}

void toggle (int i, string &input) {
    input[i] = input[i] == '0' ? '1' : '0';
}

void toggleThree (int i, string &input) {
    if (i != 0) {
        toggle(i - 1, input);
    }
    toggle(i, input);
    if (i != n - 1) {
        toggle(i + 1, input);
    }
}

void simulate(int start) {
    
    string temp = initInput;
    int answer = 0;
    
    if (start == 1) {
        toggleThree(0, temp);
        answer++;
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (temp[i] != initGoal[i]) {
            toggleThree(i + 1, temp);
            answer++;
        }
    }
    
    if (temp == initGoal) ans = min(ans, answer);
    return;
}

int main() {
    init();
    simulate(0); simulate(1);
    if (ans == 1e9) cout << -1;
    else cout << ans;
    
    return 0;
}

