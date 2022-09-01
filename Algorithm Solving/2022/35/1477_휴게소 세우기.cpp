// 문제 링크: https://www.acmicpc.net/problem/1477
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l;
vector<int> highway;

int binarySearch() {
    int low = 0, high = l, mid;
    int result = 0;
    
    while(low <= high) {
        mid = (low + high) / 2;
        // mid는 0이 될 수 없다.
        if (mid == 0) {
            low = mid + 1;
            continue;
        }
        
        int placing = 0;    // 현재 범위 내에서 추가 가능한 휴게소의 수
        
        // 현재 배치되어 있는 휴게소를 싹 본다.
        for (int i = 1; i < highway.size(); i++) {
            int dist = highway[i] - highway[i-1];
            
            // 두 휴게소 사이에 dist 이상의 거리를 두도록 휴게소를 몇 개 추가할 수 있나.
            placing += (dist / mid);
            // 이미 휴게소를 세운 곳에는 추가로 세울 수 없으므로 카운트를 하나 줄여 준다.
            if (dist % mid == 0) placing--;
        }
        
        // 휴게소를 기준보다 많이 세웠을 경우, 기준을 올려 보자.
        if (placing > m) low = mid + 1;
        else {
            high = mid - 1;
            result = mid;
        }
    }
    
    return result;
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // 주어진 입력을 받는다.
    // n: 현재 휴게소의 개수 n, 추가하려는 휴게소의 개수 m, 고속도로의 길이 l
    cin >> n >> m >> l;
    highway.push_back(0); highway.push_back(l); // 고속도로의 양 끝점에는 휴게소를 세울 수 없다.
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        highway.push_back(temp);
    }
    sort(highway.begin(), highway.end());
}

int main() {
    // 입력 받기
    init();
    cout << binarySearch();
    return 0;
}

