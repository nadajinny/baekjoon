#include <iostream>
#include <queue>

using namespace std; 

int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1}; 

int map[1001][1001]; 
int visited[2][1001][1001]; 

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt","r", stdin); 
    freopen("./output.txt","w",stdout); 
    #endif

    int n, m;
    cin >> n >> m;

    for(int i = 0;i<n;i++) {
        string s; 
        cin >> s; 
        if (s.size() != m) {
        return 1;
        }
        for(int j =0; j<m;j++) {
            map[i][j] = s[j]-'0'; 
            visited[0][i][j] = 0; 
            visited[1][i][j] = 0;
        }
    }

    queue<pair<int,pair<int,int>>> path; 

    path.push({1,{0,0}}); 
    int cnt =0; 
    int flag = 0; 
    visited[1][0][0] = 1;  //[남은 스킬 횟수][x][y]

    while(!path.empty()) {
        int sz = path.size(); 
        cnt ++ ; 

        for(int i = 0; i<sz; i++) {
            int skill = path.front().first; 
            int x = path.front().second.first; 
            int y = path.front().second.second; 
            path.pop();

            if(x == n-1 && y==m-1)  {flag = 1; break; }

            for(int dir = 0; dir<4; dir++) {
                int move_x = x+ dx[dir]; 
                int move_y = y+ dy[dir]; 

                if(move_x<0||move_y<0||move_x>=n||move_y>=m) continue; 
                if(visited[0][move_x][move_y] && visited[1][move_x][move_y]) continue; 

                if(map[move_x][move_y]) { //벽이 있을 경우, visited[0][move_x][move_y]가 있는지 확인 -> skill이 있는지 확인
                    if(visited[0][move_x][move_y]) continue; 
                    if(skill) {
                        visited[0][move_x][move_y] = 1; 
                        path.push({0,{move_x, move_y}}); 
                    }
                }
                else { //벽이 없을 경우, visited[skill][move_x][move_y]를 확인하고, 
                    if(visited[skill][move_x][move_y]) continue;
                    visited[skill][move_x][move_y] = 1; 
                    path.push({skill, {move_x, move_y}}); 
                }

            } 

        }
        if(flag) break; 

    }

    if(flag) cout << cnt; 
    else cout << -1;  

    return 0; 
}
