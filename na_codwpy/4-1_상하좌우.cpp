#include <iostream>
#include <string>
using namespace std;

int Ax = 1, Ay = 1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char moveTypes[4] = {'R', 'D', 'L', 'U'};
string movePlan;
int N;

int main() {
    cin >> N;
    cin.ignore();
    getline(cin, movePlan);
    
    for (int i = 0; i < movePlan.size(); i++) {
        char currentPlan = movePlan[i];
        int tempx = -1, tempy = -1;
        
        for (int j = 0; j < 4; j++) {
            if (currentPlan == moveTypes[j]) {
                tempx = Ax + dx[j];
                tempy = Ay + dy[j];
            }
            
            if (tempx < 1 || tempy < 1 || tempx > N || tempy > N)
                continue;
            Ax = tempx;
            Ay = tempy;
        }
    }
    
    cout << Ax << " " << Ay;
    
    return 0;
}
