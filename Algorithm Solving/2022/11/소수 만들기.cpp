// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12977
#include <vector>
#include <iostream>
#include <set>
#define MAX_P 3000
using namespace std;

set<int> primes;

void primesInit() {
    for (int i = 1; i <= MAX_P; i++) {
        primes.insert(i);
    }
    
    for (int i = 2; i <= MAX_P; i++) {
        if (primes.find(i) != primes.end()) {
            for (int j = i+i; j <= MAX_P; j+=i) {
                primes.erase(j);
            }
        }
    }
}

int solution(vector<int> nums) {
    
    int answer = 0;
    primesInit();
    
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i+1; j < nums.size() - 1; j++) {
            for (int k = j+1; k < nums.size(); k++) {
                int number = nums[i] + nums[j] + nums[k];
                if (primes.find(number) != primes.end()) answer++;
            }
        }
    }

    return answer;
}
