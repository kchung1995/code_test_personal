#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100001

int g, p;
int parent[MAX_N];
vector<int> planes;

int get_parent(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = get_parent(parent[x]);
}

void make_union (int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g >> p;
    
    for (int i = 0; i <= g; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < p; i++) {
        int temp;
        cin >> temp;
        planes.push_back(temp);
    }
    
    int result = 0;
    for (int i = 0; i < p; i++) {
        int temp = planes[i];
        int root = get_parent(temp);
        if (root == 0) break;
        make_union(root, root-1);
        result++;
    }
    
    cout << result;
    return 0;
}
