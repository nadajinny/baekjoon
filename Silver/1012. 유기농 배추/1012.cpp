#include <iostream>
#include <queue>
using namespace std; 

int dx[4] = {1, -1, 0 , 0}; 
int dy[4] = {0,0,1, -1};

void execute() {
    int X, Y, n; 

    bool board[50][50] ={false}; 
    bool visited[50][50] = {false}; 
    int total = 0; 
    cin >> X >> Y >> n;

    for(int i = 0;i<n;i++) {
        int x, y; 
        cin >> x >> y; 
        board[x][y] = true; 
    }

    for(int i = 0;i<X; i++) {
        for(int j = 0;j<Y; j++) {
            queue<pair<int,int>> Q; 
            if(visited[i][j]) continue; 
            if(!board[i][j]) continue; 
            visited[i][j] = true; 
            Q.push({i,j}); 

            while(!Q.empty()) {
                int x = Q.front().first; 
                int y = Q.front().second; 
                Q.pop(); 

                for(int k = 0;k<4; k++) {
                    int nx = x+dx[k]; 
                    int ny = y+dy[k]; 
                    if(nx >= X || nx < 0) continue; 
                    if(ny >= Y || ny < 0) continue; 
                    if(visited[nx][ny]) continue; 
                    if(!board[nx][ny]) continue; 

                    Q.push({nx, ny}); 
                    visited[nx][ny] = true; 
                }
            }
            total ++; 
        }
    }

    cout << total <<'\n'; 
}


int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n;

    for(int i = 0;i<n;i++ ) execute(); 

    return 0;
}
