// 문제 링크: https://www.acmicpc.net/problem/7662
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int t;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
}

void simulate() {
    int k;
    priority_queue<int> maxval;
    priority_queue<int, vector<int>, greater<int> > minval;
    vector<int> domain;
    int queuecount = 0;
    unordered_map<int, int> maxvalRemoved;
    unordered_map<int, int> minvalRemoved;
    
    cin >> k;
    
    // pq를 두개 둔다. 여기서 삽입, 삭제되는 시간복잡도를 줄일 수 있다.
    while(k--) {
        char cmd; int option;
        cin >> cmd >> option;
        
        switch(cmd) {
            case 'I':
                maxval.push(option);
                minval.push(option);
                domain.push_back(option);
                maxvalRemoved.insert({option, 0});
                minvalRemoved.insert({option, 0});
                queuecount++;
                break;
            case 'D':
                if (queuecount == 0) break;
                queuecount--;
                if (option == 1) {
                    while (minvalRemoved[maxval.top()] > 0) {
                        minvalRemoved[maxval.top()]--;
                        maxval.pop();
                    }
                    maxvalRemoved[maxval.top()]++;
                    maxval.pop();
                }
                if (option == -1) {
                    while (maxvalRemoved[minval.top()] > 0) {
                        maxvalRemoved[minval.top()]--;
                        minval.pop();
                    }
                    minvalRemoved[minval.top()]++;
                    minval.pop();
                }
                break;
        }
    }
    
    vector<int> result;
    unordered_set<int> maxres;
    unordered_set<int> minres;
    
    while(!maxval.empty()) {
        maxres.insert(maxval.top());
        maxval.pop();
    }
    
    while(!minval.empty()) {
        minres.insert(minval.top());
        minval.pop();
    }
    
    for (int i = 0; i < domain.size(); i++) {
        int next = domain[i];
        if (maxres.find(next) != maxres.end() && minres.find(next) != minres.end()) {
            result.push_back(next);
        }
    }
    
    if (queuecount == 0 || result.size() == 0) {
        cout << "EMPTY\n"; return;
    }
    
    sort(result.begin(), result.end());
    
    // 값이 단 하나뿐인 경우
    if (result.size() == 1) {
        cout << result[0] << ' ' << result[0] << '\n';
        return;
    }
    cout << result.back() << ' ' << result[0] << '\n';
    return;
}

int main() {
    init();
    while(t--) {
        simulate();
    }
    
    return 0;
}

