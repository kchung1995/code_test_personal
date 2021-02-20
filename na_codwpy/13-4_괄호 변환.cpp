#include <string>
#include <vector>

using namespace std;

int balanced_string_index(string p) {
    int brackets = 0;
    int string_size = p.size();
    for (int i = 0; i < string_size; i++) {
        if (p[i]  == '(')
            brackets++;
        else if (p[i] == ')')
            brackets--;
        if (brackets == 0)
            return i;
    }
    return -1;
}

bool check_proper_string(string p) {
    int left_b = 0;
    int string_size = p.size();
    for (int i = 0; i < string_size; i++) {
        if (p[i] == '(')
            left_b++;
        else if (p[i] == ')')
            left_b--;
        if (left_b < 0)
            return false;
    }
    if (left_b == 0)
        return true;
}

string solution(string p) {
    string answer = "";
    if (p == "") return answer;
    int index = balanced_string_index(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);
    
    if (check_proper_string(u))
        answer = u + solution(v);
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        int u_size = u.size();
        u = u.substr(1, u_size-2);
        for (int i = 0; i < u_size; i++) {
            if (u[i] == '(') u[i] = ')';
            else if (u[i] == ')') u[i] = '(';
        }
        answer += u;
    }
    
    return answer;
}