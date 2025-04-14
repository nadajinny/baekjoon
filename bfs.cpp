#include <iostream>
#include <queue> 
using namespace std; 

#define X first
#define Y second

int board[101][101] = {...}; 
bool visited[502][502]; 
int n = 7, m = 10; 

int dx[4] = {1, 0 , -1, 0}; 
int dy[4] = {0,1,0,-1}; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    queue<pair<int, int>> Q;  
    visited[0][0] = true; 
    Q.push({0,0}); 

    while(!Q.empty()){
        pair<int,int> current = Q.front(); 
        Q.pop(); 
        for(int dir = 0; dir< 4; dir++){
            int nx = cur.x + dx[dir]; 
            int ny = cur.y + dy[dir]; 
            if(nx < 0 ||nx >=n||ny< 0 ||ny>=m) continue; 
            if(visited[nx][ny]||board[nx][ny]!=true) continue; 
            visited[nx][ny] = 1; 
            Q.push({nx,ny }); 
        }
    }
}