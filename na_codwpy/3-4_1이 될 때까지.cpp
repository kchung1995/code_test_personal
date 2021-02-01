#include <iostream>
using namespace std;

int N, K;
int calc_count = 0;

int main() {
    cin >> N >> K;
    while (N != 1) {
        if (N % K == 0) {
            N /= K;
            calc_count++;
        }
        else {
            int temp = N % K;
            N -= temp;
            calc_count += temp;
        }
    }
    
    cout << calc_count;
    return 0;
}
