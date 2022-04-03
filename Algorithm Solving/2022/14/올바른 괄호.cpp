// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12909
#include <string>
#include <stack>

using namespace std;

bool solution(string input)
{
    stack<char> s;
    
    for (auto &next : input) {
        if (next == '(') {
            s.push('(');
        }
        else if (next == ')') {
            if (s.empty()) return false;
            if (s.top() == '(') {
                s.pop();
            }
            else if (s.top() == ')') {
                return false;
            }
        }
    }
    
    if (!s.empty()) return false;
    else return true;
    
}
