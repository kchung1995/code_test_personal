#include <iostream>
#include <string>
using namespace std;

string input;
int input_len;
int left_in = 0, right_in = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> input;
    input_len = input.size();
    
    for (int i = 0; i < (input_len / 2); i++)
        left_in += (input[i] - '0');
    
    for (int i = input_len / 2; i < input_len; i++)
        right_in += (input[i] - '0');
    
    if (left_in == right_in)
        cout << "LUCKY";
    else cout << "READY";
    
    return 0;
}
