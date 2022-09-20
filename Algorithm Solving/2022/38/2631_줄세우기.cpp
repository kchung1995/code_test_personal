// 문제 링크: https://www.acmicpc.net/problem/2631
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 201

int n;
vector<int> lineup;
int dp[MAX_N];

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        lineup.push_back(temp);
    }
}

int getMaximumSubsetSize() {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j <= i; j++) {
            if (lineup[j] < lineup[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        
        answer = max(answer, dp[i]);
    }
    
    return answer;
}

int main() {
    init();
    cout << n - getMaximumSubsetSize();
    return 0;
}

