#include <iostream>
#include <string>
using namespace std;

string input;
int input_len;
int alphabet[26];
int numbers = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
    input_len = input.size();
    
    for (int i = 0; i < input_len; i++) {
        int temp = input[i] - '0';
        if (temp >= 10)
            alphabet[input[i] - 'A']++;
        else
            numbers += input[i] - '0';
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alphabet[i]; j++)
            cout << char(i + 'A');
    }
    cout << numbers;
    return 0;
}
