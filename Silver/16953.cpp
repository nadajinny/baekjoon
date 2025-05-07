#include <iostream>
#include <queue> 
using namespace std; 

bool visited[1000001]; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    long long from, goal ; 

    cin >> from >> goal; 
    //최단경로 - bfs
    //from -> goal 을 찾는게 아니라 goal->from을 찾는게 나을 듯 
    // /2 때문에 
    
    queue<pair<long long, int>> Q; 
    Q.push({goal, 1}); 
    int result = -1; 
    while(!Q.empty()){
        int target = Q.front().first; 
        int cnt = Q.front().second; 
        Q.pop(); 
        if(target<=1000000&&visited[target-1]== true) continue; 
        if(target == from){
            result = cnt; 
            break;
        }

        if(target%2==0){
            Q.push({target/2 ,cnt+1}); 
        }
        if(target%10 == 1)Q.push({target/10, cnt+1}); 
        if(target<=1000000) visited[target-1] = true; 
    }

    cout << result ; 
    return 0;
}