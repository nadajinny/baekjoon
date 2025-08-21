#include <iostream>
#include <queue> 
using namespace std; 

int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1}; 

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt","r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n;
    int map[101][101];
    int max =0; 
    int max_height = 0;  

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin >> map[i][j]; 
            max_height = max_height>map[i][j] ? max_height: map[i][j]; 
        }
    }

    for(int height = 0;height<max_height; height++) {
        int cnt = 0; 
        bool visited[101][101]; 

        for(int i = 0;i<n;i++ ){for(int j = 0;j<n;j++) visited[i][j]=false; }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++) {
                queue<pair<int,int>> section; 
                if(map[i][j]<=height) { visited[i][j] = true; continue; }
                if(visited[i][j]) continue; 
                section.push({i,j}); 
                visited[i][j] = 1; 
                cnt ++ ; 
                while(!section.empty()) {
                    int x = section.front().first; 
                    int y = section.front().second; 

                    section.pop(); 
                    for(int dir = 0;dir<4; dir++) {
                        int move_x = x+ dx[dir]; 
                        int move_y = y+ dy[dir]; 

                        if(move_x<0||move_x>=n||move_y<0||move_y>=n) continue; 
                        if(visited[move_x][move_y]) continue; 
                        if(map[move_x][move_y]<=height) continue; 

                        visited[move_x][move_y] = 1; 
                        section.push({move_x, move_y}); 
                    }
                }

            }
        }

        max = max>cnt ? max: cnt; 
    }

    cout << max; 

    return 0;
}
