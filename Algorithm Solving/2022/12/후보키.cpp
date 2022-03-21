// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/42890
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<vector<string>> relation;
unordered_set<int> columnCombination;
vector<unordered_set<int> > candidates;
vector<bool> is_selected;
int columns = -1;
int answer = 0;

bool isUnique(vector<vector<string> > &relation) {
    unordered_set<string> temp;
    for (int i = 0; i < relation.size(); i++) {
        string result = "";
        for (auto &next : columnCombination) {
            result += relation[i][next];
        }

        if (temp.find(result) != temp.end()) return false;
        else temp.insert(result);
    }

    return true;
}

bool isMinimal() {
    // 1개의 column으로 이루어져 있다면 무조건 최소성을 만족
    if (columnCombination.size() == 1) return true;
    
    for (int i = 0; i < candidates.size(); i++) {
        bool minimal = false;
        for (auto &key : candidates[i]) {
            if (columnCombination.find(key) == columnCombination.end()) {
                minimal = true;
                break;
            }
        }
        if (!minimal) return false;
    }
    return true;
}

// start: 시작 위치, count: 현재까지 누적 컬럼 개수, totalCount: 목표 개수
void dfs(int start, int count, int totalCount, vector<vector<string> > &relation) {
    // 조합이 만들어졌을 때,
    if (count == totalCount) {
        // 만들어진 조합이 유일성과 최소성을 만족하면 센다
        if (isUnique(relation) && isMinimal()) {
            candidates.push_back(columnCombination);
            answer++;
        }
        return;
    }
    
    // 조합에 칼럼을 하나씩 더 추가한다
    for (int i = start; i < columns; i++) {
        if (is_selected[i] == true) continue;
        is_selected[i] = true;
        columnCombination.insert(i);
        dfs(i, count+1, totalCount, relation);
        is_selected[i] = false;
        columnCombination.erase(i);
    }
}

int solution(vector<vector<string>> relation) {
    
    // db에 주어진 relation의 수
    columns = relation[0].size();
    // 선택 여부를 기록하는 bool형 배열
    is_selected.resize(columns, false);

    
    // dfs를 이용하여 가능한 조합의 경우의 수를 구한다. 
    for (int i = 1; i <= columns; i++) {
        dfs(0, 0, i, relation);
    }
    
    return answer;
}
