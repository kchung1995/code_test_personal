#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int ugly[MAX_N];
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    int i2 = 0, i3 = 0, i5 = 0;
    int next2 = 2, next3 = 3, next5 = 5;
    ugly[0] = 1;
    
    for (int index = 1; index < n; index++) {
        ugly[index] = min (next2, min(next3, next5));
        
        if (ugly[index] == next2) {
            i2++;
            next2 = ugly[i2] * 2;
        }
        if (ugly[index] == next3) {
            i3++;
            next3 = ugly[i3] * 3;
        }
        if (ugly[index] == next5) {
            i5++;
            next5 = ugly[i5] * 5;
        }
    }
    
    cout << ugly[n-1];
    return 0;
}
