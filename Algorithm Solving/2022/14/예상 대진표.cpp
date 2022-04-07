// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12985
#include <cmath>

using namespace std;

int solution(int n, int a, int b) {
    int round = 1;
    while(1) {
        //바로 옆에 붙어 있고, 더 작은 수가 홀수면 (1&2, 3&4, ...)
        if (abs(a-b) == 1 && min(a, b) % 2 == 1) return round;
        else {
            // 다음 참가번호 배정
            if (a % 2 == 1) a = (a/2 + 1);
            else a /= 2;
            if (b % 2 == 1) b = (b/2 + 1);
            else b /= 2;
            round++;
        }
    }
}
