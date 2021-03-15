#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 200000

int total_cost = 0, built_cost = 0;
int n, m;
vector<pair <int, pair<int, int> > > roads;                    //cost, b, [a]
int parent[MAX_N];

int get_parent(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = get_parent(parent[x]);
}

void make_union(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        roads.push_back(make_pair(c, make_pair(a, b)));
        total_cost += c;
    }
    
    sort(roads.begin(), roads.end());
    
    for (int i = 0; i < m; i++) {
        int cost = roads[i].first;
        int a = roads[i].second.first;
        int b = roads[i].second.second;
        
        a = get_parent(a);
        b = get_parent(b);
        
        if (a != b) {
            make_union(a, b);
            built_cost += cost;
        }
    }
    
    cout << total_cost - built_cost;
    return 0;
}

/*
 7 11
 0 1 7
 0 3 5
 1 2 8
 1 3 9
 1 4 7
 2 4 5
 3 4 15
 3 5 6
 4 5 8
 4 6 9
 5 6 11
 */
