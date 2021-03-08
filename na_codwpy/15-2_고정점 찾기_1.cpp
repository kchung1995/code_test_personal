#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> numbers;
int fixed_point = -1;

int bfs(int start, int end) {
    int mid = (start + end) / 2;
    if (start > end) return -1;
    if (numbers[mid] == mid)
        return mid;
    else if (mid > numbers[mid])
        return bfs(mid+1, end);
    else
        return bfs(start, mid-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    
    fixed_point = bfs(0, n-1);
    cout << fixed_point;
    return 0;
}
