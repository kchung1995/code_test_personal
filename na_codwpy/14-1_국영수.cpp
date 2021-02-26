#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
    string name;
    int korean;
    int english;
    int math;
    
    Student(string name, int korean, int english, int math) {
        this->name = name;
        this->korean = korean;
        this->english = english;
        this->math = math;
    }
    
    bool operator <(Student &other) {
        if (this->korean == other.korean && this->english == other.english && this->math == other.math)
            return this->name < other.name;
        if (this->korean == other.korean && this->english == other.english)
            return this->math > other.math;
        if (this->korean == other.korean)
            return this->english < other.english;
        return this->korean > other.korean;
    }
};

vector <Student> students;
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        students.push_back(Student(name, kor, eng, math));
    }
    
    sort(students.begin(), students.end());
    
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << '\n';
    }
    return 0;
}
