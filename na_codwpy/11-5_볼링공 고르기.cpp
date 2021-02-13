#include <iostream>
using namespace std;

int n, m;
int combination = 0;
int each_weight[11];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        each_weight[temp]++;
    }
    
    for (int i = 1; i <= m; i++) {
        n -= each_weight[i];
        combination += each_weight[i] * n;
    }
    
    cout << combination;
    return 0;
}
