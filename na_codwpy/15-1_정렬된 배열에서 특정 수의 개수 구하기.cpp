#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1000000

vector<int> numbers;
int n, x;

int countByRange(vector<int> numbers, int left_val, int right_val) {
    vector<int>::iterator right_index = upper_bound(numbers.begin(), numbers.end(), right_val);
    vector<int>::iterator left_index = lower_bound(numbers.begin(), numbers.end(), left_val);
    return right_index - left_index;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    
    int count = countByRange(numbers, x, x);
    
    if (count == 0) cout << -1;
    else cout << count;
    
    return 0;
}
