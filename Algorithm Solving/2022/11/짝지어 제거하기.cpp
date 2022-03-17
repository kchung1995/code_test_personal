// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12973
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string input) {
    
    stack<char> s;
    for (int i = 0; i < input.size(); i++) {
        if (s.empty()) {
            s.push(input[i]);
        }
        else {
            if (input[i] == s.top()) {
                s.pop();
            }
            else {
                s.push(input[i]);
            }
        }
    }

    if (s.empty()) return 1;
    else return 0;

}
