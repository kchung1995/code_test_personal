// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/17680
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int totalTime = 0;
const int miss = 5;
const int hit = 1;
vector<string> recentlyUsed;
unordered_set<string> cached;

using namespace std;

void toLowercase (vector<string> &cities) {
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].size(); j++) {
            if ('A' <= cities[i][j] && cities[i][j] <= 'Z') {
                cities[i][j] += 32;
            }
        }
    }
}

int solution(int cacheSize, vector<string> cities) {
    
    if (cacheSize == 0) return (5* cities.size());
    
    toLowercase(cities);
    
    // cached: 캐시된 도시 이름 목록만을 관리
    // recentlyUsed: 오래 된 도시 이름일수록 앞에 위치
    
    for (auto &city : cities) {
        
        // 새 도시 이름이 캐시에 없는 경우
        if (cached.find(city) == cached.end()) {
            totalTime += miss;
            // 캐시 사이즈가 다 찬 경우
            if (recentlyUsed.size() == cacheSize) {
                if (cacheSize != 0) {
                    cached.erase(recentlyUsed[0]);
                    recentlyUsed.erase(recentlyUsed.begin());
                }
            }
            cached.insert(city);
            recentlyUsed.push_back(city);
        }
        // 새 도시 이름이 캐시에 있는 경우
        else {
            totalTime += hit;
            // 도시 이름을 recentlyUsed에서 찾고, 제거한 후 다시 push
            int i = 0;
            for (i; i < recentlyUsed.size(); i++) {
                if (recentlyUsed[i] == city) {
                    break;
                }
            }
            recentlyUsed.erase(recentlyUsed.begin() + i);
            recentlyUsed.push_back(city);
        }
    }
    
    return totalTime;
}
