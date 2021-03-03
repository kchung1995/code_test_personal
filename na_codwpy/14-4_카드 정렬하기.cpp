#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> cards;
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i= 0; i < n; i++) {
        int temp;
        cin >> temp;
        cards.push(-temp);
    }
    
    int answer = 0;
    while (cards.size() != 1) {
        int first = -cards.top();
        cards.pop();
        int second = -cards.top();
        cards.pop();
        int sum = first + second;
        answer += sum;
        cards.push(-sum);
    }
    cout << answer;
    return 0;
}
