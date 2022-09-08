// 문제 링크: https://www.acmicpc.net/problem/1091
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> p;
vector<int> s;
//const int maxCnt = pow(48, 3) + 1;
const int maxCnt = 1e7;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 주어진 입력을 받는다.
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        p.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        s.push_back(temp);
    }
}

void shuffle() {
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[s[i]] = p[i];
    }
    for (int i = 0; i < n; i++) {
        p[i] = temp[i];
    }
}

bool satisfiesCondition() {
    for (int i = 0; i < n; i++) {
        if (p[i] != i % 3) return false;
    }
    return true;
}

void simulate() {
    int cnt = 0;
    while(1) {
        if (satisfiesCondition()) break;
        shuffle();
        cnt++;
        if (cnt > maxCnt) {
            cnt = -1;
            break;
        }
    }
    cout << cnt;
}

int main() {
    init();
    simulate();
    return 0;
}

