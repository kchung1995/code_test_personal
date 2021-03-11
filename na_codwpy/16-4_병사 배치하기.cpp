#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 2001

int n;
vector<int> soldiers;
int dp[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        soldiers.push_back(temp);
    }
    
    reverse(soldiers.begin(), soldiers.end());
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (soldiers[j] < soldiers[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    int max_value = 0;
    for (int i = 0; i < n; i++) {
        max_value = max(max_value, dp[i]);
    }
    
    cout << n - max_value;
    return 0;
}
