#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int n;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
}

int simulate() {
    int result = 0;
    while(n--) {
        string temp; cin >> temp;
        istringstream ss(temp);
        string buffer;
        vector<string> splits;
        
        while(getline(ss, buffer, '-')) {
            splits.push_back(buffer);
        }
        
        int remainingDate = stoi(splits[1]);
        if (remainingDate <= 90) {
            result++;
        }
    }
    
    return result;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
