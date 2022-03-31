// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/12901
#include <string>
#include <vector>

using namespace std;

int days[13] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    string answer = "";
    
    int displacement = 0;
    // 월마다 날 수를 더한다.
    for (int i = 1; i < a; i++) {
        displacement += days[i];
    }
    
    // 날짜 차이를 더한다.
    displacement += (b - 1);
    
    // 7로 나눈 나머지를 구한다.
    displacement %= 7;
    
    return day[displacement];
}
