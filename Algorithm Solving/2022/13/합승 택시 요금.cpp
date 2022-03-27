// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/72413
#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 201
#define INF 1e8

using namespace std;

int d[MAX_N][MAX_N];

void floydWarshall(int &n, vector<vector<int> > &fares) {
    
    // 초기 주어진 거리 설정
    for (auto &next : fares) {
        d[next[0]][next[1]] = next[2];
        d[next[1]][next[0]] = next[2];
    }
    
    // 플로이드 와셜 3중 for문
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++)
                d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
        }
    }
}

void init(int &n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = INF;
        }
    }
}

// 지점 (노드)의 수 3 <= n <= 200
// s, a, b는 각각 서로 다른 n 이하의 자연수, 서로 겹치지 않는다.
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    int answer = INF;
  
    init(n);
    // 플로이드 와셜 알고리즘
    floydWarshall(n, fares);
    
    // 환승점 c를 기준으로, a와 b가 갈라지는 경우
    for (int c = 1; c <= n; c++) {
        answer = min(answer, d[s][c] + d[c][a] + d[c][b]);
    }
    // 환승점이 a 또는 b의 목적지인 경우
    answer = min(answer, min(d[s][a] + d[a][b], d[s][b] + d[b][a]));
    // 합승을 하지 않을 때 더 저렴한 경우, 합승을 하지 않는다.
    answer = min(answer, d[s][a] + d[s][b]);
    
    return answer;
}
