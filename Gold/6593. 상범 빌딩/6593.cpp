#include <iostream>
#include <queue> 

using namespace std; 

int dx[6] = {1,-1,0,0,0,0}; 
int dy[6] = {0,0,1,-1,0,0}; 
int dz[6] = {0,0,0,0,1,-1}; 

int main(void)  {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt","r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    while(1) {
        int L,R,C; 
        char map[31][31][31]; 
        bool visited[31][31][31];   
        int time =-1; 

        cin >> L >> R >> C; 
        if(L==0&&R==0&&C==0) break; 

        queue<pair<int,pair<int,int>>> pos; 
        pair<int,pair<int,int>> exit; 

        for(int k = 0;k<L; k++) {
            for(int j = 0;j<R; j++ ) {
                for(int i = 0; i<C; i++) {
                    cin >> map[i][j][k]; 
                    visited[i][j][k] = 0;
                    if(map[i][j][k]=='S') { pos.push({i, {j, k}}); visited[i][j][k] = 1; }
                    if(map[i][j][k]=='E') exit = {i,{j,k}}; 
                }
            }
        }

        
        bool flag = 0; 
        while(!pos.empty()) {
            int sz = pos.size(); 
            time++; 
                
            for(int i = 0;i<sz; i++) {
                int x = pos.front().first; 
                int y = pos.front().second.first; 
                int z = pos.front().second.second; 
                pos.pop(); 

                if(x == exit.first&&y==exit.second.first&&z == exit.second.second) {flag = 1; break;}

                for(int dir = 0;dir <6; dir++) {
                    int move_x = x+ dx[dir]; 
                    int move_y = y+ dy[dir]; 
                    int move_z = z+ dz[dir]; 

                    if(move_x<0||move_y<0||move_z<0||move_x>=C||move_y>=R||move_z>=L) continue; 
                    if(map[move_x][move_y][move_z] == '#') continue; 
                    if(visited[move_x][move_y][move_z]) continue; 

                    pos.push({move_x, {move_y, move_z}}); 
                    visited[move_x][move_y][move_z] = 1; 
                }
            }
            
            if(flag) break;
        }

        if(flag) cout << "Escaped in " << time<<" minute(s).\n"; 
        else cout << "Trapped!\n"; 

    }

    return 0;
}
