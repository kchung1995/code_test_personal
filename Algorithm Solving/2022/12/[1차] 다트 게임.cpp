// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/17682
#include <string>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

bool isOperand(char c) {
    if (c == 'S' || c == 'D' || c == 'T' || c == '*' || c == '#') return true;
    else return false;
}

bool isInteger(string s) {
    if (s == "10") return true;
    else if ('0' <= s[0] && s[0] <= '9') return true;
    else return false;
}

int powerBy(char c) {
    if (c == 'S') return 1;
    else if (c == 'D') return 2;
    else if (c == 'T') return 3;
    else return -1;
}

int solution(string dartResult) {
    int answer = 0;
    stack<int> s;
    vector<string> dart;
    
    // dartResult를 잘라서 넣음
    string temp = "";
    
    for (int i = 0; i < dartResult.size(); i++) {
        if (isOperand(dartResult[i])) {
            if (temp != "") dart.push_back(temp);
            temp = "";
            temp += dartResult[i];
            dart.push_back(temp);
            temp = "";
        }
        else {
            temp += dartResult[i];
        }    
    }
    
    for (int i = 0; i < dart.size(); i++) {
        if (isInteger(dart[i])) {
            int temp = stoi(dart[i]);
            i++;
            temp = pow(temp, powerBy(dart[i][0]));
            s.push(temp);
        }
        else if (dart[i][0] == '*') {
            int temp1 = 0, temp2 = 0;
            temp1 = s.top();
            s.pop();
            if (!s.empty()) {
                temp2 = s.top();
                s.pop();
                s.push(temp2 * 2);
            }
            s.push(temp1 * 2);
        }
        else if (dart[i][0] == '#') {
            int temp = 0;
            temp += s.top();
            s.pop();
            s.push(-1*temp);
        }
    }
    
    // answer 값 합
    while(!s.empty()) {
        answer += s.top();
        s.pop();
    }
    
    return answer;
}
