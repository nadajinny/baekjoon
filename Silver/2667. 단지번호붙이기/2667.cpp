#include <iostream>
#include <queue> 
#include <algorithm>
#include <vector> 
#include <string> 
using namespace std; 

int h_size; 
bool house[26][26]; 
int move_x[4] = {1,-1,0,0}; 
int move_y[4] = {0,0,1,-1}; 
int tot = 0;
vector<int> tot_size; 
void bfs() {
    for(int i = 0;i<h_size;i++){
        for(int j = 0;j<h_size; j++){
            int each_size = 0; 
            if(!house[i][j]) continue; 
            house[i][j] = false; 
            queue<pair<int,int>> Q; 
            tot++; 
            each_size++;
            Q.push({i,j}); 

            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();  
                for(int n = 0;n<4;n++){
                        if(cur.first+move_x[n]>=h_size || cur.first+move_x[n]<0) continue; 
                        if(cur.second+move_y[n]>=h_size || cur.second+move_y[n]<0) continue; 
                        if(!house[cur.first+move_x[n]][cur.second+move_y[n]]) continue; 
                        Q.push({cur.first+move_x[n], cur.second+move_y[n]});
                        each_size++; 
                        house[cur.first+move_x[n]][cur.second+move_y[n]] = false; 
                    
                }
            }
            tot_size.push_back(each_size); 
        }
    }
}


int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(); 

    cin >> h_size; 
    string a; 
    for(int i = 0;i<h_size; i++){
        cin >> a; 
        for(int j = 0;j<h_size; j++){
            house[i][j] = a[j]-'0';
        }
    }

    bfs(); 
    cout << tot<<'\n'; 
    sort(tot_size.begin(), tot_size.end()); 
    for(int i = 0;i<tot; i++) {
        cout << tot_size[i]<<'\n';
    }
    return 0;
}