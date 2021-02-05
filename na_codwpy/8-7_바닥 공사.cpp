#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1001
#define DIVISOR 796796

int N;
int tiles[MAX_N] = {0, };

int main() {
    cin >> N;
    tiles[1] = 1;
    tiles[2] = 3;
    
    for (int i = 3; i <= N; i++)
        tiles[i] = (tiles[i-1] + tiles[i-2]*2) % DIVISOR;
    
    cout << tiles[N];
    return 0;
}
