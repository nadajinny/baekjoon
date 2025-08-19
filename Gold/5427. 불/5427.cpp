#include <iostream>
#include <queue> 
using namespace std; 

int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1}; 

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n;

    for(int cnt = 0;cnt<n;cnt++) {
        char map[1001][1001]; 
        int visited[1001][1001]; 
        int w, h; 
        int sec=0; 
        queue<pair<int,int>> queue_me; 
        queue<pair<int,int>> queue_fire; 

        //input
        cin >> w >> h;
        for(int i = 0; i<h; i++) {
            for(int j = 0; j<w; j++) {
                cin >> map[j][i]; 
                visited[j][i]=0;
                if(map[j][i]=='@') {queue_me.push({j,i});  visited[j][i]=1; }
                if(map[j][i]=='*') {queue_fire.push({j,i}); } 
            }
        }

        //calculation
        int flag = 0; 
        while(!queue_me.empty()) {
            sec++; 

            //fire move
            int sz = queue_fire.size(); 
            for(int i = 0;i<sz; i++) {
                int x = queue_fire.front().first; 
                int y = queue_fire.front().second; 
                queue_fire.pop(); 

                for(int j = 0; j<4; j++) {
                    int nxt_x = x+ dx[j]; 
                    int nxt_y = y+dy[j]; 
                    if(nxt_x<0||nxt_x>=w||nxt_y<0||nxt_y>=h) continue; 
                    if(map[nxt_x][nxt_y]=='#'||map[nxt_x][nxt_y]=='*') continue; 

                    queue_fire.push({nxt_x,nxt_y}); 
                    map[nxt_x][nxt_y] = '*'; 
                }
            }
            
            sz = queue_me.size(); 
            for(int i = 0;i<sz; i++) {
                int x = queue_me.front().first; 
                int y = queue_me.front().second; 
                queue_me.pop(); 

                for(int j = 0;j<4; j++) {
                    int nxt_x = x+ dx[j]; 
                    int nxt_y = y + dy[j]; 

                    if(nxt_x<0||nxt_x>=w||nxt_y<0||nxt_y>=h) {flag = 1; break;}
                    if(visited[nxt_x][nxt_y]) continue; 
                    if(map[nxt_x][nxt_y]=='#'||map[nxt_x][nxt_y]=='*'||map[nxt_x][nxt_y]=='@') continue;
                    queue_me.push({nxt_x, nxt_y}); 
                    visited[nxt_x][nxt_y] =1; 
                }

                if(flag == 1) break;
            }

            if(flag == 1) break;

        }

        //output
        if(flag == 1) cout << sec <<'\n';   
        else cout << "IMPOSSIBLE" <<'\n';
    }


    return 0;
}
