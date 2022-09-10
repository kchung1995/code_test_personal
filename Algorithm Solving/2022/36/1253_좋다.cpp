// 문제 링크: https://www.acmicpc.net/problem/1253
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> num;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 주어진 입력을 받는다.
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
}

bool isGoodNumber(int i) {
    
    int start = 0, end = n - 1;
    while (start < end) {
        if (start == i) {
            start++; continue;
        }
        if (end == i) {
            end--; continue;
        }
        
        // good number인 경우
        if (num[i] == num[start] + num[end]) {
            return true;
        }
        // 두 수의 합보다 목표 숫자가 더 큰 경우
        else if (num[i] > num[start] + num[end]) {
            start++;
        }
        // 두 수의 합보다 목표 숫자가 더 작은 경우
        else if (num[i] < num[start] + num[end]) {
            end--;
        }
    }
    
    return false;
}

int simulate() {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (isGoodNumber(i)) {
            answer++;
        }
    }
    return answer;
}

int main() {
    init();
    if (n < 3) {
        cout << 0;
        return 0;
    }
    cout << simulate();
    return 0;
}

