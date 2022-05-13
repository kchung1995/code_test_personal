// https://programmers.co.kr/learn/courses/30/lessons/62048
#include <algorithm>
using namespace std;

int gcd (int a, int b) {
    if (a < b) swap(a, b);
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    long long mini_w, mini_h;
    long long divisor = gcd(w, h);
    mini_w = w / divisor;
    mini_h = h / divisor;  
    
    return answer - ((mini_w + mini_h - 1) * (w / mini_w));
}
