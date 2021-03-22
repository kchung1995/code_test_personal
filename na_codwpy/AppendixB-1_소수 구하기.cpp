#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N 1000001

bool primes[MAX_N] = {true};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> m >> n;
    
    primes[1] = false;
    for (int i = 2; i <= n; i++) {
        primes[i] = true;
    }
    for (int i = 2; i <= sqrt(n) + 1; i++) {
        if (primes[i]) {
            int j = 2;
            while (i*j <= n) {
                primes[i*j] = false;
                j++;
            }
        }
    }
    
    for (int i = m; i <= n; i++) {
        if (primes[i]) cout << i << '\n';
    }
    
    return 0;
}
