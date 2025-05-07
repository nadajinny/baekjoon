#include <iostream>
#include <queue> 
#include <stack> 
using namespace std; 

int m, n, k;

void solve(){
    int cabbage[50][50]={0}; 
    cin >> m >> n >> k; 
    int a, b; 

    for(int i = 0;i<k; i++){
        cin >> a >> b; 
        cabbage[b][a] =1; //가로 , 세로  
    }

    bool visited[50][50]={0}; 
    int dir_x[4] = {1,-1,0,0}; 
    int dir_y[4] = {0,0,-1,1};

    int tot = 0; 

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            queue<pair<int,int>> Q; 
            if(cabbage[i][j]!=1||visited[i][j]) continue; 
            Q.push({i,j}); 
            visited[i][j] = true; 
            while(!Q.empty()){
                pair<int,int> current = Q.front(); Q.pop(); 
                for(int dir = 0;dir<4; dir++) {
                    int nx = current.first + dir_x[dir]; 
                    int ny = current.second + dir_y[dir]; 

                    if(nx<0||nx>=n ||ny<0||ny>=m) continue; 
                    if(visited[nx][ny]||cabbage[nx][ny]!=1) continue; 
                    visited[nx][ny] = true; 
                    Q.push({nx, ny}); 
                }
            }
            tot ++; 
        }
    }

    cout << tot <<'\n'; 
}

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int t; 
    cin >> t; 

    for(int i =0;i<t; i++){
        solve(); 
    }

    return 0;
}