#include <iostream>
#include <queue>
#include <string> 
using namespace std; 

//#- 벽, . - 통과가능, j- 초기위치, f - 화재공간

int move_x[4] = {1,-1,0,0}; 
int move_y[4] = {0,0,1,-1}; 
int n, m;
string space[1001]; 

queue<pair<int,int>> Jihon; 
queue<pair<int,int>> Fire; 

int visited_j[1001][1001] = {-1}; 
int visited_f[1001][1001] = {-1}; 

void solve_f(){
    pair<int,int> current = Fire.front(); 
    int x = current.second; 
    int y = current.first; 
    visited_f[y][x] = 0;
    while(!Fire.empty()){
        pair<int,int> current = Fire.front(); 
        int x = current.second; 
        int y = current.first; 

        for(int i = 0;i<4; i++){
            int nx = x+move_x[i]; 
            int ny = y+move_y[i]; 
            if(nx<0||nx>=m||ny<0||ny>=n) continue; 
            if(space[])
            visited_f[ny][nx] = visited_f[y][x]+1; 
        }

    }
}

void solve_j(){

}


int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    cin >> n>> m;

    for(int i = 0;i<n;i++){
        cin >> space[i]; 
        for(int j = 0;j<m;j++){
            if(space[i][j]=='J') Jihon.push({i,j}); 
            if(space[i][j]=='F') Fire.push({i,j}); 
        }
    }

    solve_f();
    solve_j();  
    

    return 0;
}