#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> numbers;
int add, sub, mul, divs;
int maximum = -1e9, minimum = 1e9;

void dfs (int i, int now) {
    if (i == n) {
        maximum = max(maximum, now);
        minimum = min(minimum, now);
    }
    else {
        if (add > 0) {
            add--;
            dfs(i+1, now + numbers[i]);
            add++;
        }
        if (sub > 0) {
            sub--;
            dfs(i+1, now - numbers[i]);
            sub++;
        }
        if (mul > 0) {
            mul--;
            dfs(i+1, now * numbers[i]);
            mul++;
        }
        if (divs > 0) {
            divs--;
            dfs(i+1, now / numbers[i]);
            divs++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    cin >> add >> sub >> mul >> divs;
    
    dfs(1, numbers[0]);
    
    cout << maximum << '\n' << minimum;
    
    return 0;
}
