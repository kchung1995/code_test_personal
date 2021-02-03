#include <iostream>
#include <algorithm>
using namespace std;

int numbers[500];
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    
    for (int i = 0; i < N; i++) {
        int maximum = numbers[i];
        int max_index = -1;
        for (int j = i+1; j < N; j++) {
            if (numbers[j] > maximum) {
                maximum = numbers[j];
                max_index = j;
            }
        }
        if (max_index != -1) {
            int temp;
            temp = numbers[i];
            numbers[i] = numbers[max_index];
            numbers[max_index] = temp;
        }
    }
    
    for (int i = 0; i < N; i++)
        cout << numbers[i] << " ";
    return 0;
}
