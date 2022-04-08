// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12978
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 51
#define INF 1e9

int d[MAX_N][MAX_N];

void init(int &n, vector<vector<int> > &road) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }
    
    for (auto &next : road) {
        d[next[0]][next[1]] = min(d[next[0]][next[1]], next[2]);
        d[next[1]][next[0]] = min(d[next[1]][next[0]], next[2]);
    }
}

void floydWarshall (int &n) {
    
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
            }
        }
    }
}

int lessOrEqualToK (int &n, int &k) {
    int count = 1;
    for (int i = 2; i <= n; i++) {
        if (d[1][i] <= k) count++;
    }
    return count;
}

int solution(int n, vector<vector<int> > road, int k) {
    
    // 플로이드-와셜 알고리즘 사용
    init(n, road);
    floydWarshall(n);
    
    return lessOrEqualToK(n, k);;
}
