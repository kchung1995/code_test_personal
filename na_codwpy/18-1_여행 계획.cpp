#include <iostream>
using namespace std;
#define MAX_N 501

int n, m;

int parent[MAX_N];
int plan[MAX_N];
int matrix[MAX_N][MAX_N];

int find_parent(int x) {
    if (parent[x] == x) return x;
    else return find_parent(parent[x]);
}

void make_union(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x < y)
        parent[y] = x;
    else parent[x] = y;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] == 1) {
                make_union(i, j);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> plan[i];
    }
    
    int par = parent[plan[0]];
    bool available = true;
    
    for (int i = 1; i < m; i++) {
        if (parent[plan[i]] != par)
            available = false;
    }
    
    if (available) cout << "YES";
    else cout << "NO";
    
    return 0;
}
