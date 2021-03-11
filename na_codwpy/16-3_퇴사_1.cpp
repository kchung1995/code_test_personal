#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 16

int t[MAX_N];
int p[MAX_N];
int dp[MAX_N];
int n, max_value = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
    
    for (int i = n; i >= 1; i--) {
        int time = i + t[i];
        if (time <= n+1) {
            dp[i] = max(p[i] + dp[t[i]+i], max_value);
            max_value = dp[i];
        }
        else dp[i] = max_value;
    }
    cout << max_value;
    return 0;
}
