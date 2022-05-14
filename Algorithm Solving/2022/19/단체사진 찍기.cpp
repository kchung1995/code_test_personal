// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/1835
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int answer;

bool equalsTo (int a, int b, int dist) {
    if ((abs(a-b) - 1) == dist) return true;
    else return false;
}

bool lessThan (int a, int b, int dist) {
    if ((abs(a-b) - 1) < dist) return true;
    else return false;
}

bool furtherThan (int a, int b, int dist) {
    if ((abs(a-b) - 1) > dist) return true;
    else return false;
}

void satisfyCondition(string input, vector<string> &data) {
    bool satisfiesAll = true;
    
    for (auto &condition : data) {
        int a, b;
        int dist = (condition[4] - '0');
        for (int i = 0; i < input.size(); i++) {
            if (condition[0] == input[i]) a = i;
            if (condition[2] == input[i]) b = i;
        }
        
        if (condition[3] == '=') {
            if (equalsTo(a, b, dist) == false) {
                satisfiesAll = false;
            }
        }
        else if (condition[3] == '<') {
            if (lessThan(a, b, dist) == false) {
                satisfiesAll = false;
            }
        }
        else if (condition[3] == '>') {
            if (furtherThan(a, b, dist) == false) {
                satisfiesAll = false;
            }
        }
    }
    
    if (satisfiesAll) answer++;
    return;
}

void lineup(string input, set<int> occupied, vector<char> &friends, vector<string> &data) {
    
    if (input.size() == friends.size()) {
        satisfyCondition(input, data);
        return;
    }

    else {
        for (int i = 0; i < friends.size(); i++) {
            if (occupied.find(i) == occupied.end()) {
                string nextInput = input + friends[i];
                occupied.insert(i);
                lineup(nextInput, occupied, friends, data);
                occupied.erase(i);
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    
    answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    set<int> occupiedInit;
    lineup("", occupiedInit, friends, data);
    
    return answer;
}
