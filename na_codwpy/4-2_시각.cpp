#include <iostream>
using namespace std;

int N;
int counter = 0;

int main() {
    cin >> N;
    
    int h, m, s;
    for (int i = 0; i <= N; i++) {
        h = i;
        for (int j = 0; j <= 59; j++) {
            m = j;
            for (int k = 0; k <= 59; k++) {
                s = k;
                if (h != 0 && (h / 10 == 3 || h % 10 == 3))
                    counter++;
                else if (m != 0 && (m / 10 == 3 || m % 10 == 3))
                    counter++;
                else if (s != 0 && (s / 10 == 3 || s % 10 == 3))
                    counter++;
            }
        }
    }
    
    cout << counter;
    return 0;
}
