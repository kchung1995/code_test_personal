#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100000

int N;
priority_queue<int> terror;
int groups = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        terror.push(-temp);
    }
    
    int group_members = 0;
    while(!terror.empty()) {
        int now = -terror.top();
        terror.pop();
        group_members++;
        if (group_members == now) {
            groups++;
            group_members = 0;
        }
    }
    
    cout << groups;
    return 0;
}
