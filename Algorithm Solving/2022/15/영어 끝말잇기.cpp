// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12981
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
   
    int count = 0;
    vector<int> answer;
    unordered_set<string> used;
    bool failed = false;
    char prev = '-';
    
    for (auto &next : words) {
        // 끝말에 맞는 단어를 말하지 않은 경우 실패
        if (prev != '-' && next[0] != prev) {
            failed = true;
            break;
        }
        // 제대로 말한 경우 성공
        else if (used.find(next) == used.end()) {
            used.insert(next);
            prev = next.back();
            count++;
        }
        // 이미 사용한 단어를 또 사용한 경우 실패
        else {
            failed = true;
            break;
        }
    }
    
    if (!failed) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back((count % n) + 1);
        answer.push_back((count / n) + 1);
    }

    return answer;
}
