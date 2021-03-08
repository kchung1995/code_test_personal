#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 20

int mine[MAX_N][MAX_N];
int memo[MAX_N][MAX_N];
int t, n, m;

void initial() {
    n = 0;
    m = 0;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            mine[i][j]  = 0;
            memo[i][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int round = 0; round < t; round++) {
        initial();
        cin >> n >> m;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mine[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                memo[i][j] = mine[i][j];
            }
        }
        
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int leftup, leftdown, leftmid;
                if (i == 0) leftup = 0;
                else leftup = memo[i-1][j-1];
                if (i == n-1) leftdown = 0;
                else leftdown = memo[i+1][j-1];
                leftmid = memo[i][j-1];
                memo[i][j] += max(leftmid, max(leftup, leftdown));
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = max(answer, memo[i][m-1]);
        }
        cout << answer << '\n';
    }
    return 0;
}
