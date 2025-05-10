#include <iostream>
#include <queue> 
using namespace std; 

void solve(int n){
    queue<pair<int,int>> Q; 
    Q.push({0,n}); 
    bool visited[50000] = {false}; 
    while(!Q.empty()) {
        pair<int,int> current = Q.front(); Q.pop(); 
        int cur_n = current.second; 
        int cur_cnt = current.first;  
        //0이 되어야지만 나갈 수 있음
        if(cur_n == 0) {cout << cur_cnt; return; }
        
        for(int i = 1; i*i<=cur_n; i++){
            if(visited[cur_n-i*i]) continue; 
            Q.push({cur_cnt+1, cur_n-i*i}); 
            visited[cur_n-i*i]=true; }
    }
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(); 

    int n;
    cin >> n;
    if(n==0) {cout << 0; return 0;}
    if(n==1) {cout << 1; return 0;}
    solve(n); 

    return 0;
}