#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 101
#define MAX_M 10001

int N, M;
int coins[MAX_N];
int number_added[MAX_M];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    
    for (int i = 0; i <= M; i++)
        number_added[i] = MAX_M;
    number_added[0] = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = coins[i]; j <= M; j++) {
            number_added[j] = min(number_added[j], number_added[j-coins[i]] + 1);
        }
    }

    if (number_added[M] == 10001)
        cout << -1;
    else
        cout << number_added[M];
    return 0;
}

