#include <iostream>
#include <queue> 
using namespace std; 

int n,m;
int map[1001][1001]; 
int start_x, start_y; 
int result[1001][1001];
bool visited[1001][1001]; 

void search(){
    int dir_x[4] = {1, -1,0,0}; 
    int dir_y[4] = {0,0,1,-1}; 

    queue<pair<int,int>> Q;

    Q.push({start_x, start_y}); 
    result[start_x][start_y] = 0; 

    while(!Q.empty()){
        pair<int,int> current = Q.front(); Q.pop(); 
        int cur_x = current.first; 
        int cur_y = current.second; 

        for(int i = 0;i<4; i++){
            int move_x = cur_x+dir_x[i]; 
            int move_y = cur_y+dir_y[i]; 
            if(move_x>=n||move_x<0) continue;
            if(move_y>=m||move_y<0) continue; 
            if(!map[move_x][move_y]) {
                result[move_x][move_y] = 0; 
                continue; 
            }
            if(!visited[move_x][move_y]&&result[move_x][move_y]!=-1){
                //그전 값과의 비교문 필요 
                if(result[move_x][move_y]<=result[cur_x][cur_y]+1) continue; 
                result[move_x][move_y] = result[cur_x][cur_y]+1; 
            }else {
                result[move_x][move_y] = result[cur_x][cur_y]+1; 
            }
            Q.push({move_x, move_y}); 

        }

    }
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(); 

    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) {
            cin >> map[i][j]; 
            result[i][j] = -1 ;
            if(map[i][j]==2) {    start_x = i; start_y=j;    }
        }
    }

    search(); 

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(result[i][j]==-1&&map[i][j]==0) result[i][j] =0; 
            cout << result[i][j]<<' '; 
        }
        cout <<'\n'; 
    }

    return 0;
}