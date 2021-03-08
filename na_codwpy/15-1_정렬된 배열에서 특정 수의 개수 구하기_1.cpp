#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int> numbers;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    
    vector<int>::iterator left_boundary = lower_bound(numbers.begin(), numbers.end(), x);
    vector<int>::iterator right_boundary = upper_bound(numbers.begin(), numbers.end(), x);
    cout << right_boundary-left_boundary;
    
    return 0;
}
