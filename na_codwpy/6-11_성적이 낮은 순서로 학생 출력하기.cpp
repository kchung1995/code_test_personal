#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <pair<int, string> > grades;
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string name;
        int score;
        cin >> name >> score;
        grades.push_back(make_pair(score, name));
    }
    
    sort(grades.begin(),grades.end());
    
    for (int i = 0; i < N; i++) {
        cout << grades[i].second << " ";
    }
    return 0;
}
