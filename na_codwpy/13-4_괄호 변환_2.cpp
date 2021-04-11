#include <string>
#include <vector>
#include <stack>

using namespace std;

int balanced_string_index(string input) {
    int sensor = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(')
            sensor++;
        else if (input[i] == ')')
            sensor--;
        if (sensor == 0)
            return i;
    }
    return -1;
}

bool is_proper (string input) {
    stack <char> characters;
    if (input[0] == ')') return false;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(')
            characters.push('(');
        else if (input[i] == ')')
            characters.pop();
    }
    if (characters.empty()) return true;
    else return false;
}

string solution(string p) {
    string answer = "";
    if (p == "") return answer;
    
    string u, v;
    int balanced = balanced_string_index(p);
    u = p.substr(0, balanced+1);
    v = p.substr(balanced+1);
    if (is_proper(u))
        answer = u + solution(v);
    else {
        string buffer = "(";
        buffer = buffer + solution(v);
        buffer = buffer + ")";
        u = u.substr(1);
        for (int i = 0; i < (int)u.size() - 1; i++) {
            if (u[i] == '(')
                buffer = buffer + ')';
            else if (u[i] == ')')
                buffer = buffer + '(';
        }
        answer = buffer;
    }
    
    return answer;
}