#include <iostream>
using namespace std;

#define MAX_N 50
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};      //북 동 남 서

int grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int curx, cury, direction;
int move_count = 1;

int N, M;

void turn_left() {
    direction -= 1;
    if (direction == -1) direction = 3;
}

int main() {
    cin >> N >> M;
    cin >> curx >> cury >> direction;
    visited[curx][cury] = 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    
    int turn_count = 0;
    while(1) {
        turn_left();
        int nx = curx + dx[direction];
        int ny = cury + dy[direction];
        
        if (grid[nx][ny] == 0 && visited[nx][ny] == 0) {
            visited[nx][ny] = 1;
            curx = nx;
            cury = ny;
            move_count++;
            turn_count = 0;
            continue;
        }
        else turn_count++;
        
        if (turn_count == 4) {
            nx = curx - dx[direction];
            ny = cury - dy[direction];
            
            if (grid[nx][ny] == 0) {
                curx = nx;
                cury = ny;
            }
            else break;
            turn_count = 0;
        }
    }
    
    cout << move_count;
    return 0;
}

