// 문제 링크: https://www.acmicpc.net/problem/2947
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 5

int nums[MAX_N];
void printNums() {
    for (int i = 0; i < MAX_N; i++) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
}

bool rotate() {
   bool hasMoved = false;
   for (int i = 0; i < 4; i++) {
       if (nums[i] > nums[i + 1]) {
           swap (nums[i], nums[i + 1]);
           printNums();
           hasMoved = true;
       }
   }
   return hasMoved;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < MAX_N; i++) {
        cin >> nums[i];
    }

    while(1) {
        if (!rotate()) break;
    }

    return 0;
}
