#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_X 30001

int calculated[MAX_X] = {0, };
int x;

int main() {
    cin >> x;
    for (int i = 2; i <= x; i++) {
        calculated[i] = calculated[i-1] + 1;
        if (i % 5 == 0)
            calculated[i] = min (calculated[i], calculated[i/5] + 1);
        if (i % 3 == 0)
            calculated[i] = min (calculated[i], calculated[i/3] + 1);
        if (i % 2 == 0)
            calculated[i] = min (calculated[i], calculated[i/2] + 1);
    }
    
    cout << calculated[x];
    return 0;
}
