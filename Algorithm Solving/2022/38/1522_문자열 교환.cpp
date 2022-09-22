// 문제 링크: https://www.acmicpc.net/problem/1522
#include <iostream>
#include <string>
using namespace std;

string input;
int aCount = 0;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
    for (char &n : input) {
        if (n == 'a') aCount++;
    }
}

int simulate() {
    int answer = input.size();
    
    for (int i = 0; i < input.size(); i++) {
        int tempCount = aCount;
        int temp = 0;
        
        for (int j = i; j < i + input.size(); j++) {
            if (tempCount == 0) break;
            if (input[j % input.size()] == 'b') {
                tempCount--;
                temp++;
            }
            else {
                tempCount--;
            }
        }
        answer = min(answer, temp);
    }
    
    return answer;
}

int main() {
    init();
    cout << simulate();
    return 0;
}

