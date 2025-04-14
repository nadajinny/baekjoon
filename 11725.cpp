#include <iostream> 
#include <queue> 
#include <vector>
using namespace std; 

vector<int> tree[100001]; 
int result[100001]; 
bool visited[100001]; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b; 
        cin >> a >> b;
        tree[a].push_back(b); 
        tree[b].push_back(a); 
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : tree[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                result[next] = cur; // 부모 설정
                q.push(next);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
