// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12982
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    
    // 신청한 금액이 작은 부서부터 먼저 지원해 준다.
    sort(d.begin(), d.end());
    
    int count = 0;
    int used = 0;
    for (count; count < d.size(); count++) {
        if (d[count] + used <= budget) {
            used += d[count];
        }
        else break;
    }
    
    return count;
}
