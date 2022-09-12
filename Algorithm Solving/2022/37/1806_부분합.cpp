// 문제 출처: https://www.acmicpc.net/problem/1806
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<int> seq;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        seq.push_back(temp);
    }
}

int search() {
    int answer = 1e9;
    
    int a = 0, b = 0;
    int sum = seq[0];
    
    while (b < n) {
        if (sum >= s) {
            answer = min(answer, b - a + 1);
            sum -= seq[a];
            a++;
        }
        else {
            b++;
            sum += seq[b];
        }
    }
    
    // 만드는 것이 불가능한 경우
    if (answer == 1e9) return 0;
    return answer;
}

int main() {
    init();
    cout << search();
    return 0;
}

