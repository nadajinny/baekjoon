#include <iostream>
using namespace std; 

bool visited[100001]; 
int input[100001]; 
bool finished[100001];
int cnt = 0; 
void dfs(int x) {
    visited[x] = true; 
    int nxt = input[x]; 
    if(!visited[nxt]) dfs(nxt); 
    else if(!finished[nxt]) {
        int cur = nxt; 
        int cur_cnt = 1; 
        while(input[cur]!=nxt) {
            cur = input[cur]; 
            cur_cnt++; 
        }
        cnt += cur_cnt; 
    }

    finished[x] = true; 
}

int main(void)  {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;

    cin >> n;

    for(int i = 0;i<n;i++ ) {
        int len; 
        cin >> len; 
        for(int j = 0;j<len;j++) {
            cin >> input[j+1] ;
            visited[j+1] = false; 
            finished[j+1] = false; 
        }
        cnt = 0; 
        for(int j = 0;j<len;j++) {
            if(!visited[j+1]) dfs(j+1); 
        }

        cout << len - cnt <<'\n'; 
    }

    return 0;
}
