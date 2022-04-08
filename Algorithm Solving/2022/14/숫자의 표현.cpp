// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12924
#include <string>
#include <vector>

using namespace std;

int start = 1, finish = 1;
int sum = 1;

int solution(int n) {
    int answer = 0;
    
    if (n == 1) return 1;
    
    
    while (finish <= n) {
        if (sum < n) {
            finish++;
            sum += finish;
        }
        else if (sum > n) {
            sum -= start;
            start++;
        }
        else if (sum == n) {
            answer++;
            finish++;
            sum += finish;
        }
    }
    
    return answer;
}
