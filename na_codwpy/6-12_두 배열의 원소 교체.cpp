#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> containerA;
vector<int> containerB;
int N, K;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        containerA.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        containerB.push_back(temp);
    }
    
    sort(containerA.begin(),containerA.end());
    sort(containerB.begin(),containerB.end(), greater<int>() );
    
    for (int i = 0; i < K; i++) {
        int temp;
        temp = containerA[i];
        containerA[i] = containerB[i];
        containerB[i] = temp;
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += containerA[i];
    }
    
    cout << sum;
    
    return 0;
}
