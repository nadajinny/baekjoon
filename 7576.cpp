#include <iostream>
#include <queue> 
using namespace std; 

int n,m;  //n = x, m = y
int move_x[4] = {1,-1,0,0}; 
int move_y[4] = {0,0,1,-1}; 
//first = x , second = y ; y, x
int tomato[1001][1001]; 
int start_x, start_y; 
int flag = true; 
queue<pair<int,int>> Q;
bool visited[1001][1001] ={false};  

void input(){
    
    for(int i = 0;i<m;i++){
        for (int j =0;j<n; j++){
            cin >> tomato[i][j]; 
            if(tomato[i][j]==1) {Q.push({j,i}); visited[i][j] = true; }
            if(tomato[i][j]==0) {flag = false; }
        }
    }
}

void solve(){
    while(!Q.empty()){
        pair<int,int> current = Q.front(); Q.pop(); 
        int y = current.second; 
        int x = current.first; 
        for(int i = 0;i<4; i++){
            int nx = x+move_x[i]; 
            int ny = y+move_y[i]; 
            if(nx<0||nx>=n||ny<0||ny>=m) continue; 
            if(tomato[ny][nx]==-1||visited[ny][nx]) continue; 
            tomato[ny][nx] = tomato[y][x] + 1; 
            Q.push({nx, ny}); 
            visited[ny][nx] = true; 
        }
    }
    int result = 0;

    for(int i = 0;i<m;i++){
        for (int j =0;j<n; j++){
            if(tomato[i][j] == 0 && !visited[i][j]) {cout << -1 ; return; }
            result = result>tomato[i][j]?result:tomato[i][j]; 
        }
    }

    cout << result-1; 
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    cin >> n>> m;
    input(); 
    if(flag==true) {cout << 0; return 0;}
    solve(); 


    return 0;
}