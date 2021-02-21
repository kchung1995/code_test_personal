#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1000000
#define MAX_M 2000000000 //20억

int N, M, teok_start, teok_end;
vector<int> teok_height;

int binary_search(int start, int end, int target) {
    int result = 0;
    while (start <= end) {
        long long int cutted_teok = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < N; i++) {
            if (teok_height[i] > mid)
                cutted_teok += teok_height[i] - mid;
        }
        if (cutted_teok < target)
            end = mid - 1;
        else {
            result = mid;
            start = mid + 1;
        }
    }
    return result;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        teok_height.push_back(temp);
    }
    
    int result = binary_search(0, 1e9, M);
    cout << result;
    
    return 0;
}

