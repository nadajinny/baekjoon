#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
using namespace std; 

char table[5][5]; 
int cnt = 0; 
bool isused[5][5]; 
int dx[4] = {0,0,1,-1}; 
int dy[4] = {1,-1,0,0}; 
vector<pair<int,int>> Q; 
set<vector<pair<int,int>>> uniq;


void func(int num, int yeon) { 
    if(yeon > 3) return ;
    if(num==7) {
        vector<pair<int,int>> sortQ = Q;
        sort(sortQ.begin(), sortQ.end());
        uniq.insert(sortQ);
        return ; 
    }
    int sz = Q.size(); 
    for(int i = 0;i<sz; i++){
        int x = Q[i].first; 
        int y = Q[i].second;  
        for(int i = 0;i<4; i++) {
            if(dx[i]+x<0||dx[i]+x>4||dy[i]+y<0||dy[i]+y>4) continue; 
            if(!isused[x+dx[i]][y+dy[i]]) {
                int Y = table[x+dx[i]][y+dy[i]]=='Y'? 1: 0; 
                isused[x+dx[i]][y+dy[i]] =1; 
                Q.push_back({dx[i]+x, dy[i]+y}); 
                func(num+1, yeon+Y); 
                isused[x+dx[i]][y+dy[i]] =0; 
                Q.pop_back(); 
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin); 
    freopen("./output.txt", "w", stdout); 
    #endif

    string s; 
    for(int i = 0;i<5; i++) {
        cin >> s; 
        for(int j = 0;j<5; j++) table[i][j] = s[j]; 
    }

    for(int i = 0;i<5;i++) {
        for(int j = 0;j<5; j++) {
            int Y = table[i][j]=='Y'? 1: 0; 
            Q.push_back({i,j}); 
            isused[i][j] = 1; 
            func(1, Y); 
            isused[i][j] = 0; 
            Q.pop_back(); 
        }
    }
    cout << uniq.size(); 

    return 0;
}
