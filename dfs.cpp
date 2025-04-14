#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

bool visited[1001];
bool visited2[1001];
vector<int> graph[1001];

void dfs(int node){
    visited[node] = true;
    cout << node << ' ';
    for(int i=0; i<graph[node].size(); i++){
        int next = graph[node][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited2[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << ' ';
        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i];
            if(!visited2[next]){
                q.push(next);
                visited2[next] = true;
            }
        }
    }
}

int main(void){
    int n, m, start;
    cin >> n >> m >> start;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(start);
    cout << endl;
    bfs(start);
    return 0;
    
}