#include <iostream>
#include <string>
using namespace std;

string input;
long long result = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
    
    result = input[0] - '0';
    for (int i = 1; i < input.size(); i++) {
        long long current = input[i] - '0';
        if (result <= 1 || current <= 1)
            result += current;
        else
            result *= current;
    }
    
    cout << result;
    return 0;
}
