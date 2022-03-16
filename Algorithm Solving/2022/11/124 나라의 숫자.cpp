// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12899#
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string decimal_to_124 (int n) {
    string answer = "";
    
    // 숫자가 3 이상일 동안 반복
    while(n >= 3) {
        int remaining = n % 3;
        
        // 나머지가 0일 경우, 값을 4로 대체하고, n값을 하나 줄임
        if (remaining == 0) {
            answer = '4' + answer;
            n = (n/3) - 1;
        }
        else {
            answer = to_string(remaining) + answer;
            n /= 3;
        }
    }
    answer = to_string(n) + answer;
    
    // 맨 앞에 0이 있을 경우 제거
    if (answer[0] == '0') return answer.substr(1);
    else return answer;
}

string solution(int n) {
    
    string answer = decimal_to_124(n);
    
    return answer;
}
