#include <iostream>
#include <queue> 
using namespace std; 

int dir_x[8] = {-1, 2, -2, 1, 2, 1, -2,-1}; 
int dir_y[8] = {2, -1, 1, -2, 1, 2, -1, -2}; 

int main(void){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    
    int n, line;
    
    cin >> n;

    for(int i = 0;i<n;i++){
        int cnt[301][301] = {0}; 
        bool visited[301][301] = {false}; 
        int line, from_x, from_y, dest_x, dest_y; 
        queue<pair<int,int>> Q; 

        cin >> line;
        cin >> from_x >> from_y >> dest_x >> dest_y; 

        //solve()코드
        Q.push({from_x, from_y}); 
        cnt[from_x][from_y] = 0; 
        visited[from_x][from_y] = true; 


        while(!Q.empty()){
            pair<int,int> current = Q.front(); Q.pop(); 

            if(current.first == dest_x && current.second == dest_y) {
                break;
            }
            for(int i = 0;i<8;i++){
                int nx = current.first + dir_x[i]; 
                int ny = current.second + dir_y[i]; 
                
                if(nx<0||nx>=line||ny<0||ny>=line) continue; 
                if(visited[nx][ny]) continue; 

                Q.push({nx, ny}); 
                visited[nx][ny] = true; 
                cnt[nx][ny] = cnt[current.first][current.second] + 1; 
            }
        }
        cout << cnt[dest_x][dest_y]<<'\n'; 
    }  


    return 0;
}