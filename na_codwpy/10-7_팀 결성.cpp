#include <iostream>
using namespace std;
#define MAX_N 100001

int N, M;
int parent[MAX_N];

int find_parent (int x) {
    if (x == parent[x]) return x;
    else return find_parent(parent[x]);
}

void make_union(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0)
            make_union(a, b);
        else if (t == 1) {
            if (find_parent(a) == find_parent(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
