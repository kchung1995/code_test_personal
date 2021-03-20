#include <iostream>
#include <string>
using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
string input;

bool in_boundary(int x, int y) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
    
    int x = input[0] - 'a';
    int y = input[1] - '0' - 1;
    
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (in_boundary(nx, ny)) count++;
    }
    cout << count;
    return 0;
}
