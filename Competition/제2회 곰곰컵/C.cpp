#include <iostream>
using namespace std;

long long a, b, c;
long long x, y, z;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    cin >> x >> y >> z;
}

long long countFirst(long long &i, long long &j) {
    long long result = 0;
    if (i >= j) {
        result = j;
        i -= j;
        j = 0;
    }
    else {
        result = i;
        j -= i;
        i = 0;
    }
    return result;
}

long long simulate() {
    long long countGomgom = 0;
    
    // 먼저 식권대로 먹을 수 있는 곰곰이들을 센다.
    countGomgom += countFirst(a, x);
    countGomgom += countFirst(b, y);
    countGomgom += countFirst(c, z);
    
    while(1) {
        long long tempGomgom = countGomgom;
        // 해당 음식을 원하는 곰곰이가 없고, 티켓이 남은 경우를 확인한다.
        if (a == 0) {
            y += (x / 3);
            x %= 3;
            countGomgom += countFirst(b, y);
        }
        if (b == 0) {
            z += (y / 3);
            y %= 3;
            countGomgom += countFirst(c, z);
        }
        if (c == 0) {
            x += (z / 3);
            z %= 3;
            countGomgom += countFirst(a, x);
        }
        
        if (tempGomgom == countGomgom) {
            break;
        }
    }
    
    return countGomgom;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
