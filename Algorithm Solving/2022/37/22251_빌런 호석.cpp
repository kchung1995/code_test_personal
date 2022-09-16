// 문제 링크: https://www.acmicpc.net/problem/22251
#include <iostream>
#include <string>

using namespace std;

#define MAX_P 7
#define MAX_D 10

const int bits[MAX_D][MAX_P] = {
    {1, 1, 0, 1, 1, 1, 1},  // 0
    {0, 0, 0, 1, 0, 0, 1},  // 1
    {1, 0, 1, 1, 1, 1, 0},  // 2
    {1, 0, 1, 1, 0, 1, 1},  // 3
    {0, 1, 1, 1, 0, 0, 1},  // 4
    {1, 1, 1, 0, 0, 1, 1},  // 5
    {1, 1, 1, 0, 1, 1, 1},  // 6
    {1, 0, 0, 1, 0, 0, 1},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
};

int n, k, p, x; // n층까지, k자리 수, 최대 p개 반전, 현재 x층
string xstr = "";

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> p >> x;
    
    xstr = to_string(x);
    while(xstr.size() < k) {
        xstr = "0" + xstr;
    }
}

int flip (int input) {
    
    int answer = 0;
    
    // 비교를 편하게 하기 위해서 정수를 문자열로 변환한다.
    string cmp = to_string(input);
    while(cmp.size() < k) {
        cmp = "0" + cmp;
    }
    
    // 두 문자열을 비교해 보자.
    // 각 자리마다,
    for (int i = 0; i < k; i++) {
        // 각 숫자 표시 LED에 대해
        for (int j = 0; j < MAX_P; j++) {
            if (bits[xstr[i] - '0'][j] != bits[cmp[i] - '0'][j]) answer++;
        }
    }
    
    return answer;
}

int simulate() {
    int answer = 0;
    
    // 1층부터 N층까지 중에서
    for (int floor = 1; floor <= n; floor++) {
        if (floor == x) continue;
        if (flip(floor) <= p) answer++;
    }
    
    return answer;
}

int main() {
    init();
    cout << simulate();
    return 0;
}

