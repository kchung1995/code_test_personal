// 문제 링크: https://www.acmicpc.net/problem/2493
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> poll;
stack<pair<int, int> > polls;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

bool cmpResult(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        poll.push_back(temp);
//        polls.push({temp, i});
    }
}

void simulate() {
    for (int i = 0; i < n; i++) {
        while(!polls.empty()) {
            if (polls.top().first > poll[i]) {
                cout << polls.top().second << ' ';
                polls.push({poll[i], i + 1});
                break;
            }
            polls.pop();
        }
        if (polls.empty()) {
            cout << 0 << ' ';
            polls.push({poll[i], i + 1});
        }
        
    }
}

int main() {
    init();
    simulate();
    return 0;
}

