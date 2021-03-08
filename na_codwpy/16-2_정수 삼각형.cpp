#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 500

int memo[MAX_N][MAX_N];
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            cin >> memo[i][j];
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int left, right;
            if (j == 0) left = 0;
            else left = memo[i-1][j-1];
            if (j == i) right = 0;
            else right = memo[i-1][j];
            memo[i][j] += max(left, right);
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, memo[n-1][i]);
    }
    cout << result;
    
    return 0;
}
