#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string input;
int zero = 0, one = 0;
int s;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
    
    char current_char = 'a';
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != current_char) {
            current_char = input[i];
            if (current_char == '0')
                zero++;
            else if (current_char == '1')
                one++;
        }
    }
    
    cout << min(zero, one);
    return 0;
}
