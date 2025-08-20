#include <iostream>
#include <queue> 
#include <stack> 
using namespace std; 

int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1}; 

int main(void)  {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt","w", stdout); 
    #endif

    int map[101][101]; 
    int m, n, k;
    int cnt = 0; 
    cin >> m >> n >> k; 

    for(int i = 0; i<101; i++) {
        for(int j = 0;j<101; j++) map[i][j]=0;
    }

    for(int i = 0; i<k;i++) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2; 
        for(int i = y1; i<y2; i++){
            for(int j = x1; j<x2; j++) {
                map[j][i] = 1; 
            }
        }
    }
    priority_queue<int> sz; 

    for(int k = 0;k<n;k++){
        for(int l = 0; l<m;l++) {
            if(map[k][l]) continue; 

            queue<pair<int,int>> blank;
            blank.push({k,l}); 
            map[k][l] = 1 ;
            cnt ++ ; 
            int box_size = 0; 

            while(!blank.empty()) {
                int x = blank.front().first; 
                int y = blank.front().second; 
                box_size++; 
                blank.pop(); 

                for(int i = 0;i<4; i++) {
                    int move_x = x+ dx[i]; 
                    int move_y = y + dy[i]; 

                    if(move_x<0||move_x>=n||move_y<0||move_y>=m) continue; 
                    if(map[move_x][move_y]) continue; 

                    map[move_x][move_y] = 1; 
                    blank.push({move_x, move_y}); 
                }
            }
            sz.push(box_size); 
        }
    }

    cout << cnt<<'\n';
    stack<int> result; 
    while(!sz.empty()) {
        result.push(sz.top()); 
        sz.pop(); 
    }

    while(!result.empty()) {
        cout << result.top() <<" "; 
        result.pop(); 
    }

    return 0;
}
