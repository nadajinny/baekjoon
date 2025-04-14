#include <iostream>
#include <queue> 
using namespace std; 
#define MAX 0x3f3f3f3f

int board[1001][1001]; 
int min_path[1001][1001][2]; 
int n, m;
void input(){
    for (int i = 0;i<n; i++){
        for(int j =0;j<m;j++){
            cin >> board[i][j]; 
        }
    }
}
void bfs(){

    int dx[4] = {1,-1, 0,0}; 
    int dy[4] = {0,0,1,-1}; 
    queue<pair<int, int>> Q; 
    queue<int> flag;    
    min_path[0][0][0] = 0; 
   
    min_path[0][0][1] = 0; 

    Q.push({0,0}); 
    flag.push(1); 

    while(!Q.empty()){
        pair<int,int> current= Q.front(); Q.pop(); 
        int curFlag = flag.front(); flag.pop(); 

        if(current.first == n-1&&current.second == m-1) {
            cout << min_path[current.first][current.second][curFlag]; 
            return ; 
        }
        for(int i = 0;i<4; i++){
            int curX = current.first + dx[i]; 
            int curY = current.second + dy[i]; 
            if(curX<0||curX>=n||curY<0||curY>=m) continue; 
            if(board[curX][curY]!=0&&curFlag == 0) continue; 
            else if(curFlag == 1){
                Q.push({curX, curY}); 
                flag.push(curFlag-1); 
                min_path[curX][curY][curFlag-1] = min_path[curX][curY][curFlag]+1; 
                continue; 
            }
            else if(min_path[curX][curY][curFlag]!=0) continue; 
            Q.push({curX, curY}); 
            flag.push(curFlag); 
            min_path[curX][curY][curFlag] = min_path[curX][curY][curFlag]+1; 
            
        }
    }

    cout << -1 ; 


}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin >> n >> m;

    input(); 


    bfs(); 

    return 0;
}