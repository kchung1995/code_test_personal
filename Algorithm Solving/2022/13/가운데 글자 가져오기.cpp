// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12903
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    // 홀수라면
    if (s.size() % 2 == 1) {
        answer = s.substr(s.size() / 2, 1);
    }
    
    // 짝수라면
    else {
        answer = s.substr((s.size() - 1) / 2, 2);
    }
    
    return answer;
}
