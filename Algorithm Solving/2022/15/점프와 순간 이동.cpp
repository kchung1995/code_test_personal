// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12980
#include <algorithm>
using namespace std;

int solution(int n) {
    
    int cost = 1;
    while (n > 1) {
        if (n % 2 == 0) n /= 2;
        else {
            n--;
            cost++;
            n /= 2;
        }
    }

    return cost;
}

