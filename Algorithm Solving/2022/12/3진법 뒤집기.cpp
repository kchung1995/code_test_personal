// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/68935
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int reversed_trinary_to_int(string input) {
    int answer = 0;
    
    for (int i = 0; i < input.size(); i++) {
        answer += ((input[i] - '0') * pow(3, i));
    }
    
    return answer;
}

string int_to_trinary(int input) {
    string answer = "";
    
    while (input >= 3) {
        answer = to_string(input % 3) + answer;
        input /= 3;
    }
    answer = to_string(input) + answer;
    
    return answer;
}

int solution(int n) {
    
    return reversed_trinary_to_int(int_to_trinary(n));
    
}
