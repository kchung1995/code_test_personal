#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_N 100001

int v, e;
int indegree[MAX_N] = {0, };
vector <int> graph[MAX_N];

void topology_sort() {
    vector<int> result;
    queue<int> q;
    
    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        result.push_back(now);
        
        for (int i = 0; i < graph[now].size(); i++) {
            indegree[graph[now][i]]--;
            if (indegree[graph[now][i]] == 0)
                q.push(graph[now][i]);
        }
    }
    
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    topology_sort();
    
    return 0;
}
