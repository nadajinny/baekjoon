#include <iostream>
#include <queue> 
using namespace std; 

bool linked[101][101] = {false}; 
int n, m;
bool visited[101] = {false}; 
void bfs(int from){
    queue<int> root; 
    root.push(from); 
    int cnt = 0; 

    while(!root.empty()){
        from = root.front(); 
        root.pop(); 
        for(int i = 2; i<=n; i++){
            if(linked[from][i] && !visited[i]){
                visited[i]= true; 
                cnt++; 
                root.push(i); 
            }
        }
    }
    cout << cnt ; 

    
}

int main(void){
    ios::sync_with_stdio(); 
    cin.tie(); 

    cin >> n >> m;
    int input1, input2; 
    for(int i = 0;i<m;i++){
        cin >> input1>> input2; 
        linked[input1][input2] = true;
        linked[input2][input1] = true;  
    }

    bfs(1); 

    return 0; 

}