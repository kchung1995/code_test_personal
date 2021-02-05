#include <iostream>
using namespace std;
#define MAX_N 101

int N;
int foods[MAX_N];
int stolen[MAX_N] = {0, };

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> foods[i];
    }
    stolen[0] = foods[0];
    stolen[1] = max(foods[0],foods[1]);
    for (int i = 2; i < N; i++) {
        stolen[i] = max(stolen[i-1], stolen[i-2] + foods[i]);
    }
    
    cout << stolen[N-1];
    return 0;
}
