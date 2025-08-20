#include <iostream>
#include <queue>
using namespace std; 

int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1}; 

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt","r",stdin); 
    freopen("./output.txt","w",stdout); 
    #endif

    int n, m;   
    char map[1001][1001]; 
    int days = 0; 
    queue<pair<int,int>> jihoon; 
    queue<pair<int,int>> fire; 
    int visited[1001][1001]; 
    cin >> n >> m;
    
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin >> map[j][i]; 
            if(map[j][i]=='J') jihoon.push({j, i});
            if(map[j][i]=='F') fire.push({j,i}); 
            visited[j][i] = 0; 
        }  
    }

    bool flag = 0; 

    while(!jihoon.empty()) {

        int sz = fire.size(); 
        days++;

       for(int i = 0;i<sz;i++) {
            int x = fire.front().first; 
            int y = fire.front().second;
            fire.pop(); 

            for(int j = 0;j<4; j++) {
                int move_x = x + dx[j]; 
                int move_y = y + dy[j]; 

                if(map[move_x][move_y]=='#'||map[move_x][move_y]=='F') continue; 
                if(move_x<0||move_x>=m||move_y<0||move_y>=n) { continue; }

                fire.push({move_x, move_y}); 
                map[move_x][move_y] = 'F'; 
            }
        }

        sz = jihoon.size(); 
        
        for(int i = 0;i<sz;i++) {
            int x = jihoon.front().first; 
            int y = jihoon.front().second;
            jihoon.pop(); 

            for(int j = 0;j<4; j++) {
                int move_x = x + dx[j]; 
                int move_y = y + dy[j]; 

                if(map[move_x][move_y]=='#'||map[move_x][move_y]=='F') continue; 
                if(move_x<0||move_x>=m||move_y<0||move_y>=n) { flag=1; continue; }
                if(visited[move_x][move_y]) continue; 

                jihoon.push({move_x, move_y}); 
                visited[move_x][move_y] = 1; 
            }
        }
        
        if(flag) break; 
    }

    if(flag) cout << days; 
    else cout << "IMPOSSIBLE"; 

    return 0;
}
