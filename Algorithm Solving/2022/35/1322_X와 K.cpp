// 문제 링크: https://www.acmicpc.net/problem/1322 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

long long x, k;
long long answer = 0;
vector<int> list;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> x >> k;
    int i = 0;
    int j = 0;
    while(k > 0) {
        if (!((x >> i) & 1)) {
            answer |= ((k >> j) & 1) << i;
            j++;
            if (!(k>>j)) break;
        }
        i++;
    }
    
    cout << answer;
    
    return 0;
}
