// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/17677
#include <string>
#include <vector>
#include <unordered_map>
#define CONST 65536

using namespace std;
vector<string> input1;
vector<string> input2;
unordered_map<string, int> hap1;
unordered_map<string, int> hap2;
unordered_map<string, int> gyo;

bool isAlphabet (char c) {
    if ('a' <= c && c <= 'z') return true;
    if ('A' <= c && c <= 'Z') return true;
    return false;
}

char toUpper (char c) {
    if ('a' <= c && c <= 'z') return (c - 32);
    else return c;
}

void stringParse(string &input, int dest) {
    for (int i = 0; i < input.size() - 1; i++) {
        // 알파벳이 아닌 경우 넘어감
        if (!isAlphabet(input[i]) || !isAlphabet(input[i+1])) continue;
        string temp = "";
        temp = temp + toUpper(input[i]) + toUpper(input[i+1]);
        if (dest == 1) input1.push_back(temp);
        else if (dest == 2) input2.push_back(temp);
    }
}

void addToSets() {
    // 먼저 str1의 부분집합을 hap1에 넣음
    for (auto &next : input1) {
        if (hap1.find(next) == hap1.end())
            hap1.insert({next, 1});
        else hap1[next]++;
    }
    
    // 그 다음, st2를 검사
    for (auto &next : input2) {
        // hap1에 있었다면 교집합의 원소가 된다.
        if (hap1.find(next) != hap1.end()) {
            if (hap1[next] > 1) hap1[next]--;
            else hap1.erase(next);
            
            if (gyo.find(next) == gyo.end())
                gyo.insert({next, 1});
            else gyo[next]++;
        }
        // hap1에 없었다면 교집합의 원소가 아니다.
        else {
            if (hap2.find(next) == hap2.end())
                hap2.insert({next, 1});
            else hap2[next]++;
        }
    }
}

int solution(string str1, string str2) {
    
    // 문자열의 다중집합을 만들어 배열에 넣음
    stringParse(str1, 1);
    stringParse(str2, 2);
    
    // 문자열을 map에 집어넣음
    addToSets();
    
    // 교집합과 합집합의 원소의 수를 각각 구함
    int intersection = 0, unionval = 0;
    for (auto &next : gyo) {
        intersection += next.second;
    }
    for (auto &next : hap1) {
        unionval += next.second;
    }
    for (auto &next : hap2) {
        unionval += next.second;
    }
    unionval += intersection;

    // 둘 다 공집합인 경우, 정의에 의해 자카드 유사도는 1이 된다.
    if (unionval == 0 && intersection == 0) return CONST;
    else return ((CONST * intersection) / unionval);
    
}
