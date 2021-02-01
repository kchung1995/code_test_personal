#include <iostream>
#include <string>
using namespace std;

int knight_movesX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int knight_movesY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int initX, initY;
int possible_cases = 0;
string userInput;

int main() {
    cin >> userInput;
    initX = userInput[0] - 'a' + 1;
    initY = userInput[1] - '0';
    
    for (int i = 0; i < 8; i++) {
        int tempX = -1, tempY = -1;
        tempX = initX + knight_movesX[i];
        tempY = initY + knight_movesY[i];
        
        if (tempX < 1 || tempY < 1 || tempX > 8 || tempY > 8)
            continue;
        possible_cases++;
    }
    cout << possible_cases;
    return 0;
}
