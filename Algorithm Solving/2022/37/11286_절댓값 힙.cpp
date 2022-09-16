// 문제 링크: https://www.acmicpc.net/problem/11286
#include <iostream>
#include <queue>
using namespace std;

int n;

priority_queue<long long> pos;
priority_queue<long long> neg;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
}

long long printHeap() {
    // 절댓값이 가장 작은 값을 출력한다.
    // 만약 힙이 비어 있다면 0을 출력한다.
    if (pos.empty() && neg.empty()) return 0;
    
    // 만약 음수 힙에만 숫자가 있다면 해당 숫자를 출력한다.
    if (pos.empty()) {
        long long answer = neg.top();
        neg.pop();
        return answer;
    }
    // 만약 양수 힙에만 숫자가 있다면 해당 숫자를 출력한다.
    if (neg.empty()) {
        long long answer = -1 * pos.top();
        pos.pop();
        return answer;
    }
    // 두 힙에 모두 숫자가 있는 경우
    // 힙에는 모든 숫자가 음수로 들어가 있으므로, 실제로는 작은 숫자가 힙에서는 큰 숫자다.
    if (pos.top() > neg.top()) {
        long long answer = -1 * pos.top();
        pos.pop();
        return answer;
    }
    long long answer = neg.top();
    neg.pop();
    return answer;
}

void addHeap(long long temp) {
    // 입력이 음수인 경우
    if (temp < 0) {
        neg.push(temp);
    }
    // 입력이 양수인 경우
    if (temp > 0) {
        pos.push(-1 * temp);
    }
}

void absHeapSimulate() {
    while(n--) {
        long long temp; cin >> temp;
        
        // 주어지는 입력에 따라 구분
        switch(temp) {
            case 0:
                cout << printHeap() << '\n';
                break;
            default:
                addHeap(temp);
                break;
        }
    }
}

int main() {
    init();
    absHeapSimulate();
    return 0;
}

