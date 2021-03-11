#include <iostream>
#include <string>
using namespace std;
#define MAX_D 5001


string input, target;
int dp[MAX_D][MAX_D] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input >> target;
    int input_len = input.size();
    int target_len = target.size();
    
    for (int i = 1; i <= input_len; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= target_len; i++) {
        dp[0][i] = i;
    }
    
    for (int i = 1; i <= input_len; i++) {
        for (int j = 1; j <= target_len; j++) {
            if (input[i-1] == target[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
        }
    }
    
    cout << dp[input_len][target_len];
    return 0;
}
