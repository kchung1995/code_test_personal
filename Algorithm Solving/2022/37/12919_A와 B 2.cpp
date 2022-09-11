// 문제 링크: https://www.acmicpc.net/problem/12919
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;
bool isPossible = false;

bool strCompare(string st1, string st2) {
    if (st1.size() != st2.size()) return false;
    for (int i = 0; i < st1.size(); i++) {
        if (st1[i] != st2[i]) return false;
    }
    return true;
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> t;
}

void dfs(string a, string b) {
    if (strCompare(a, b)) {
        isPossible = true;
        return;
    }
    
    if (isPossible) return;
    if (a.size() >= b.size()) return;
    
    string temp = "";
    if (b[b.size() - 1] == 'A') {
        temp = b;
        temp.erase(temp.size() - 1);
        dfs(a, temp);
    }
    if (b[0] == 'B') {
        temp = b;
        temp.erase(temp.begin());
        reverse(temp.begin(), temp.end());
        dfs(a, temp);
    }
}

int main() {
    init();
    dfs(s, t);
    isPossible ? cout << 1 : cout << 0;
    return 0;
}

