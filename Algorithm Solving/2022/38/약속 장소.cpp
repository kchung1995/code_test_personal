// 문제 출처: 2022 POSTECH Programming Contest Open
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, l;
vector<string> input;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        input.push_back(temp);
    }
    return;
}

vector<vector<string> > getCandidates() {
    
    // 각 자릿수별로 최대 빈도의 문자를 센다 (1개 이상 존재).
    vector<vector<string> > list(l + 1);
    
    // 각 문자의 자리를 기준으로 검사한다.
    for (int j = 0; j < l; j++) {
        unordered_map<char, int> cnt;
        int mostAppear = 0;
        
        for (int i = 0; i < n; i++) {
            char temp = input[i][j];
            if (cnt.find(temp) == cnt.end()) {
                cnt.insert({temp, 1});
                mostAppear = max(mostAppear, 1);
            }
            else {
                cnt[temp]++;
                mostAppear = max(mostAppear, cnt[temp]);
            }
        }
        
        // mostAppear만큼 등장했던 알파벳 대문자 (1개 이상)를 list에 집어넣는다.
        for (auto &next : cnt) {
            if (next.second == mostAppear) {
                string tmp_string(1, next.first);
                list[j].push_back(tmp_string);
            }
        }
    }
    
    return list;
}

bool itQualifies (string target) {
    if (target.size() != l) return false;
    
    for (string &next : input) {
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            if (next[i] != target[i]) cnt++;
        }
        if (cnt >= 2) return false;
    }
    return true;
}

void buildStr (int depth, string str, vector<vector<string> > &list, vector<string> &ans) {
    if (str.size() == l) {
        if (itQualifies(str)) {
            ans.push_back(str);
        }
        return;
    }
    
    for (int i = 0; i < list[depth].size(); i++) {
        buildStr(depth + 1, str + list[depth][i], list, ans);
    }
}

string getResult(vector<vector<string> > list) {
    
    if (input.empty()) return "CALL FRIEND";
    
    vector<string> ans;
    
    buildStr(0, "", list, ans);
    
    if (ans.empty()) {
        return "CALL FRIEND";
    }
    else return ans[0];
}

int main() {
    init();
    cout << getResult(getCandidates());
    return 0;
}

