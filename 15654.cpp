#include <iostream>
#include <vector> 
#include <algorithm>
#include <queue> 
using namespace std; 

int n, m;
vector<int> a; 
bool visited[10]; 
int output[10]; 

void dfs(int x, int y){
    if(y == m){
        for(int i = 0;i<m;i++){
            cout << output[i]<<' '; 
        }
        cout << '\n'; 
    }else {
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                visited[i]= true; 
                output[y] = a[i]; 
                dfs(i+1, y+1); 
                visited[i] = false; 
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin >> n>> m;
    int input; 
    for(int i = 0;i<n;i++){
        cin >> input; 
        a.push_back(input); 
    }

    sort(a.begin(), a.end()); 


    dfs(1,0); 

    return 0;
}