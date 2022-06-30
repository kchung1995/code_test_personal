// 문제 링크: https://www.acmicpc.net/problem/2805
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> trees;

int binary_search(int start, int end, int target) {
    int result;
    while (start <= end) {
        long long cutted_tree = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < n; i++) {
            if (trees[i] > mid) {
                cutted_tree += (trees[i] - mid);
            }
        }
        if (cutted_tree < target)
            end = mid - 1;
        else {
            result = mid;
            start = mid + 1;
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        trees.push_back(temp);
    }
    
    cout << binary_search(0, 1e9, m);
    return 0;
}
