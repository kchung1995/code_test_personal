#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_N 501

int t;
int indegree[MAX_N];
bool graph[MAX_N][MAX_N];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        indegree[i] = 0;
    }
    for (int i = 0; i < MAX_N; i++) {
        fill(graph[i], graph[i] + MAX_N, false);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int round = 0; round < t; round++) {
        init();
        int n, m;
        cin >> n;
        //n개의 정수 ti를 포함하고 있는 한 줄
        vector <int> ranks;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            ranks.push_back(temp);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                graph[ranks[i]][ranks[j]] = true;
                indegree[ranks[j]]++;
            }
        }
        
        
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (graph[a][b]) {
                graph[a][b] = false;
                graph[b][a] = true;
                indegree[a]++;
                indegree[b]--;
            }
            else {
                graph[a][b] = true;
                graph[b][a] = false;
                indegree[a]--;
                indegree[b]++;
            }
        }
        
        //topology sort starts
        vector<int> result;
        queue<int> q;
        
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        //topology sort
        bool cycle = false, certain = true;
        for (int i = 0; i < n; i++) {
            if (q.empty()) {
                cycle = true;
                break;
            }
            if (q.size() >= 2) {
                certain = false;
                break;
            }
            
            int now = q.front();
            q.pop();
            result.push_back(now);
            
            for (int j = 1; j <= n; j++) {
                if (graph[now][j]) {
                    indegree[j]--;
                    if (indegree[j] == 0)
                        q.push(j);
                }
            }
        }
        
        if (cycle) cout << "IMPOSSIBLE\n";
        else if (!certain) cout << "?\n";
        else {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
