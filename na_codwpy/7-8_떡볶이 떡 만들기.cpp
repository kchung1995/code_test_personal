#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1000000
#define MAX_M 2000000000 //20억

int N, M, if_result;
vector<int> teok_height;

int binary_search(int start, int end, int target) {
    int mid = (end+start)/2;
    int cutted_teok = 0;
    for (int i = 0; i < N; i++) {
        if (teok_height[i] > mid)
            cutted_teok += (teok_height[i] - mid);
    }
    if (cutted_teok == target)
        return mid;
    else if (start == end && cutted_teok != target)
        return -1;
    else if (cutted_teok > target) {
        if_result = mid;
        return binary_search(mid+1, end, target);
    }
    else if (cutted_teok < target)
        return binary_search(start, mid-1, target);
    else
        return -1;
}

int main() {
    cin >> N >> M;
    int max_teok_length = -1;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        teok_height.push_back(temp);
        max_teok_length = max(max_teok_length, temp);
    }
    
    int result = binary_search(0, max_teok_length, M);
    if (result > 0)
        cout << result;
    else
        cout << if_result;
    
    return 0;
}
