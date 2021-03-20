#include <iostream>
#include <string>
using namespace std;
#define MAX_N 101

int land[MAX_N][MAX_N];
string movePlan;

//L, R, U, D
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n;
int x = 1, y = 1;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; cin.ignore(); getline(cin, movePlan);
    for (int i = 0; i < movePlan.size(); i++) {
        int tempX, tempY;
        if (movePlan[i] == 'L') {
            tempX = x + dx[0];
            tempY = y + dy[0];
        }
        else if (movePlan[i] == 'R') {
            tempX = x + dx[1];
            tempY = y + dy[1];
        }
        else if (movePlan[i] == 'U') {
            tempX = x + dx[2];
            tempY = y + dy[2];
        }
        else if (movePlan[i] == 'D') {
            tempX = x + dx[3];
            tempY = y + dy[3];
        }
        if (tempX < 1 || tempY < 1 || tempX > n || tempY > n) continue;
        x = tempX;
        y = tempY;
    }
    cout << x << " " << y;
    return 0;
}
