#include <iostream>
#include <string>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    int cnt = 0;
    for (int h = 0; h <= n; h++) {
        for (int m = 0; m <= 59; m++) {
            for (int s = 0; s <= 59; s++) {
                if (h != 0 && (h / 10 == 3 || h % 10 == 3)) {
                    cnt++;
                }
                else if (m != 0 && (m/10 == 3 || m%10 == 3))
                    cnt++;
                else if (s != 0 && (s/10 == 3 || s%10 == 3))
                    cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
