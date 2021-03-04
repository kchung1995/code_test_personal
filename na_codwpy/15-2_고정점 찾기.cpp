#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> numbers;
int fixed_point = -1;

int find_fixed_point(int start, int end) {
    if (start > end) return -1;
    int mid = (end + start)/2;
    if (mid == numbers[mid]) {
        return mid;
    }
    else if (mid > numbers[mid]) {
        return find_fixed_point(mid+1,end);
    }
    else
        return find_fixed_point(start, mid-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    
    cout << find_fixed_point(0, n-1);
    return 0;
}
