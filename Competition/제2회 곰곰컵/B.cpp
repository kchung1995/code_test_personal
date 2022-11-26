#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int n;
unordered_set<string> dancing;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dancing.insert("ChongChong");
}

int simulate() {
    for (int i = 0; i < n; i++) {
        string person1, person2;
        cin >> person1 >> person2;
        
        // 둘 중 한명이라도 무지개 댄스 중이면
        if (dancing.find(person1) != dancing.end() || dancing.find(person2) != dancing.end()) {
            dancing.insert(person1);
            dancing.insert(person2);
        }
    }
    return dancing.size();
}

int main() {
    init();
    cout << simulate();
    return 0;
}
