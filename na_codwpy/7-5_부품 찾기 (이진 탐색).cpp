#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
vector<int> in_stock;
vector<int> ordered;

int binary_search(int start, int end, int target) {
    int mid = (end + start) / 2;
    if (target == ordered[mid])
        return mid;
    else if (start == end && ordered[mid] != target)
        return -1;
    else if (ordered[mid] > target)
        return binary_search(start, mid-1, target);
    else if (ordered[mid] < target)
        return binary_search(mid+1, end, target);
    else
        return -1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        in_stock.push_back(temp);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        ordered.push_back(temp);
    }
    
    sort(in_stock.begin(),in_stock.end());
    
    for (int i = 0; i < M; i++) {
        int found = binary_search(0, N-1, ordered[i]);
        if (found > 0)
            cout << "yes ";
        else
            cout << "no ";
    }
    
    return 0;
}
