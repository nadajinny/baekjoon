#include <iostream>
#include <queue> 
using namespace std; 

int n, m;
int draw[501][501]; 
int max1 =0; 
int cnt =0; 
void input(){
    cin >> n>> m;
    for(int y = 0;y<n;y++){
        for(int x = 0;x<m;x++){
            cin >> draw[y][x];  
        }
    }
}

void solve(){ 
    bool visited[501][501] = {0}; 
    int dx[4] = {1,-1,0,0}; 
    int dy[4] = {0,0,1,-1}; 
    
    for (int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if (draw[i][j]==0||visited[i][j]) continue; 
            cnt ++ ; 
            queue<pair<int,int>> Q;
            Q.push({i,j}); 
            int size = 0;
            visited[i][j] = true; 
            while(!Q.empty()){
                size ++; 
                pair<int,int> current = Q.front(); Q.pop(); 
                for(int dir = 0;dir<4; dir++){
                    int nx = current.first + dx[dir]; 
                    int ny = current.second + dy[dir]; 

                    if(nx <0 ||nx>=n||ny<0||ny>=m) continue; 
                    if(visited[nx][ny]||draw[nx][ny]!=1) continue; 
                    visited[nx][ny] = 1; 
                    Q.push({nx, ny}); 
                }
            }
            max1 = max1>size?max1: size ; 
        }
    }
    cout << cnt << '\n' << max1; 
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    input(); 

    solve(); 
    
    return 0;
}