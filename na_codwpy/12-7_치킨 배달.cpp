#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 51

int n, m;
int house_size, chicken_size;
vector<pair <int, int> > chicken;
vector<pair <int, int> > house;
int chicken_distance = 1e9;

int get_distance (vector <pair <int, int> > input) {
    int current_dist = 0;
    int input_size = input.size();
    
    for (int i = 0; i < house_size; i++) {
        int hx = house[i].first;
        int hy = house[i].second;
        
        int temp = 1e9;
        for (int j = 0; j < input_size; j++) {
            int cx = input[j].first;
            int cy = input[j].second;
            temp = min(temp, abs(hx-cx) + abs(hy-cy));
        }
        current_dist += temp;
    }
    return current_dist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int temp;
            cin >> temp;
            if (temp == 2)
                chicken.push_back(make_pair(i, j));
            else if (temp == 1)
                house.push_back(make_pair(i, j));
        }
    }
    house_size = house.size();
    chicken_size = chicken.size();
    
    vector<bool> binary(chicken.size());
    fill (binary.end() - m, binary.end(), true);
    
    do {
        vector <pair <int, int> > now;
        for (int i = 0; i < chicken_size; i++) {
            if (binary[i]) {
                int cx = chicken[i].first;
                int cy = chicken[i].second;
                now.push_back(make_pair(cx, cy));
            }
        }
        chicken_distance = min (chicken_distance, get_distance(now));
    } while (next_permutation(binary.begin(), binary.end()));
    
    cout << chicken_distance;
    return 0;
    
}
