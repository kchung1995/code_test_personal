#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> houses;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        houses.push_back(temp);
    }
    
    sort(houses.begin(), houses.end());
    cout << houses[(n-1)/2];
    
    return 0;
}
