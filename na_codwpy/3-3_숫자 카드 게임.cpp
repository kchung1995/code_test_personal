#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000

int matrix[MAX_N][MAX_N];
int N, M;
int max_n = -1;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        int local_min = 10001;
        for (int j = 0; j < M; j++) {
            local_min = min(local_min, matrix[i][j]);
        }
        max_n = max(local_min, max_n);
    }
    
    cout << max_n;
    return 0;
}
