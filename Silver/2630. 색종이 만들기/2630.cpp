#include <iostream>
using namespace std; 

bool paper[129][129]; 
int white = 0; 
int blue = 0; 

void dfs(int n, int x, int y ){
    int fullcolor = 1;
    int cur_color = paper[x][y];
    for(int i = x;i<x+n;i++){
        for(int j = y;j<y+n;j++){
            if(cur_color!=paper[i][j]) {
                dfs(n/2, x, y); 
                dfs(n/2, x+n/2, y); 
                dfs(n/2, x, y+n/2); 
                dfs(n/2, x+n/2,y+n/2);
                return ; 
            }
        }
    }
    if(fullcolor) {
        if(cur_color) {blue++;}
        else {white++;}
    }
}

int input(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> paper[i][j]; 
        }
    }
    return n;
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(); 

    int n  = input(); 

    dfs(n, 0,0); 

    cout << white <<'\n' << blue; 

    return 0;
}