// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/77884
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    
    int answer = 0;
    
    for (int num = left; num <= right; num++) {
        int root = sqrt(num);
        if (num == pow(root, 2)) answer -= num;
        else answer += num;
    }
    
    return answer;
}
