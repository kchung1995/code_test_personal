#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001
#define MAX_M 1000000

int N, M;
int parent[MAX_N];
vector <pair <int, pair<int, int> > > homes;
int total_cost = 0;

int find_parent (int x) {
    if (x != parent[x])
        parent[x] = find_parent(parent[x]);
    return parent[x];
}

void make_union(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
        parent[i] = i;
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        homes.push_back(make_pair(c, make_pair(a, b)));
    }
    
    sort(homes.begin(), homes.end());
    
    int max_cost = 0;
    for (int i = 0; i < M; i++) {
        int cost = homes[i].first;
        int home_a = homes[i].second.first;
        int home_b = homes[i].second.second;
        
        if (find_parent(home_a) != find_parent(home_b)) {
            make_union(home_a, home_b);
            total_cost += cost;
            max_cost = max (max_cost, cost);
        }
    }

    cout << total_cost - max_cost;
    
    return 0;
}
