#include <iostream>
#include <queue> 
using namespace std; 

int n,m;
bool maze[101][101]= {false}; 
bool visited[101][101] = {false}; 
int nx[4] ={1,-1,0,0}; 
int ny[4] = {0,0,1,-1}; 

void input(){
    string sample ; 
    for(int i = 0; i<n;i++){
        cin >> sample; 
        for(int j = 0;j<m;j++){
            maze[i][j] = sample[j]=='1'; 
        }
    }
}

void findmaze(){
    queue<pair<int,int>> Q; 
    int dist[101][101] = {0}; 
    Q.push({0,0}); 
    int result =0; 
    dist[0][0] = 1; 
    while(!Q.empty()){
        pair<int,int> current = Q.front(); Q.pop(); 
        //가능할 경우에만 queue에 넣자
        result++; 
        for(int i = 0;i<4; i++){
            int x_step = current.second + nx[i]; 
            int y_step = current.first + ny[i];  
            if(y_step <0||y_step>=n||x_step <0||x_step>=m) continue; 
            if(visited[y_step][x_step]||!maze[y_step][x_step]) continue; 
            dist[y_step][x_step] = dist[current.first][current.second] + 1;
            visited[y_step][x_step] = true;
            Q.push({y_step, x_step}); 
        }
    }
    cout << dist[n-1][m-1]; 
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    cin >> n>> m;
    
    input(); 

    findmaze(); 

    return 0;
}