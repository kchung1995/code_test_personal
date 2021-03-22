#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int l, c;
vector<char> vowel_list = {'a', 'e', 'i', 'o', 'u'};
vector<char> alphabets;
vector<string> words;

bool is_vowel(char input) {
    for (int i = 0; i < vowel_list.size(); i++) {
        if (input == vowel_list[i]) return true;
    }
    return false;
}

bool is_appropriate(string password) {
    int vowels = 0, consonant = 0;
    for (int i = 0; i < password.size(); i++) {
        char now = password[i];
        if (is_vowel(now)) vowels++;
        else consonant++;
    }
    
    if (vowels >= 1 && consonant >= 2) return true;
    else return false;
}

void make_word(int index, string password) {
    if (password.size() == l && is_appropriate(password)) {
        cout << password << '\n';
        return;
    }
    if (index >= c) return;
    make_word(index+1, password + alphabets[index]);
    make_word(index+1, password);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char temp;
        cin >> temp;
        alphabets.push_back(temp);
    }
    sort (alphabets.begin(), alphabets.end());
    
    make_word(0, "");
    
    return 0;
}
