#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001

int n;
vector <pair <int, pair <int, int> > > distances;
int parent[MAX_N];

int find_parent(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}

void make_union (int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i <= MAX_N; i++) {
        parent[i] = i;
    }
    
    vector <pair <int, int> > xin;
    vector <pair <int, int> > yin;
    vector <pair <int, int> > zin;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        xin.push_back(make_pair(a, i));
        yin.push_back(make_pair(b, i));
        zin.push_back(make_pair(c, i));
    }
    
    sort(xin.begin(), xin.end());
    sort(yin.begin(), yin.end());
    sort(zin.begin(), zin.end());
    
    for (int i = 0; i < n-1; i++) {
        distances.push_back(make_pair(abs(xin[i+1].first - xin[i].first), make_pair(xin[i].second, xin[i+1].second)));
        distances.push_back(make_pair(abs(yin[i+1].first - yin[i].first), make_pair(yin[i].second, yin[i+1].second)));
        distances.push_back(make_pair(abs(zin[i+1].first - zin[i].first), make_pair(zin[i].second, zin[i+1].second)));
    }
    
    sort(distances.begin(), distances.end());
    
    int answer = 0;
    for (int i = 0; i < distances.size(); i++) {
        int cost = distances[i].first;
        int a = distances[i].second.first;
        int b = distances[i].second.second;
        
        a = find_parent(a);
        b = find_parent(b);
        if (a != b) {
            make_union(a, b);
            answer += cost;
        }
    }
    cout << answer;
    return 0;
}
