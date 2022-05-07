// 문제 링크: https://www.acmicpc.net/problem/1406
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> cursorLeft;
stack<char> cursorRight;
string input;
int n;

void execute (char &cmd, char &subject) {
    switch (cmd) {
        case 'L':
            if (!cursorLeft.empty()) {
                cursorRight.push(cursorLeft.top());
                cursorLeft.pop();
            }
            break;
        case 'D':
            if (!cursorRight.empty()) {
                cursorLeft.push(cursorRight.top());
                cursorRight.pop();
            }
            break;
        case 'B':
            if (!cursorLeft.empty()) cursorLeft.pop();
            break;
        case 'P':
            cursorLeft.push(subject);
            break;
    }
}

void init() {
    cin >> input;
    cin >> n;
    
    for (int i = 0; i < input.size(); i++) {
        cursorLeft.push(input[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // 입력 받기
    init();
    
    // 명령 실행
    char cmd, subj;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == 'P') {
            cin >> subj;
        }
        execute(cmd, subj);
    }
    
    // 정답 출력
    while(!cursorLeft.empty()) {
        cursorRight.push(cursorLeft.top());
        cursorLeft.pop();
    }
    while(!cursorRight.empty()) {
        cout << cursorRight.top();
        cursorRight.pop();
    }
    return 0;
}
