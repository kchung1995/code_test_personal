// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/1845
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> ponkemons;
    
    for (auto &next : nums) {
        ponkemons.insert(next);
    }
    
    if (ponkemons.size() > (nums.size() / 2)) {
        return nums.size() / 2;
    }
    else return ponkemons.size();

}
