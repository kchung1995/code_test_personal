#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> coins;
int target = 1;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    sort(coins.begin(), coins.end());
    
    for (int i = 0; i < n; i++) {
        if (target < coins[i]) break;
        target += coins[i];
    }
    
    cout << target;
    return 0;
}
