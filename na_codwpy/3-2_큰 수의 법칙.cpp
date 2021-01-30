#include <iostream>
using namespace std;

int N, M, K;
int first = 0, second = 0;
int result = 0;

int main() {
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp > first) {
            second = first;
            first = temp;
        }
        else if (temp > second)
            second = temp;
    }
    
    int divisor = M / (K+1);
    result = (M-divisor)*first + divisor*second;
    cout << result;
    
    return 0;
}
