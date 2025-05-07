//bbarkingdog - BFS

#include <iostream>
#include <string> 
#include <queue> 
using namespace std; 


int n;
string a[101];


void solve(){
    int dir_x[4] = {1,-1,0,0}; 
    int dir_y[4] = {0,0,1,-1}; 

    bool visited[101][101] = {false}; 
    bool visited_2[101][101] = {false}; 

    int cnt = 0;
    int cnt_2 = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(visited[i][j] == false) {
                queue<pair<int,int>> Q; 
                Q.push({i, j}); 
                visited[i][j] = true; 
                while(!Q.empty()){
                    pair<int,int> current = Q.front(); Q.pop(); 
    
                    for(int dir = 0;dir<4; dir++){
                        int next_x = current.first + dir_x[dir]; 
                        int next_y = current.second + dir_y[dir]; 
    
                        if(next_x<0||next_x>=n||next_y<0||next_y>=n) continue; 
                        if(visited[next_x][next_y]) continue; 
                        if(a[next_x][next_y]!=a[current.first][current.second]) continue; 
    
                        Q.push({next_x, next_y}); 
    
                        visited[next_x][next_y] = true;
                    }
                }
                cnt ++; 
    
            }
           if(visited_2[i][j]== false){
                queue<pair<int,int>> Q; 
                Q.push({i, j}); 
                visited_2[i][j] = true; 
                while(!Q.empty()){
                    pair<int,int> current = Q.front(); Q.pop(); 

                    for(int dir = 0;dir<4; dir++){
                        int next_x = current.first + dir_x[dir]; 
                        int next_y = current.second + dir_y[dir]; 

                        if(next_x<0||next_x>=n||next_y<0||next_y>=n) continue; 
                        if (visited_2[next_x][next_y]) continue; 
                        if(a[current.first][current.second]!='B'){
                            if(a[next_x][next_y]!='B'){
                                Q.push({next_x, next_y}); 
                                visited_2[next_x][next_y] = true; 
                                continue; 
                            }
                        }
                        else {
                            if(a[next_x][next_y]==a[current.first][current.second]) {
                                
                                Q.push({next_x, next_y}); 
                                visited_2[next_x][next_y] = true;
                            }
                        }

                    }
                }
                cnt_2 ++; 

           }


        }
    }
    cout << cnt <<" "<< cnt_2; 
}

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
 
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i]; 
    }


    solve(); 

    return 0;
}