#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 501

int N;
vector<int> graph[MAX_N];
vector<int> result(MAX_N);
int indegree[MAX_N] = {0, };
int time_taken[MAX_N] = {0, };

void topology_sort() {
    queue<int> q;
    
    for (int i = 1; i <= N; i++)
        result[i] = time_taken[i];
    
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
        
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < graph[now].size(); i++) {
            indegree[graph[now][i]]--;
            result[graph[now][i]] = max(result[graph[now][i]], result[now] + time_taken[graph[now][i]]);
            if (indegree[graph[now][i]] == 0)
                q.push(graph[now][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> time_taken[i];
        while(1) {
            int input;
            cin >> input;
            if (input == -1) break;
            indegree[i]++;
            graph[input].push_back(i);
        }
    }
    
    topology_sort();
    for (int i = 1; i <= N; i++)
        cout << result[i] << '\n';
    
    return 0;
}
