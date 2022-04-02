// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12906
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int curr = -1;
    
    for (auto &next : arr) {
        if (curr == next) {
            continue;
        }
        else {
            answer.push_back(next);
            curr = next;
        }
    }

    return answer;
}
